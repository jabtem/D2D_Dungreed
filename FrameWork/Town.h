#pragma once
#include "Include.h"

class Town
{
private : 
	//아틀라스에서 이미지 자를좌표
	Position g1;//땅1번
	Position g2;//땅2번
	Position p1;//플랫폼 1번

	Sprite TownBG_Sky;//하늘 구름
	Sprite TownBG_Mountain;//산
	Sprite TownBG_Tree;//나무

	Sprite Town_Floor;
	Sprite TownAtlas;//타운 타일맵

	RECT Town_World;


	//사운드
	bool isTownBGMON;


	//좌표관련
	int cameraY;

	double floorXpos;
	double floorYpos;

	double floorX;
	double treeX;
	double treeY;
	double mountainX;
	double mountainY;
	double groundX;
	double platformX;

	double gX;
	double gMoveCnt;//지면타일 이동횟수

	//std::list<RECT> town_RecT;
public :
	Town();
	~Town();

	//RECT plat_RecT;
	//RECT ground_RecT;
	RECT town_RecT[20];//RECT충돌영역배열

	//선좌표
	Line town_Line[20];//LINE충돌영역배열


	
	double skyY;


	void Init();
	void Update(double frame);
	void Draw();
	void SetPos(Position&p,int, int, int, int);
	void SetLine(Line& l, int, int, int, int);

	double& GetSkyY();
};

extern Town town;