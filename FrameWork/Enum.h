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

//�����
enum BGM
{
	MENUBGM,//�޴�
	TOWNBGM, //����
	DUNGEONBGM //����
};

//ȿ����
enum EFFECT
{
	SSWSWING,//���ҵ� �ֵθ���ȿ����
	DUNOPEN,//��������
	DUNCLOSE//��������
};

//������
enum MAP
{
	TOWN,
	DUNGEON
};