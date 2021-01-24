#include "Include.h"


Monster monster;



Monster::Monster(void)
{
	live = true;//���� ���翩��
	state = EIdle;
	next_Idle = 0;
	next_Move = 0;
	next_Attack = 0;
	x = 0;
	y = 0;

	direction = Right;//ĳ���Ͱ� �⺻�� �������̹Ƿ� �ݴ��� ������ �⺻������������
}

Monster::~Monster(void)
{
}

void Monster::Init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/idle.png");//���η� 132 ���η� 120���ڸ� �� 660
	Idle.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/attack.png");//���η� 284 ���η� 192���ڸ� �� 3408
	Attack.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/move.png");//���η� 132 ���η� 120���ڸ� �� 792
	Move.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resources/images/Enemy/Skel/Big_Normal/destroy.png");//���η� 160 ���η� 160���ڸ� �� 1760
	Destory.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}


//���� �ش���ġ�� �����ϴ��Լ�
void Monster::Spawn(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Monster::Update()
{
	cameraX = camera.Get_CameraX();//ī�޶��� X��
	cameraY = camera.Get_CameraY();//ī�޶��� Y��

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

