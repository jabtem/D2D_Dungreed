//���콺 ��ǥ�� ������ Ŭ����

#pragma once
#include "Include.h"
class Mouse
{
public:
	Mouse();
	~Mouse();
	void Set_MousePoint(int, int);
	POINT Get_MousePoint();
	void Set_isLclik(bool);
	bool Get_isLclick();
	void Set_Lclik(bool);
	bool Get_Lclick();

private:
	POINT mousePoint;
	bool Lclick;
	bool isLclick;
};
extern Mouse mouse;