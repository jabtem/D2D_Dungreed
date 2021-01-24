
#include "Include.h"
Mouse mouse;
Mouse::Mouse()
{
	Lclick = false;
	isLclick = false;
	clikOk = true;//마우스클릭은 기본적으로 가능한상태
}

Mouse::~Mouse()
{
}

void Mouse::Set_MousePoint(int x, int y)
{
	mousePoint.x = x;
	mousePoint.y = y;
}

POINT Mouse::Get_MousePoint()
{
	return mousePoint;
}
void Mouse::Set_Lclik(bool TF)
{
	Lclick = TF;
}
bool Mouse::Get_Lclick()
{
	return Lclick;
}

void Mouse::Set_isLclik(bool TF)
{
	isLclick = TF;
}
bool Mouse::Get_isLclick()
{
	return isLclick;
}

void Mouse::Set_isRclick(bool TF)
{
	isRclick = TF;
}
bool Mouse::Get_isRclick()
{
	return isRclick;
}

void Mouse::Set_clickOk(bool TF)
{
	clikOk = TF;
}
bool Mouse::Get_clickOk()
{
	return clikOk;
}