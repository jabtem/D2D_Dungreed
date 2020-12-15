#pragma once
#include "Include.h"

class Character
{
private:
	//��������Ʈ
	Sprite Ch_Idle;
	Sprite Ch_Jump;
	Sprite Ch_Move;
	Sprite Ch_Die;


	char buffer[128] = { 0,0,0,0 };
	char ch[3] = { 0,0,0 }; 

	//�ִϸ��̼� ����, ����
	int state;
	int direction;

	DWORD curTime;

	float gravity;//�����ð��Ǵ� �߷°��ӵ�
	float ch_gravity;//ĳ���Ϳ� �������� �߷°�(���X)
	
	//����
	bool isJump;
	float jumpPower;
	float jumpTime;
	double posY;
	double posX;

	float nomx;
	float nomy;


	//�뽬
	float dashPower;
	float dashTime;
	bool isDash;

	int cameraX;
	int cameraY;
	float next_Idle, next_Move;
	RECT Ch_Rect;//ĳ���� �浹���� ����
	bool jumpUp;
	POINT mouseP;
	int m_W;//ĳ���� ���� x��ǥ
	int m_H;//ĳ���� ���� y��ǥ

	int PlayerX;//ī�޶󿵿����� ĳ���� x��ǥ
	int PlayerY;//ī�޶󿵿����� ĳ���� y��ǥ

	int prePlayerX;//��Ŭ�� ������ x��ǥ
	int prePlayerY;//��Ŭ�� ������ y��ǥ

	float angle1;//�����ʱ��� ĳ�����߽ɰ� ���콺 Ŀ�� ������ ����
	float angle2;//���ʱ��� ĳ���� �߽ɰ� ���콺 Ŀ�� ������ ����

	int curWeapon;//���������ѹ���
	bool isLeftMove;
	bool isRightMove;

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
	void MoveLeft();
	void MoveRight();
	
};

extern Character character;