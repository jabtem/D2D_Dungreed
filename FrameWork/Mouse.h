//���콺 ��ǥ�� ������ Ŭ����

#pragma once
#include "Include.h"
class Mouse
{
public:
	Mouse();
	~Mouse();
	void Update();
	void Set_MousePoint(int, int);
	POINT Get_MousePoint();
	void Set_isLclik(bool);
	bool Get_isLclick();
	void Set_Lclik(bool);
	bool Get_Lclick();
	void Set_isRclick(bool);
	bool Get_isRclick();
	void Set_clickOk(bool);
	bool Get_clickOk();
	

private:
	POINT mousePoint;
	bool Lclick;
	bool clikOk;//���콺 Ŭ�����ɿ���
	bool isLclick;
	bool isRclick;
};
extern Mouse mouse;