#include "Include.h"
WeaponManager weapon;
WeaponManager::WeaponManager()
{
	slashDigree = 0;
	ssWx = 0;
}

WeaponManager::~WeaponManager()
{
}
void WeaponManager::init()
{

	Set_ssWslah(true, false);
	char FileName[256];
	sprintf_s(FileName, "./resources/images/MeleeWeapon/ShortSword.png");
	shortSw.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	digree = 100 * M_PI / 180;//100���� ���Ȱ�����
}
void WeaponManager::Update()
{

		//if (mouse.Get_Lclick())
		//{
		//	mouse.Set_isLclik(true);
		//	if (slashstate.Up)
		//	{
		//		slashDigree = 180 * M_PI / 180;
		//		Set_ssWslah(false, true);
		//	}
		//	else if (slashstate.Down)
		//	{
		//		slashDigree = 0;
		//		Set_ssWslah(true, false);
		//	}
		//}
		//else if (!mouse.Get_Lclick())
		//{
		//	mouse.Set_isLclik(false);
		//}
		if (mouse.Get_isLclick()/* && !mouse.Get_Lclick()*/)
		{
			if (GetTickCount64() - ssWDelay > 300)//��Ŭ�� �Է¿����� �ν� 0.2�� ������
			{
				mouse.Set_isLclik(false);//���콺 Ŭ�� ���ѹ��� �ν��ϵ��� �����ڸ��� false�� ó��
				mouse.Set_Lclik(true);
				Emanager.Set_swingEF(true);//����Ʈ��¿��� ����
				if (slashstate.Up)
				{
					slashDigree = 180 * M_PI / 180;
					ssWx = 20;
					Set_ssWslah(false, true);
				}
				else if (slashstate.Down)
				{
					slashDigree = 0;
					ssWx = 0;
					Set_ssWslah(true, false);
				}

				int swingSound = sound.Get_Effect(SSWSWING);
				sound.EffectPlay(swingSound);
				ssWDelay = GetTickCount64();
			}
		}
		else if (!mouse.Get_isLclick() && mouse.Get_Lclick())
		{
			mouse.Set_Lclik(false);
		}
		


	mouseP = mouse.Get_MousePoint();
	weaponNum = character.Get_Curweapon();//���繫���������Է¹���
	PlayerX = character.Get_PlayerX();
	PlayerY = character.Get_PlayerY();
	angle = atan2(mouseP.y - (PlayerY - CHARACTER_HEIGHT*0.5), mouseP.x - (PlayerX + CHARACTER_WIDTH * 0.5));//ĳ���� �߽ɰ� ���콺Ŀ����ġ���� ����(�����ʱ���)
	angle2 = atan2((PlayerY - CHARACTER_HEIGHT * 0.5) - mouseP.y, (PlayerX + CHARACTER_WIDTH * 0.5) - mouseP.x);//ĳ���� �߽ɰ� ���콺Ŀ����ġ���� ����(���ʱ���)
}
void WeaponManager::Draw()
{

	if (Gmanager.m_GameStart == true) {
		if (!character.Get_CharacterHide())//����� ĳ���Ϳ� �Բ��׷������ϹǷ� ĳ���Ͱ� ������� ���̻��������
		{
			if (character.Get_Direction() == Right)
				shortSw.Render(PlayerX + 40 + ssWx, PlayerY - 40, -digree + slashDigree + angle, 1, 1);
			else if (character.Get_Direction() == Left)
				shortSw.Render(PlayerX + 20 - ssWx, PlayerY - 40, digree - slashDigree + angle2, -1, 1);
		}
	}
}
void WeaponManager::Set_ssWslah(bool _Up, bool _Down)
{
	slashstate.Up = _Up;
	slashstate.Down = _Down;
}
float WeaponManager::Get_Angle1()
{
	return angle;
}
float WeaponManager::Get_Angle2()
{
	return angle2;
}



ssWslash WeaponManager::Get_sswSlash()
{
	return slashstate;
}
