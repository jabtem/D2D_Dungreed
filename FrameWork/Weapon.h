//단순히 무기정보를 통합하기위한 클래스

#pragma once
#include "Include.h"
class WeaponManager
{
public:
	WeaponManager();
	~WeaponManager();

	void init();
	void Update();
	void Draw();

	void Set_ssWslah(bool, bool);
	ssWslash Get_sswSlah();
private:
	Sprite shortSw;
	int weaponNum;
	int PlayerX;
	int PlayerY;
	DWORD ssWDelay;//숏소드 휘두르는 딜레이
	//int MouseX;
	//int MouseY;
	POINT mouseP;
	float digree;
	float slashDigree;//숏소드 공격후 변화될 각도값
	float ssWx;//공격후 이미지각도변경에따른 x축위치 재조정
	float angle;
	float angle2;

	ssWslash slashstate;
};
extern WeaponManager weapon;