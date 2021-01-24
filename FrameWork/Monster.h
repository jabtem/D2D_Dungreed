#pragma once
#include "Include.h"


class Monster
{
private:
	Sprite Idle;
	Sprite Attack;
	Sprite Move;
	Sprite Destory;//몹죽을때 폭발연출


	DWORD animTime;//애니메이션 간격
	//애니메이션의 상태와 방향
	int state;
	int direction;

	bool live;

	int x;//몬스터 x좌표
	int y;//몬스터 y좌표

	int cameraX;//카메라x좌표
	int cameraY;//카메라y좌표

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