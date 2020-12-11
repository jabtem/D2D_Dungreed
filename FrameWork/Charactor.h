#pragma once
#include "Include.h"

class Character
{
private:
	//스프라이트
	Sprite Ch_Idle;
	Sprite Ch_Jump;
	Sprite Ch_Move;
	Sprite Ch_Die;


	char buffer[128] = { 0,0,0,0 };
	char ch[3] = { 0,0,0 }; 

	//애니메이션 상태, 방향
	int state;
	int direction;

	DWORD curTime;

	float gravity;//점프시계산되는 중력가속도
	float ch_gravity;//캐릭터에 가해지는 중력값(사용X)
	
	//점프
	bool isJump;
	float jumpPower;
	float jumpTime;
	double posY;


	int cameraX;
	int cameraY;
	float next_Idle, next_Move;
	RECT Ch_Rect;//캐릭터 충돌판정 범위
	bool jumpUp;
	int m_W;
	int m_H;
	int curWeapon;//현재장착한무기

public:
	Character();
	~Character();
	void Set_Gravity(float);

	
	int Get_PlayerX();
	int Get_PlayerY();
	void Set_PlayerX(int);
	void Set_PlayerY(int);


	void Set_Sate(int);
	void Set_Direction(int);
	bool& Get_IsJump();
	void Init();
	void Update();
	void Draw();
	void Reset();
	void Coll_Player_Map(RECT p, RECT m);
	void Jumping();
	void Jump_Reset();;
	double Get_CameraY();
	bool& Get_jumpUp();
	RECT Get_ChRECT();
	int Get_Direction();
	bool MoveStop();
	int Get_Curweapon();
	
};

extern Character character;