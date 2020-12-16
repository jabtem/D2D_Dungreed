#include "Include.h"

Town town;

Town::Town()
{

	SetPos(g1,65, 505, 576, 575);
	SetPos(g2,128, 385, 448, 448);
	SetPos(p1, 328, 320, 496, 364);
	SetRect(&Town_World, 0, 0, 7300, 1300);
	floorX = 0;
	treeX = 0;
	skyY = 0;
	groundX = 0;
	gX = 0;
	gMoveCnt = 0;
	next_dungeonEat = 0;
	isTownBGMON = false;
	doorOpen = false;
	doorAni = false;

}

Town::~Town()
{
}

void Town::Init()
{
	int i,j;
	char FileName[256];
	
	sprintf_s(FileName, "./resources/images/Map/Town_BGL.png");
	TownBG_Sky.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Map/TownBG_Day.png");
	TownBG_Mountain.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Map/TownLayer_Day.png");
	TownBG_Tree.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Map/TownFloor.png");
	Town_Floor.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Map/townAtlas1.png");
	TownAtlas.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	
	sprintf_s(FileName, "./resources/images/Villiage/DungeonEat.png");
	DungeonEat.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Town::Update(double frame)
{
	if (!isTownBGMON)
	{
		int TBGM = sound.Get_BGM(TOWNBGM);//BGM파일불러옴
		sound.BGMChange(TBGM);
		isTownBGMON = true;
	}

	//camera.CamCheck(Town_World, camera.Get_CameraRect());
	camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), Town_World);

	int rectsize = sizeof(town_RecT) / sizeof(RECT);//RECT 배열 크기
	for (int i = 0;i < rectsize;++i)
		collision.Coll_Character_Map(character.Get_ChRECT(), town_RecT[i]);
	int linesize = sizeof(town_Line) / sizeof(Line);//Line 배열 크기
	for (int i = 0;i < linesize;++i)
		collision.Line_RECT(town_Line[i], character.Get_ChRECT());

	/*camera.CamCheck(Town_World, camera.Get_CameraRect(),character.Get_ChRECT());*/
	//floorXpos = -800 - floorX;/* camera.Get_CameraX();*/;
	//floorXpos = -800 - camera.Get_CameraX();


	//if (mountainY <= 320)
	//	mountainY = 320;
	cameraX = camera.Get_CameraX();
	cameraY = camera.Get_CameraY();
	floorYpos = -820;
	floorXpos = -800;

	mountainY = 400 - cameraY*0.5;

	mountainX = camera.Get_CameraX()*0.2f;
	treeX = camera.Get_CameraX()*0.4f;
	groundX = camera.Get_CameraX();
	platformX = camera.Get_CameraX();


	//for (auto iter = town_RecT.begin(); iter != town.town_RecT.end();iter++)
	//{
	//	collision.Coll_Player_Map(character.Ch_Rect, *iter);
	//}
	//나무 렌더 이어지게출력
	//if (treeX - 1122 >= 0)
	//{
	//	treeX -= 1122;
	//}
	//else if (treeX + 1122 <= 0)
	//{d
	//	treeX += 1122;
	//}

	//우측이동시
	if (groundX  >= GroundLength && groundX < GroundLength * 2 && gMoveCnt==0)
	{
		gX -= GroundLength;
		++gMoveCnt;
	}
	else if (groundX >= GroundLength * 2 && groundX < GroundLength * 3 && gMoveCnt == 1)
	{
		gX -= GroundLength;
		++gMoveCnt;
	}
	else if (groundX >= GroundLength * 3 && groundX < GroundLength * 4 && gMoveCnt == 2)
	{
		gX -= GroundLength;
		++gMoveCnt;
	}

	//좌측이동시
	else if (groundX < GroundLength * 2 && groundX < GroundLength * 3 && gMoveCnt == 3)
	{
		gX += GroundLength;
		--gMoveCnt;
	}
	else if (groundX < GroundLength * 1 && groundX < GroundLength * 2 && gMoveCnt == 2)
	{
		gX += GroundLength;
		--gMoveCnt;
	}
	else if (groundX < GroundLength * 0 && groundX < GroundLength * 1 && gMoveCnt == 1)
	{
		gX += GroundLength;
		--gMoveCnt;
	}

	playerX = character.Get_PlayerPosX();//캐릭터의 월드좌표를받아옴


	if (playerX >= 3065 && playerX <3845 &&collision.Get_TBCol()&&!doorOpen)//현재 캐릭터가 땅에닿고있고 x좌표가 일정범위이내일때 
	{
		doorOpen = true;
		doorAni = true;
	}


	if (doorAni)
	{
		key.Set_inputOk(false);//던전입구에 들어서면 잠시동안 입력을제한
		character.Set_Sate(Idle);
		if (GetTickCount64() - curtime > 70)
		{
			next_dungeonEat += 480;
			if (next_dungeonEat >= 3840)
			{
				character.Set_CharacterHide(true);//던전입구 애니메이션이 절반이상 지났을때 캐릭터를 감춤 
			}
			else if (next_dungeonEat - 13440>=0)
			{
				next_dungeonEat =0;//애니메이션 한사이클끝나면 0위치초기화
				doorAni = false;//애니메이션이 한사이클만 출력되도록 설정
			}
			curtime = GetTickCount64();
		}
	}

	
}

