
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

void Mouse::Init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/common/cursor/BasicCursor.png");
	MenuCursor.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resources/images/common/cursor/ShootingCursor2.png");
	GameCursor.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}
void Mouse::Draw()
{
	if(g_Mng.n_Chap == MENU)
		MenuCursor.Render(mousePoint.x-38, mousePoint.y-38, 0, 1, 1);
	else if(g_Mng.n_Chap == GAME)
		GameCursor.Render(mousePoint.x-42, mousePoint.y-42, 0, 1, 1);
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