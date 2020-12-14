#include "Include.h"
EffectManager Emanager;
EffectManager::EffectManager()
{
	next_swing = 0;
	PlayerX = 0;
	PlayerY = 0;
	swingEF = false;
}

EffectManager::~EffectManager()
{
}

void EffectManager::Init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/MeleeWeapon/SwingFX.png");//���� 112 ���� 160���ڸ�
	swing1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void EffectManager::Update()
{
	if (GetTickCount64() - curTime > 100)
	{
		if (swingEF)
		{
			/// <����ȿ��> �Ѿִϸ��̼Ǵٳ����� �˾Ƽ� �����ʱ�ȭ
			//next_swing = 0;
			next_swing += 112;
			if (next_swing - 336 == 0)
			{
				next_swing -= 336;
				swingEF = false;
			}
			/// </����ȿ��>

		}
		curTime = GetTickCount64();
	}
	weaponNum = character.Get_Curweapon();

	if (mouse.Get_Lclick())//�ΰ��� ���콺 Ŭ���̺�Ʈ �߻��� ������ ĳ���� x,y��ǥ�� ����, ĳ���Ϳ� ���콺Ŀ�� ������ ����
	{
		PlayerX = character.Get_PlayerX() + CHARACTER_WIDTH * 0.5;//���� ĳ������ �����ǥ
		PlayerY = character.Get_PlayerY() - CHARACTER_HEIGHT * 0.5;
		PlayerDirection = character.Get_Direction();
		angleR = weapon.Get_Angle1();
		angleR2 = weapon.Get_Angle2();
	}
	CameraX = camera.Get_CameraX();
	CameraY = camera.Get_CameraY();

	//ĳ���Ϳ� ���콺�����ͻ����� ����


	andgleD = angleR * -180 / M_PI;//���Ȱ����� ��������
	//andgleD2 = angleR2 * 180 / M_PI;

	//������ �����ʱ��� �����ǥ�ΰ��
	if (andgleD >= 0)
		andgleD = andgleD;
	else if (andgleD < 0)
		andgleD = 360 + andgleD;

}
//��÷� ��ǥ���޴°Ծƴ� ���콺 Ŭ���� ������ ĳ������ x,y�����޾� �ش������� ����Ʈ�� ����ؾ���
void EffectManager::Draw()
{
	TCHAR sztext[100];
	sprintf_s(sztext, __TEXT("andgleD : %f"), andgleD);
	dv_font.DrawString(sztext, 1100, 400);


	if (Gmanager.m_GameStart == true) {
		//if (PlayerDirection == Right)//������
		//{
		if (swingEF)//���콺 Ŭ���ɶ��� Draw
		{
			float effectDegree;
			if (andgleD < 22.5 || andgleD>337.5)//����������Ʈ
			{
				effectDegree = 0;
				swing1.RenderDraw(PlayerX - CameraX, PlayerY - CameraY - 80, next_swing, 0, next_swing + 112, 160, effectDegree, 1.0, 1.0);
			}
			else if (andgleD >= 22.5 && andgleD < 77.5)
			{
				effectDegree = 45 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX - 60, PlayerY - CameraY - 80 + 40, next_swing+1, 0, next_swing + 112, 160, -effectDegree, 1.0, 1.0);
			}

		}

			
		//}
		//else if (PlayerDirection == Left)//����
		//{
		//	if (swingEF)//���콺 Ŭ���ɶ��� Draw
		//		swing1.RenderDraw(PlayerX - CameraX, PlayerY - CameraY - 80, next_swing, 0, next_swing + 112, 160, 0, -1.0, 1.0);
		//}
	}

}
void EffectManager::Set_swingEF(bool _TF)
{
	swingEF = _TF;
}