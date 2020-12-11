#pragma once
class WeaponManager;
/* ---------------------------------------------------
///////////////// 프로그램 파일 //////////////////////

		라이브러리에 필요한 파일입니다.
		지우면 안돼요~~^^;

//////////////////////////////////////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")

// 데이타 베이스///////////////////
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

#include "Time.h"
#include <profileapi.h> //델타타임용헤더

/* ---------------------------------------------------
///////////////// 사용자 추가 파일 ///////////////////

		새로 클래스 만들 때 마다
		헤더파일을 추가해 주세요~

//////////////////////////////////////////////////////
-----------------------------------------------------*/
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"
#include "Key.h"
#include "GameManager.h"

#include "CollisionManager.h"
#include <list>
#include "Monster.h"
#include "Sound.h"
#include "Town.h"
#include "Target.h"
#include "Charactor.h"
#include "Enum.h"
#include "Camera.h"
#include <cmath>


// 무기
#include "Weapon.h"

// 데이타 베이스///////////////////
#include "Mysql.h"

/* ---------------------------------------------------
///////////////// 사용자 추가 파일 ///////////////////

		키 입력 처리 함수입니다.

//////////////////////////////////////////////////////
-----------------------------------------------------*/

inline int KeyDown	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 1:0 ); //키보드 눌렸을때
}

inline int KeyUp	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 0:1); 
}