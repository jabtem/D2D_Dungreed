//마우스 좌표를 관리용 클래스

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
	

private:
	POINT mousePoint;
	bool Lclick;
	bool isLclick;
	bool isRclick;
};
extern Mouse mouse;