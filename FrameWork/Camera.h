#pragma once
#include "Include.h"
class Camera
{
public:
	Camera();
	~Camera();
	void CamCheck(RECT, RECT);
	void followCam(RECT, RECT, RECT);
	void Set_CameraX(int);

	int Get_CameraX();
	int Get_CameraY();
	RECT Get_CameraRect();
	bool Get_CanFollow();
	bool Get_Rlimit();
	bool Get_Llimit();
	bool Get_CamLock();
	void Update();

	int plcl;
	int pl;
	int cl;

	int ptct;
	int pt;
	int ct;

private:
	RECT CameraRect;
	RECT worldRect;
	int cameraX;
	int cameraY;
	bool CMoveX;//ī�޶�x�̵����ɿ���
	bool CanFollow;//ī�޶󿵿� �̵����ɿ���
	bool LeftLimit;
	bool RightLimit;
	bool cameraLock;
	DWORD upTime;
};

extern Camera camera;