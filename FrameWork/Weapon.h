//�ܼ��� ���������� �����ϱ����� Ŭ����

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
	void Set_MouseX(int);
	void Set_MouseY(int);
private:
	Sprite shortSw;
	int weaponNum;
	int PlayerX;
	int PlayerY;
	int MouseX;
	int MouseY;
	float digree;
	float angle;
	float angle2;
};
extern WeaponManager weapon;