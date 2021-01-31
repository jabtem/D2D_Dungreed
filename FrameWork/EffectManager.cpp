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
	
	//�ΰ��� ���콺 Ŭ���̺�Ʈ �߻��� ������ ĳ���Ϳ� ���콺�ޱ����� ������
	if (mouse.Get_Lclick())
	{
		PlayerX = character.Get_PlayerPosX() + CHARACTER_WIDTH * 0.5;//���콺 Ŭ�� ������ ĳ���� X��ǥ
		PlayerY = character.Get_PlayerPosY() - CHARACTER_HEIGHT * 0.5;//���콺 Ŭ�� ������ ĳ���� Y��ǥ
		angleR = weapon.Get_Angle1();//���콺 Ŭ�� ������ ĳ���Ϳ� ���콺������ ����
	}
	//�ӽ�
	angleR2 = weapon.Get_Angle1();//������¿�



	CameraX = camera.Get_CameraX();
	CameraY = camera.Get_CameraY();

	//ĳ���Ϳ� ���콺�����ͻ����� ����
	andgleD = angleR * -180 / M_PI;//���Ȱ����� ��������

	//������ �����ʱ��� �����ǥ�ΰ��
	if (andgleD >= 0)
		andgleD = andgleD;
	else if (andgleD < 0)
		andgleD = 360 + andgleD;

}
//��÷� ��ǥ���޴°Ծƴ� ���콺 Ŭ���� ������ ĳ������ x,y�����޾� �ش������� ����Ʈ�� ����ؾ���
void EffectManager::Draw()
{

	if (Gmanager.m_GameStart == true) {
		//if (PlayerDirection == Right)//������
		//{
		if (swingEF)//���콺 Ŭ���ɶ��� Draw
		{
			float effectDegree;
			if (andgleD < 22.5 || andgleD>=337.5)//����������Ʈ
			{
				effectDegree = 0;
				swing1.RenderDraw(PlayerX - CameraX +20, PlayerY - CameraY - 80, next_swing, 0, next_swing + 112, 160, effectDegree, 1.0, 1.0);
			}
			else if (andgleD >= 22.5 && andgleD < 67.5)//����
			{
				effectDegree = 45 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX - 30, PlayerY - CameraY - 80 + 20, next_swing+1, 0, next_swing + 112, 160, -effectDegree, 1.0, 1.0);
			}
			else if (andgleD >= 67.5 && andgleD < 112.5)//���
			{
				effectDegree = 90 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX -75, PlayerY - CameraY -10, next_swing , 0, next_swing + 112, 160, -effectDegree, 1.0, 1.0);
			}
			else if (andgleD >= 112.5 && andgleD < 157.5)//�»��
			{
				effectDegree = 45 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX +30, PlayerY - CameraY - 80 + 20, next_swing, 0, next_swing + 112, 160, effectDegree, -1.0, 1.0);
			}
			else if (andgleD >= 157.5 && andgleD < 202.5)//����
			{
				effectDegree = 0;
				swing1.RenderDraw(PlayerX - CameraX - 20, PlayerY - CameraY - 80 , next_swing, 0, next_swing + 112, 160, effectDegree, -1.0, 1.0);
			}
			else if (andgleD >= 202.5 && andgleD < 247.5)//���ϴ�
			{
				effectDegree = 45 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX -90, PlayerY - CameraY - 80 +40, next_swing, 0, next_swing + 112, 160, -effectDegree, -1.0, 1.0);
			}
			else if (andgleD >= 247.5 && andgleD < 292.5)//�ϴ�
			{
				effectDegree = 90 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX + 75, PlayerY - CameraY + 10, next_swing, 0, next_swing + 112, 160, effectDegree, 1.0, 1.0);
			}
			else if (andgleD >= 292.5 && andgleD < 337.5)//���ϴ�
			{
				effectDegree = 45 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX +80, PlayerY - CameraY - 80 +40, next_swing+1, 0, next_swing + 112, 160, effectDegree, 1.0, 1.0);
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

void EffectManager::Set_getinfo(bool _TF)
{
	getinfo = _TF;
}