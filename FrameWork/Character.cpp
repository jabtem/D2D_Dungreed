#include "include.h"

Character character;
Character::Character()
{
	m_W = 0;//초기X좌표
	m_H = 1200;//초기 Y좌표
	next_Idle = 0;
	next_Move = 0;
	state = Idle;
	direction = Right;
	curWeapon = Ssw;//초기기본장비를 숏소드로설정
	//점프
	gravity = 10.0f;
	//ch_gravity = 9.8f;
	jumpPower = 70.0f;
	jumpTime = 0.0f;
	isJump = false;
	jumpUp = false;//점프중 올라가고있을때
}
Character::~Character()
{
}

void Character::Init()
{
	posY = m_H;//점프전 y좌표
	char FileName[256];
	sprintf_s(FileName, "./resources/images/costumes/base/player_idle_X4.png");
	Ch_Idle.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/costumes/base/player_run_X4.png");
	Ch_Move.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/costumes/base/player_jump_X4.png");
	Ch_Jump.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Character::Update()
{
	//현재장비에따라 무기정보 업데이트
	//무기교체가 이뤄질때만 업데이트하도록 설정 교체할때마다 한번만호출
	//camera.followCam(Ch_Rect, camera.Get_CameraRect());
	//collision.Coll_Player_Map(Ch_Rect, town.ground_RecT);
	//collision.Coll_Player_Map(Ch_Rect, town.plat_RecT);

	//int rectsize = sizeof(town.town_RecT) / sizeof(RECT);
	//for (int i=0;i < rectsize;++i)
	//	collision.Coll_Character_Map(Ch_Rect, town.town_RecT[i]);
	//int linesize = sizeof(town.town_Line) / sizeof(Line);
	//for(int i=0;i<linesize;++i)
	//	collision.Line_RECT(town.town_Line[i], Ch_Rect);

	//cameraY = -(-400 + m_H)/2;
	//if ((-400 + m_H) < 0)
	//	cameraY++;
	//else if ((-400 + m_H) == 0)
	//	cameraY = 0;

	cameraY = camera.Get_CameraY();

	if (KeyDown(VK_SPACE)&& !isJump&&!key.Get_isSDown())
	{
		isJump = true;
		posY = m_H;//점프전 캐릭터높이

	}
	if (isJump)
	{
		Jumping();
	}

	if (GetTickCount64() - curTime > 70)
	{

		next_Idle += 60;
		if (next_Idle - 300 >= 0)
		{
			next_Idle -= 300;
		}
		next_Move += 68;
		if (next_Move - 544 >= 0)
		{
			next_Move -= 544;
		}

		curTime = GetTickCount64();
	}
	//if(!collision.Get_TBCol())
	if(!isJump)
		m_H += gravity;

}

void Character::Draw()
{
	if(collision.Get_TBCol())
		dv_font.DrawString("Rectcol :  True", 400, 0);
	else
		dv_font.DrawString("Rectcol :  False", 400, 0);

	if(collision.Get_Trigger())
		dv_font.DrawString("Trigger :  True", 400, 50);
	else
		dv_font.DrawString("Trigger :  False", 400, 50);

	if (collision.Get_LineCol())
		dv_font.DrawString("LineCol :  True", 400, 100);
	else
		dv_font.DrawString("LineCol :  False", 400, 100);

	if(camera.Get_Llimit())
		dv_font.DrawString("Left Limit :  True", 700, 0);
	else
		dv_font.DrawString("Left Limit :  False", 700, 0);

	if (camera.Get_Rlimit())
		dv_font.DrawString("Right Limit :  True", 700, 50);
	else
		dv_font.DrawString("Right Limit :  False", 700, 50);

	if (camera.Get_CamLock())
		dv_font.DrawString("Camera Lock :  True", 700, 100);
	else
		dv_font.DrawString("Camera Lock :  False", 700, 100);


	TCHAR sztext[100];
	sprintf_s(sztext, __TEXT("m_H : %d"), m_H);
	dv_font.DrawString(sztext, 500, 150);

	TCHAR sztext2[100];
	sprintf_s(sztext2, __TEXT("m_W : %d"), m_W);
	dv_font.DrawString(sztext2, 700, 150);

	TCHAR sztext3[100];
	sprintf_s(sztext3, __TEXT("camX : %d"), camera.Get_CameraX());
	dv_font.DrawString(sztext3, 900, 150);

	TCHAR sztext10[100];
	sprintf_s(sztext10, __TEXT("camY : %d"), camera.Get_CameraY());
	dv_font.DrawString(sztext10, 900, 200);



	TCHAR sztext4[100];
	sprintf_s(sztext4, __TEXT("plcl : %d"), camera.plcl);
	dv_font.DrawString(sztext4, 900, 250);

	TCHAR sztext5[100];
	sprintf_s(sztext5, __TEXT("pl : %d"), camera.pl);
	dv_font.DrawString(sztext5, 1100, 200);

	TCHAR sztext6[100];
	sprintf_s(sztext6, __TEXT("cl : %d"), camera.cl);
	dv_font.DrawString(sztext6, 1100, 150);

	TCHAR sztext7[100];
	sprintf_s(sztext7, __TEXT("pt : %d"), camera.pt);
	dv_font.DrawString(sztext7, 1100, 250);

	TCHAR sztext8[100];
	sprintf_s(sztext8, __TEXT("ct : %d"), camera.ct);
	dv_font.DrawString(sztext8, 1100, 300);

	TCHAR sztext9[100];
	sprintf_s(sztext9, __TEXT("ptct : %d"), camera.ptct);
	dv_font.DrawString(sztext9, 1100, 350);




	if (Gmanager.m_GameStart == true) {
		//SetRect(&Ch_Rect, m_W - camera.Get_CameraX(), m_H, m_W - camera.Get_CameraX() + 60, m_H + 80);
		SetRect(&Ch_Rect, m_W , m_H-80, m_W  + 60, m_H);
		switch (state)
		{
		case Idle:
			if (direction == Right) {
				Ch_Idle.RenderDraw(m_W - camera.Get_CameraX(), m_H - 80 - cameraY, next_Idle, 0, next_Idle + 60, 80, 0, 1.0, 1.0);

			}
			else if (direction == Left)
				Ch_Idle.RenderDraw(m_W - camera.Get_CameraX() + 60, m_H - 80 - cameraY, next_Idle, 0, next_Idle + 60, 80, 0, -1.0, 1.0);
			break;
		case Move:
			if (direction == Right) {
				Ch_Move.RenderDraw(m_W - camera.Get_CameraX(), m_H - 80 - cameraY, next_Move, 0, next_Move + 68, 80, 0, 1.0, 1.0);
			}
			else if (direction == Left)
				Ch_Move.RenderDraw(m_W - camera.Get_CameraX() +68, m_H - 80 - cameraY, next_Move, 0, next_Move + 68, 80, 0, -1.0, 1.0);
			break;
		case Jump:
			if (direction == Right)
				Ch_Jump.Render(m_W - camera.Get_CameraX(), m_H - 80 - cameraY, 0, 1.0, 1.0);
			else if (direction == Left)
				Ch_Jump.Render(m_W - camera.Get_CameraX() +68, m_H - 80 - cameraY, 0, -1.0, 1.0);

			break;
		};
	}
}

void Character::Reset()
{
	m_W = 0;
	m_H = 400;
}
void Character::Set_Sate(int _state)//캐릭터 상태
{
	state = _state;
}


void Character::Set_Direction(int _direction)//현재 방향
{
	direction = _direction;
}

void Character::Jumping()
{
	if (jumpTime > 6)
		jumpUp = false;
	else {
		jumpUp = true;
		collision.Get_TBCol() = false;
	}
		
	int height = (jumpTime * jumpTime * (-gravity) / 2) + (jumpTime * jumpPower);

	
	m_H = posY - height;

	jumpTime += deltaTime.GetDeltaTime()*15;


	//if (jumpPower >= 80.0f)
	//{
	//	jumpPower = 80.0f;
	//}

	//if (height<0.0f&&collision.Get_TDCol())
	//{
	//	//m_H = posY;
	//	//state = Idle;
	//	Jump_Reset();
	//	state = Idle;
	//}

}

//현재 점프중인지 구분
bool& Character::Get_IsJump()
{
	return isJump;
}
//점프중 올라가고있는지 떨어지고있는지 구분
bool& Character::Get_jumpUp()
{
	return jumpUp;
}
void Character::Jump_Reset()
{
	jumpTime = 0.0f;
	isJump = false;
	jumpPower = 70.0f;;
	state = Idle;

}
void Character::Set_Gravity(float _gravity)
{
	ch_gravity = _gravity;
}

double Character::Get_CameraY()
{
	return cameraY;
}

RECT Character::Get_ChRECT()
{
	return Ch_Rect;
}
int Character::Get_Direction()
{
	return direction;
}

bool Character::MoveStop()
{
	RECT cam = camera.Get_CameraRect();

	if (Ch_Rect.left <= cam.left && direction == Left)
		return true;
	else if (Ch_Rect.right >= cam.right && direction == Right)
		return true;
	else
		return false;
}

int Character::Get_PlayerX()
{
	return m_W;
}

int Character::Get_PlayerY()
{
	return m_H;
}

void Character::Set_PlayerX(int x)
{
	m_W = x;
}

void Character::Set_PlayerY(int y)
{
	m_H = y;
}

int Character::Get_Curweapon()
{
	return curWeapon;
}