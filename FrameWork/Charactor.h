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

	DWORD curTime;//애니메이션간격
	DWORD durationflight; //체공시간

	float gravity;//평시중력
	float jumpGravity;//점프시 계산되는 중력
	float ch_gravity;//캐릭터에 가해지는 중력값(사용X)
	
	//점프
	bool isJump;
	float jumpPower;
	float jumpTime;
	double posY;
	double posX;

	float nomx;
	float nomy;


	//대쉬
	float dashPower;
	float dashTime;
	bool isDash;

	int cameraX;
	int cameraY;
	float next_Idle, next_Move;
	RECT Ch_Rect;//캐릭터 충돌판정 범위
	bool jumpUp;
	POINT mouseP;
	int m_W;//캐릭터 실제 x좌표
	int m_H;//캐릭터 실제 y좌표

	int PlayerX;//카메라영역기준 캐릭터 x좌표
	int PlayerY;//카메라영역기준 캐릭터 y좌표

	int prePlayerX;//우클릭 시점의 x좌표
	int prePlayerY;//우클릭 시전의 y좌표

	float angle1;//오른쪽기준 캐릭터중심과 마우스 커서 사이의 각도
	float angle2;//왼쪽기준 캐릭터 중심과 마우스 커서 사이의 각도

	int curWeapon;//현재장착한무기
	bool isLeftMove;
	bool isRightMove;
	bool characterHide;//캐릭터 이미지 숨김여부

public:
	Character();
	~Character();
	void Set_Gravity(float);


	int Get_PlayerPosX();
	int Get_PlayerPosY();
	int Get_PlayerX();
	int Get_PlayerY();
	void Set_PlayerPosX(int);
	void Set_PlayerPosY(int);
	void Dash();
	void Set_Sate(int);
	void Set_Direction(int);
	bool& Get_IsJump();
	void Init();
	void Update();
	void Draw();
	void Reset(int,int);
	//void Coll_Player_Map(RECT p, RECT m);
	void Jumping();
	void Jump_Reset();;
	double Get_CameraY();
	bool& Get_jumpUp();
	RECT Get_ChRECT();
	int Get_Direction();
	bool MoveStop();
	int Get_Curweapon();
	void MoveLeft();
	void MoveRight();
	void Set_CharacterHide(bool);
	bool Get_CharacterHide();
	
};

extern Character character;