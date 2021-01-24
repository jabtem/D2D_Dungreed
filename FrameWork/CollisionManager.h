#pragma once
#include "Include.h"

class Collision
{
public:
	Collision();
	~Collision();
	void Coll_Character_Map(RECT,RECT);//캐릭터와 맵사이의충돌검사(물리충돌)
	bool& Get_TBCol();
	bool& Get_Trigger();
	bool Get_LineCol();
	bool Get_isRoomChange();
	void Set_isRoomChange(bool);
	void Coll_Character_MoveZone(RECT, RECT);//AABB충돌 캐릭터와 던전룸 워프영역간의 충돌여부확인
	bool Line_Line(float, float, float, float, float, float, float, float);//선과 선 충돌
	void Line_RECT(Line, RECT);//선과 사각형충돌
	RECT Get_MoveZone();

	bool col;
private:
	RECT rcTemp;//임시
	RECT moveZone;
	bool isTBCol;//위아래충돌구분
	bool isRoomChange;
	bool isLRCol;//좌우충돌구분
	bool isLineCol;//선충돌구분
	bool trigger;//하단점프구현용 트리거변수

	bool isMoveCol;//이동영역 충돌
	int triggercnt;//일정시간후 트리거해제
	float intersectionX;//교점의 x좌표저장변수
	float intersectionY;//교점의 y좌표저장변수

	//float left_intersectionX;//사각형의 왼쪽면과 선 충돌시 교점 저장변수
	//float left_intersectionY;

	//float right_intersectionX;//사각형의 오른쪽면과 선 충돌시 교점 저장변수
	//float right_intersectionY;
};

extern Collision collision;