#pragma once
class WeaponManager;
/* ---------------------------------------------------
///////////////// ���α׷� ���� //////////////////////

		���̺귯���� �ʿ��� �����Դϴ�.
		����� �ȵſ�~~^^;

//////////////////////////////////////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")

// ����Ÿ ���̽�///////////////////
//#include <my_global.h>
#include <winsock2.h>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

//////////////////////////////////

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>
#include "DXUTsound.h"
#include "Define.h"
#include "DeviceFont.h"
#include "Sprite.h"
#include "Chap.h"
#include "Enum.h"
#include "Time.h"
#include <profileapi.h> //��ŸŸ�ӿ����

/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		���� Ŭ���� ���� �� ����
		��������� �߰��� �ּ���~

//////////////////////////////////////////////////////
-----------------------------------------------------*/
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"
#include "GameManager.h"
//Ű
#include "Key.h"

//�浹
#include "CollisionManager.h"
#include "Monster.h"

#include "SoundManager.h"
#include "Sound.h"//������

#include "Target.h"
#include "Charactor.h"

#include "Camera.h"
#include <cmath>

#include "Mouse.h"

//��
#include "Town.h"
#include "Dungeon.h"
// ����
#include "Weapon.h"

//����Ʈ
#include "EffectManager.h"

// ����Ÿ ���̽�///////////////////
#include "Mysql.h"

/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		Ű �Է� ó�� �Լ��Դϴ�.

//////////////////////////////////////////////////////
-----------------------------------------------------*/

inline int KeyDown	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 1:0 ); //Ű���� ��������
}

inline int KeyUp	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 0:1); 
}