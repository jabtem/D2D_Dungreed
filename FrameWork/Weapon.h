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

	void Set_ssWslah(bool, bool);
	ssWslash Get_sswSlah();
private:
	Sprite shortSw;
	int weaponNum;
	int PlayerX;
	int PlayerY;
	DWORD ssWDelay;//���ҵ� �ֵθ��� ������
	//int MouseX;
	//int MouseY;
	POINT mouseP;
	float digree;
	float slashDigree;//���ҵ� ������ ��ȭ�� ������
	float ssWx;//������ �̹����������濡���� x����ġ ������
	float angle;
	float angle2;

	ssWslash slashstate;
};
extern WeaponManager weapon;