void Town::Draw()
{


	//하늘
	TownBG_Sky.Render(0, -(cameraY / static_cast<float>(5)), 0, 1, 1);

	//산
	//TownBG_Mountain.Render(-1364 - mountainX, 50, 0, 1, 1);
	TownBG_Mountain.Render(-mountainX, mountainY, 0, 1, 1);
	TownBG_Mountain.Render(1364 - mountainX, mountainY, 0, 1, 1);
	//TownBG_Mountain.Render(- mountainX, 800- cameraY, 0, 1, 1);
	//TownBG_Mountain.Render(1364- mountainX, 800- cameraY, 0, 1, 1);

	//나무
	//TownBG_Tree.Render(-1122 - treeX, 200, 0, 1, 1);
	TownBG_Tree.Render(-treeX, 200 - floorYpos - cameraY, 0, 1, 1);
	TownBG_Tree.Render(1122 - treeX, 200 - floorYpos - cameraY, 0, 1, 1);
	TownBG_Tree.Render(2244 - treeX, 200 - floorYpos - cameraY, 0, 1, 1);

	//계단
	//대각선충돌라인
	//SetLine(town_Line[0], 1818 + floorXpos, 679 + floorYpos, 2379 + floorXpos, 1241 + floorYpos);
	//SetLine(town_Line[1], 2915 + floorXpos, 1228 + floorYpos, 2915 + 434 + floorXpos, 1228 - 432 + floorYpos);
	//SetLine(town_Line[2], 5202 + floorXpos, 809 + floorYpos, 5202 + 415 + floorXpos, 809 + 418 + floorYpos);
	//SetLine(town_Line[3], 6243 + floorXpos, 1232 + floorYpos, 6243 + 555 + floorXpos, 1232 - 555 + floorYpos);

	SetLine(town_Line[0], 1818 + floorXpos, 679, 2379 + floorXpos, 1241);
	SetLine(town_Line[1], 2915 + floorXpos, 1228, 2915 + 434 + floorXpos, 1228 - 432);
	SetLine(town_Line[2], 5197 + floorXpos, 814, 5197 + 415 + floorXpos, 814 + 416);
	SetLine(town_Line[3], 6254 + floorXpos, 1230, 6254 + 566 + floorXpos, 1230 - 566);



	//직선충돌라인
	//SetLine(town_Line[4], 2372 + floorXpos, 1220 + floorYpos, 2372 + 68 + floorXpos, 1220 + floorYpos);
	//SetLine(town_Line[5], 2778 + floorXpos, 1215 + floorYpos, 2778 + 138 + floorXpos, 1215 + floorYpos);
	//SetLine(town_Line[6], 5618 + floorXpos, 1215 + floorYpos, 5618 + 135 + floorXpos, 1215 + floorYpos);
	//SetLine(town_Line[7], 6179 + floorXpos, 1220 + floorYpos, 6179 + 63 + floorXpos, 1220 + floorYpos);

	SetLine(town_Line[4], 2372 + floorXpos, 1220, 2372 + 68 + floorXpos, 1220);
	SetLine(town_Line[5], 2778 + floorXpos, 1215, 2778 + 138 + floorXpos, 1215);
	SetLine(town_Line[6], 5618 + floorXpos, 1215, 5618 + 135 + floorXpos, 1215);
	SetLine(town_Line[7], 6179 + floorXpos, 1220, 6179 + 63 + floorXpos, 1220);
	SetLine(town_Line[11], 64 + floorXpos, 664, 64 + 1753 + floorXpos, 664);
	SetLine(town_Line[12], 3331 + floorXpos, 804, 3331 + 1889 + floorXpos, 804);
	SetLine(town_Line[13], 6807 + floorXpos, 664, 6807 + 1751 + floorXpos, 664);


	Town_Floor.Render(floorXpos - camera.Get_CameraX(), -cameraY, 0, 1, 1);

	//바닥
	SetRect(&town_RecT[0], 0 + groundX, 468 - floorYpos, GroundLength + groundX, 573 - floorYpos);
	//SetRect(&ground_RecT, 0, 473, GroundLength, 573);
	//town_RecT.push_back(ground_RecT);
	TownAtlas.RenderDraw(-GroundLength - groundX - gX, 473 - floorYpos - cameraY, g1.x1, g1.y1, g1.x2, g1.y2, 0, 1, 1);
	TownAtlas.RenderDraw(511 - GroundLength - groundX - gX, 480 - floorYpos - cameraY, g2.x1, g2.y1, g2.x2, g2.y2, 0, 1, 1);
	TownAtlas.RenderDraw(831 - GroundLength - groundX - gX, 480 - floorYpos - cameraY, g2.x1, g2.y1, g2.x2, g2.y2, 0, 1, 1);
	TownAtlas.RenderDraw(1151 - GroundLength - groundX - gX, 473 - floorYpos - cameraY, g1.x1, g1.y1, g1.x2, g1.y2, 0, 1, 1);

	TownAtlas.RenderDraw(-groundX - gX, 473 - floorYpos - cameraY, g1.x1, g1.y1, g1.x2, g1.y2, 0, 1, 1);
	TownAtlas.RenderDraw(511 - groundX - gX, 480 - floorYpos - cameraY, g2.x1, g2.y1, g2.x2, g2.y2, 0, 1, 1);
	TownAtlas.RenderDraw(831 - groundX - gX, 480 - floorYpos - cameraY, g2.x1, g2.y1, g2.x2, g2.y2, 0, 1, 1);
	TownAtlas.RenderDraw(1151 - groundX - gX, 473 - floorYpos - cameraY, g1.x1, g1.y1, g1.x2, g1.y2, 0, 1, 1);

	TownAtlas.RenderDraw(GroundLength - groundX - gX, 473 - floorYpos - cameraY, g1.x1, g1.y1, g1.x2, g1.y2, 0, 1, 1);
	TownAtlas.RenderDraw(511 + GroundLength - groundX - gX, 480 - floorYpos - cameraY, g2.x1, g2.y1, g2.x2, g2.y2, 0, 1, 1);
	TownAtlas.RenderDraw(831 + GroundLength - groundX - gX, 480 - floorYpos - cameraY, g2.x1, g2.y1, g2.x2, g2.y2, 0, 1, 1);
	TownAtlas.RenderDraw(1151 + GroundLength - groundX - gX, 473 - floorYpos - cameraY, g1.x1, g1.y1, g1.x2, g1.y2, 0, 1, 1);

	//지하타일
	TownAtlas.RenderDraw(-10, 543 - floorYpos - cameraY, 320, 576, 384, 640, 0, 22, 6);

	//발판
	//SetRect(&town_RecT[1], 1000 - platformX, 290, 1000 - platformX + 168, 344);
	//SetLine(town_Line[8], 1000 - platformX, 290 + character.Get_CameraY(), 1000 - platformX+168, 290 + character.Get_CameraY());
	SetLine(town_Line[8], 1000, 290 - floorYpos, 1000 + 168, 290 - floorYpos);

	TownAtlas.RenderDraw(1000 - platformX, 300 - floorYpos - cameraY, p1.x1, p1.y1, p1.x2, p1.y2, 0, 1, 1);

	//SetRect(&town_RecT[2], 800 - platformX, 190, 800 - platformX + 168, 344);
	//SetLine(town_Line[9], 800 - platformX, 188 + character.Get_CameraY(), 800 - platformX + 168, 188 + character.Get_CameraY());
	SetLine(town_Line[9], 800, 188 - floorYpos, 800 + 168, 188 - floorYpos);
	TownAtlas.RenderDraw(800 - platformX, 200 - floorYpos - cameraY, p1.x1, p1.y1, p1.x2, p1.y2, 0, 1, 1);

	//SetLine(town_Line[10], 1000 - platformX, 90 + character.Get_CameraY(), 1000 - platformX + 168, 90 + character.Get_CameraY());
	SetLine(town_Line[10], 1000, 90 - floorYpos, 1000 + 168, 90 - floorYpos);
	TownAtlas.RenderDraw(1000 - platformX, 100 - floorYpos - cameraY, p1.x1, p1.y1, p1.x2, p1.y2, 0, 1, 1);

	//SetRect(&plat_RecT, 1740 - platformX, 290, 1740 - platformX + 168, 344);


	if (doorAni)
	{
		DungeonEat.RenderDraw(playerX+CHARACTER_WIDTH*0.5-cameraX-240, 160- floorYpos-cameraY-CHARACTER_HEIGHT*0.5, next_dungeonEat, 0, next_dungeonEat + 480, 360,0,1,1);
	}
}

double& Town::GetSkyY()
{
	return skyY;
}

void Town::SetPos(Position& p,int _x1, int _y1, int _x2, int _y2)
{
	p.x1 = _x1;
	p.y1 = _y1;
	p.x2 = _x2;
	p.y2 = _y2;
}
void Town::SetLine(Line& l, int _x1, int _y1, int _x2, int _y2)
{
	l.x1 = _x1;
	l.y1 = _y1;
	l.x2 = _x2;
	l.y2 = _y2;
}
//마을정보 초기화
void Town::Reset()
{
	
	floorX = 0;
	treeX = 0;
	skyY = 0;
	groundX = 0;
	gX = 0;
	gMoveCnt = 0;
	next_dungeonEat = 0;
	isTownBGMON = false;
	doorOpen = false;
	doorAni = false;
}