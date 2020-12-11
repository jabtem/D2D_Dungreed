#include "Include.h"
WeaponManager weapon;
WeaponManager::WeaponManager()
{
	slashDigree = 0;
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

	digree = 100 * M_PI / 180;//100도를 라디안값으로
}
void WeaponManager::Update()
{
	if (GetTickCount64() - ssWDelay > 300)
	{
		if (mouse.Get_Lclick())
		{
			if (slashstate.Up)
			{
				slashDigree = 180 * M_PI / 180;
				Set_ssWslah(false, true);
			}
			else if (slashstate.Down)
			{
				slashDigree = 0;
				Set_ssWslah(true, false);
			}
		}
		ssWDelay = GetTickCount64();
	}

	mouseP = mouse.Get_MousePoint();
	weaponNum = character.Get_Curweapon();
	PlayerX = character.Get_PlayerX()  - camera.Get_CameraX();
	PlayerY = character.Get_PlayerY()  - camera.Get_CameraY(); 
	angle = atan2(mouseP.y - (PlayerY - CHARACTER_HEIGHT*0.5), mouseP.x - (PlayerX + CHARACTER_WIDTH * 0.5));//캐릭터 중심과 마우스위치와의 각도(오른쪽기준)
	angle2 = atan2((PlayerY - CHARACTER_HEIGHT * 0.5) - mouseP.y, (PlayerX + CHARACTER_WIDTH * 0.5) - mouseP.x);//캐릭터 중심과 마우스위치와의 각도(왼쪽기준)
}
void WeaponManager::Draw()
{
	TCHAR sztext[100];
	sprintf_s(sztext, __TEXT("moueseX : %d"), mouseP.x);
	dv_font.DrawString(sztext, 900, 300);
	sprintf_s(sztext, __TEXT("moueseY : %d"), mouseP.y);
	dv_font.DrawString(sztext, 900, 350);



	if (Gmanager.m_GameStart == true) {
		if(character.Get_Direction() == Right)
			shortSw.Render(PlayerX+ 40, PlayerY-40, -digree + slashDigree + angle,1, 1);
		else if (character.Get_Direction() == Left)
			shortSw.Render(PlayerX+20 , PlayerY - 40, digree - slashDigree + angle2, -1, 1);
	}
	//switch (weaponNum)
	//{
	//case Ssw:
	//	
	//}
}
void WeaponManager::Set_ssWslah(bool _Up, bool _Down)
{
	slashstate.Up = _Up;
	slashstate.Down = _Down;
}

ssWslash WeaponManager::Get_sswSlah()
{
	return slashstate;
}