#pragma once
#include "Include.h"

class Collision
{
public:
	Collision();
	~Collision();
	void Coll_Character_Map(RECT,RECT);//사각형충돌검사
	void Coll_Camera_Character(RECT, RECT);
	bool& Get_TBCol();
	bool& Get_Trigger();
	bool Get_LineCol();

	bool Line_Line(float, float, float, float, float, float, float, float);//선과 선 충돌
	void Line_RECT(Line, RECT);//선과 사각형충돌
private:
	RECT rcTemp;//임시
	bool isTBCol;//위아래충돌구분
	bool isLRCol;//좌우충돌구분
	bool isLineCol;//선충돌구분
	bool trigger;//하단점프구현용 트리거변수
	int triggercnt;
	float intersectionX;//교점의 x좌표저장변수
	float intersectionY;//교점의 y좌표저장변수

	//float left_intersectionX;//사각형의 왼쪽면과 선 충돌시 교점 저장변수
	//float left_intersectionY;

	//float right_intersectionX;//사각형의 오른쪽면과 선 충돌시 교점 저장변수
	//float right_intersectionY;
};

extern Collision collision;