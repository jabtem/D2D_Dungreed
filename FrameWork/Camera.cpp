#include "Include.h"

Camera camera;

Camera::Camera()
{
	//SetRect(&CameraRect, cameraX, 0, 1366 + cameraX, 768);
	cameraX = 0;
	cameraY = 0;
	cameraLock = true;
}

Camera::~Camera()
{
}

void Camera::Update()
{
	SetRect(&CameraRect, cameraX, cameraY, 1366 + cameraX, 768+cameraY);//ȭ����ü�� �������� ��
}

//ī�޶� ��������

//void Camera::CamCheck(RECT w, RECT c, RECT p)
//{
//	//���念���� ī�޶� ���� ������ �������
//	if (w.left >= c.left)
//	{
//		if ((p.left - c.left) > 685)
//		{
//			LeftLimit = true;
//			cameraLock = false;
//		}
//		else
//		{
//			LeftLimit = true;
//			cameraLock = false;
//		}
//
//
//	}
//
//	//���念���� ī�޶� ���� ������ �������
//	else if (w.right <= c.right)
//		RightLimit = true;
//	else
//	{
//		LeftLimit = false;
//		RightLimit = false;
//	}
//}
//
//void Camera::CamCheck(RECT w, RECT c)
//{
//	//���念���� ī�޶� ���� ������ �������
//	worldRect = w;
//	if (w.left >= c.left)
//	{
//		LeftLimit = true;
//	}
//
//	//���念���� ī�޶� ���� ������ �������
//	else if (w.right <= c.right)
//		RightLimit = true;
//	else 
//	{
//		LeftLimit = false;
//		RightLimit = false;
//	}
//}

//�����ǥī�޶�(ī�޶� ĳ���Ͱ���)
//void Camera::followCam(RECT p, RECT c)
//{
//	//plcl = p.left - c.left;
//	pl = p.left;
//	cl = c.left;
//	plcl = pl - cl;
//
//	pt = p.top;
//	ct = c.top;
//	ptct = pt - ct;
//
//	int direction = character.Get_Direction();
//
//	if(LeftLimit)
//	{
//		if ((p.left-c.left) == 685 && direction ==Right)
//		{
//			cameraLock = false;
//		}
//		else if (direction == Left)
//		{
//			cameraLock = true;
//			cameraX = 0;
//
//		}
//
//	}
//	else if (RightLimit)
//	{
//		if (direction == Right)
//		{
//			cameraX = worldRect.right - 1365;
//			cameraLock = true;
//
//		}
//		else if ((p.left - c.left) == 685 && direction == Left)
//		{
//			
//			cameraLock = false;
//		}
//
//	}
//	if(p.top-c.top<384)
//		cameraY = 384-pt;
//	//else
//	//	cameraY = 0;
//
//	//else
//	//	CMoveX = false;
//
//}


void Camera::followCam(RECT p, RECT c, RECT w)
{
	//plcl = p.left - c.left;	
	pl = p.left;
	cl = c.left;
	plcl = pl - cl;

	pt = p.top;
	ct = c.top;
	ptct = pt - ct;

	cameraX = p.left - 685;
	if (cameraX < 0)
		cameraX = 0;
	else if (cameraX > w.right - 1365)
		cameraX = w.right - 1365;



	cameraY = p.top - 384;
	if (cameraY < 0)
		cameraY = 0;
	else if (cameraY >w.bottom - 500)
		cameraY = w.bottom - 500;
	//else
	//	cameraY = 0;

	//else
	//	CMoveX = false;

}

void Camera::Set_CameraX(int _cameraX)
{
	cameraX = _cameraX;
}
int Camera::Get_CameraX()
{
	return cameraX;
}
int Camera::Get_CameraY()
{
	return cameraY;
}
RECT Camera::Get_CameraRect()
{
	return CameraRect;
}

bool Camera::Get_CanFollow()
{
	return CanFollow;
}

bool Camera::Get_Llimit()
{
	return LeftLimit;
}
bool Camera::Get_Rlimit()
{
	return RightLimit;
}
bool Camera::Get_CamLock()
{
	return cameraLock;
}