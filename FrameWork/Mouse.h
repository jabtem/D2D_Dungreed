//마우스 좌표를 관리용 클래스

#pragma once
#include "Include.h"
class Mouse
{
public:
	Mouse();
	~Mouse();
	void Init();
	void Draw();
	void Update();//메시지로 실시간으로 마우스좌표를 받아오기때문에 현재필요x 필요시사용하기위해 선언만해둠
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
	Sprite MenuCursor;
	Sprite GameCursor;
	bool Lclick;
	bool clikOk;//마우스 클릭가능여부
	bool isLclick;
	bool isRclick;
};
extern Mouse mouse;