#include "Include.h"


Monster monster;



Monster::Monster(void)
{
	live = true;//몬스터 생사여부
	state = EIdle;
	next_Idle = 0;
	next_Move = 0;
	next_Attack = 0;
	x = 0;
	y = 0;

	direction = Right;//캐릭터가 기본이 오른쪽이므로 반대인 왼쪽을 기본방향으로잡음
}

Monster::~Monster(void)
{
}

void Monster::Init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/idle.png");//가로로 132 세로로 120씩자름 총 660
	Idle.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/attack.png");//가로로 284 세로로 192씩자름 총 3408
	Attack.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/move.png");//가로로 132 세로로 120씩자름 총 792
	Move.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/destroy.png");//가로로 160 세로로 160씩자름 총 1760
	Destory.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}


//몹을 해당위치에 스폰하는함수
void Monster::Spawn(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Monster::Update()
{
	cameraX = camera.Get_CameraX();//카메라의 X값
	cameraY = camera.Get_CameraY();//카메라의 Y값

	if (GetTickCount64() - animTime > 70)
	{
		next_Idle += 132;
		if (next_Idle - 660 >= 0)
		{
			next_Idle -=660;
		}
		next_Move += 132;
		if (next_Move - 660 >= 0)
		{
			next_Move -= 660;
		}
		next_Attack += 192;
		if (next_Attack - 3408 >= 0)
		{
			next_Attack -= 3408;
		}
		next_Die += 160;
		if (next_Die - 1760 >= 0)
		{
			next_Die -= 1760;
		}

		animTime = GetTickCount64();
	}
	MonsterX = x - cameraX;
	MonsterY = y - cameraY;
	
}


void Monster::Draw()
{
	if (live)
	{
		switch (state)
		{
		case EIdle:
			if (direction == Right)
			{
				Idle.RenderDraw(MonsterX, 0, next_Idle, 0, next_Idle + 132, 120, 0, 1.0, 1.0);
			}
			else if (direction == Left)
			{
				Idle.RenderDraw(MonsterX + 132, MonsterY - 120, next_Idle, 0, next_Idle + 132, 120, 0, -1.0, 1.0);
			}
			break;

		case EMove:
			if (direction == Right)
			{
				Move.RenderDraw(MonsterX, MonsterY - 120, next_Idle, 0, next_Idle + 132, 120, 0, 1.0, 1.0);
			}
			else if (direction == Left)
			{
				Move.RenderDraw(MonsterX + 132, MonsterY - 120, next_Idle, 0, next_Idle + 132, 120, 0, -1.0, 1.0);
			}
			break;

		case EAttack:
			if (direction == Right)
			{
				Attack.RenderDraw(MonsterX, MonsterY - 192, next_Idle, 0, next_Idle + 284, 192, 0, 1.0, 1.0);
			}
			else if (direction == Left)
			{
				Attack.RenderDraw(MonsterX + 284, MonsterY - 192, next_Idle, 0, next_Idle + 284, 120, 0, -1.0, 1.0);
			}
			break;

		case EDie:
			Destory.RenderDraw(MonsterX, MonsterY - 160, next_Die, 0, next_Die + 160, 160, 0, 1.0, 1.0);
			break;
		}
	}
}

