#include "Include.h"
Dungeon dungeon;
Dungeon::Dungeon()
{
	tile = new TileNum(100, 10);
	SetRect(&RoomZero_World, 0, 0, 1408, 768);//던전0번룸의 월드맵
	SetRect(&RoomOne_World, 0, 0, 1600, 768);
	SetRect(&RoomTwo_World, 0, 0, 1600, 768);
	roominfo = new RoomData;
	cameraX = 0;
	cameraY = 0;
	curRoomNum = 0;//최초 던전룸은 0번이기때문
	col = false;
	isDungeonBGMON = false;
}
//던전룸 사이의 이동을 어떻게 매끄럽게할것인가? (현재 중요과제)
//테스트삼아 정한 던전룸1을 제대로꾸미기
//마을맵 마저꾸미기
//던전룸1번 완성후 간단하게 몬스터 2종류정도 추가(AI는 일단 최대한 간단하게)
Dungeon::~Dungeon()
{
	delete tile;
	delete roominfo;
}
void Dungeon::init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/Map/tileAtlas3.png");//한칸에 64,64 픽셀씩잘라 타일맵으로사용
	DungeonAtlas.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Dungeon::Update()
{
	if (!isDungeonBGMON)
	{
		int DBGM = sound.Get_BGM(DUNGEONBGM);//BGM파일불러옴
		//sound.BGReset();
		//sound.BGPlay(DBGM);
		sound.BGMChange(DBGM);
		isDungeonBGMON = true;
	}

	cameraX = camera.Get_CameraX();
	cameraY = camera.Get_CameraY();

	//던전방별로 카메라설정
	if(curRoomNum == 0)
		camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), RoomZero_World);
	else if(curRoomNum == 1)
	{
		camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), RoomOne_World);
	}
	else if(curRoomNum == 2)
	{
		camera.followCam(character.Get_ChRECT(), camera.Get_CameraRect(), RoomTwo_World);
	}

	//룸이동 구상
	//렉트로 던전룸에 워프존을넣고 워프존과 충돌이 일어날시 어떤워프존과 충돌이일어났느냐에따라 어떤방으로 이동할지 다음좌표가 어떻게될지를결정
	//다른룸 이동했을시 충돌영역을 초기화해주지않으면 이전방에서 설정된 충돌이 그대로 일어남으로 충돌영역을 방이동마다 초기화하도록 구성
	int rectsize = sizeof(wall) / sizeof(RECT);//RECT 배열 크기
	for (int i = 0;i < rectsize;++i)
		collision.Coll_Character_Map(character.Get_ChRECT(), wall[i]);

	int rectsize2 = sizeof(moveZone) / sizeof(RECT);//RECT 배열 크기
	for (int i = 0;i < rectsize2;++i)
	{
		collision.Coll_Character_MoveZone(character.Get_ChRECT(), moveZone[i]);
	}


	//방이동
	if (collision.Get_isRoomChange())
	{
		//이동존에 닿았고 현재방번호에따라 구분
		switch (curRoomNum)
		{
		case 0:
			preRoomNum = curRoomNum;//현재 룸넘버를 이전룸넘버에 저장
			curRoomNum = 1;
			character.Reset(128, 630);
			camera.Cam_Reset();//카메라 좌표초기화
			collision.Set_isRoomChange(false);
			resetRect();
			break;
		case 1:
			preRoomNum = curRoomNum;//현재 룸넘버를 이전룸넘버에 저장
			//충돌역영의 left가 movezon0일경우 이전방 1이면 다음방
			if (collision.Get_MoveZone().left == moveZone[0].left)
			{
				curRoomNum = 0;
				character.Reset(64*20, 630);

			}
			else if(collision.Get_MoveZone().left == moveZone[1].left)
			{
				curRoomNum = 2;
				character.Reset(128, 630);
			}
			camera.Cam_Reset();//카메라 좌표초기화
			collision.Set_isRoomChange(false);
			resetRect();
			break;
		}

	}

}

void Dungeon::Draw()
{
	switch (curRoomNum)
	{
	case 0:
		//0번룸 세팅
		SetRect(&wall[0], 0, 630, 1408, 768);
		SetRect(&wall[1], 0, 0, 128, 768);
		SetRect(&wall[2], 1280, 0, 1408, 384);
		SetRect(&moveZone[0], 1344+32, 384, 1408, 640);//이동영역
		DrawRoom(0);//던전 0번룸 그림
		break;
	case 1:
		//바닥
		SetRect(&wall[0], 0, 630, 1600, 768);
		//왼벽
		SetRect(&wall[1], 0, 0, 128, 64*6);
		//천장
		SetRect(&wall[2], 0, 0, 64 * 25, 64 * 2);
		//오른벽
		SetRect(&wall[3], 64*23, 0, 64 * 25, 64 * 6);
		SetRect(&moveZone[0], 0, 64 * 6, 32, 640);//이동영역
		SetRect(&moveZone[1], 64*24+32, 64 * 6, 64*25, 640);//이동영역
		
		DrawRoom(1);//던전 1번룸 그림
		monster.Draw();
		break;
	case 2:
		//바닥
		SetRect(&wall[0], 0, 630, 1600, 768);
		DrawRoom(2);//던전 1번룸 그림
		break;
	}
	//0번룸 충돌맵

}

//던전룸 렌더
void Dungeon::DrawRoom(int roomNum)
{
	arrSize size = roominfo->Get_Size(roomNum);
	for (int row = 0; row < size.row;row++)
		for (int col = 0; col < size.col;col++)
			DrawTile(col, row, roominfo->Get_Room(row,col, roomNum));

}
//타일맵 그리는함수
void Dungeon::DrawTile(float x, float y, int _tileInfo)
{
	DungeonAtlas.RenderDraw(x * TILE_SIZE- cameraX, y * TILE_SIZE- cameraY,
		tile->Get_itemX(_tileInfo) * TILE_SIZE, tile->Get_itemY(_tileInfo) * TILE_SIZE,
		(tile->Get_itemX(_tileInfo) + 1) * TILE_SIZE, (tile->Get_itemY(_tileInfo) + 1) * TILE_SIZE,
		0, 1, 1);
}

void Dungeon::resetRect()
{
	//룸이동후 충돌영역 초기화
	int rectsize = sizeof(wall) / sizeof(RECT);//RECT 배열 크기
	RECT reset = { 0,0,0,0 };
	for (int i = 0;i < rectsize;++i)
		wall[i] = reset;

	//룸이동후 이동영역 초기화 
	int rectsize2 = sizeof(moveZone) / sizeof(RECT);//RECT 배열 크기
	for (int i = 0;i < rectsize2;++i)
		moveZone[i] = reset;
}