#pragma once
#include "Include.h"


class Monster
{
private:
	Sprite Idle;
	Sprite Attack;
	Sprite Move;
	Sprite Destory;//�������� ���߿���


	DWORD animTime;//�ִϸ��̼� ����
	//�ִϸ��̼��� ���¿� ����
	int state;
	int direction;

	bool live;

	int x;//���� x��ǥ
	int y;//���� y��ǥ

	int cameraX;//ī�޶�x��ǥ
	int cameraY;//ī�޶�y��ǥ

	int MonsterX;
	int MonsterY;

	float next_Idle, next_Move, next_Attack, next_Die;

	
public:
	Monster(void);
	~Monster(void);

	void Init();
	void Update();
	void Draw();
	void Spawn(int ,int);

};

extern Monster monster;