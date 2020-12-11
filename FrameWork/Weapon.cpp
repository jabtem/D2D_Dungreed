#include "Include.h"
WeaponManager weapon;
WeaponManager::WeaponManager()
{
}

WeaponManager::~WeaponManager()
{
}
void WeaponManager::init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/MeleeWeapon/ShortSword.png");
	shortSw.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	digree = 90 * M_PI / 180;//90µµ
}
void WeaponManager::Update()
{
	weaponNum = character.Get_Curweapon();
	PlayerX = character.Get_PlayerX() - camera.Get_CameraX();
	PlayerY = character.Get_PlayerY() -camera.Get_CameraY(); 
	angle = atan2( MouseY-PlayerY, MouseX-PlayerX);
	angle2 = atan2(PlayerY- MouseY, PlayerX-MouseX);
}
void WeaponManager::Draw()
{
	TCHAR sztext[100];
	sprintf_s(sztext, __TEXT("moueseX : %d"), MouseX);
	dv_font.DrawString(sztext, 900, 300);
	sprintf_s(sztext, __TEXT("moueseY : %d"), MouseY);
	dv_font.DrawString(sztext, 900, 350);



	if (Gmanager.m_GameStart == true) {
		if(character.Get_Direction() == Right)
			shortSw.Render(PlayerX+ 40, PlayerY-40, -digree+angle,1, 1);
		else if (character.Get_Direction() == Left)
			shortSw.Render(PlayerX+20 , PlayerY - 40, digree+angle2, -1, 1);
	}
	//switch (weaponNum)
	//{
	//case Ssw:
	//	
	//}
}

void WeaponManager::Set_MouseX(int _x)
{
	MouseX = _x;
}
void WeaponManager::Set_MouseY(int _y)
{
	MouseY = _y;
}
