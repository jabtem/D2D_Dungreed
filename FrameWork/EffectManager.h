#pragma once
#include "Include.h"
class EffectManager
{
public:
	EffectManager();
	~EffectManager();
	void Init();
	void Update();
	void Draw();
	void Set_swingEF(bool);
	void Set_getinfo(bool);
private:
	Sprite swing1;
	int next_swing;
	int weaponNum;
	int PlayerX;
	int PlayerY;
	//radian
	float angleR;
	float angleR2;
	bool getinfo;
	//degree
	float andgleD;
	float andgleD2;

	int CameraX;
	int CameraY;
	int PlayerDirection;
	bool swingEF;//숏소드공격이펙트 출력여부 구분
	DWORD curTime;
};

extern EffectManager Emanager;