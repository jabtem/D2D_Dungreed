#pragma once
#include "Include.h"

enum Charactor_Animation { Idle, Move, Jump, Die };
enum Enemy_Animation { EIdle, EMove, EAttack, EDie };
enum Direction{Top, Down, Left, Right};
enum EquipWeapon{Ssw};

enum gamechap
{
	LOGO = 0,
	MENU = 1,
	GAME = 2,
	OVER = 3,
	TOTALCHAP
};

enum alphabet
{
	A_, B_, C_, D_, E_, F_, G_, H_, I_, J_, K_, L_
};
enum gamework
{
	INIT = 0,
	WORK = 1,
	DRAW = 2
};

//배경음
enum BGM
{
	MENUBGM,//메뉴
	TOWNBGM, //마을
	DUNGEONBGM //던전
};

//효과음
enum EFFECT
{
	SSWSWING,//숏소드 휘두르는효과음
	DUNOPEN,//던전열림
	DUNCLOSE//던전닫힘
};

//맵정보
enum MAP
{
	TOWN,
	DUNGEON
};