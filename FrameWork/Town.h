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

	Sprite DungeonEat;//던전입구 X:480 Y:360씩자름

	RECT Town_World;


	//사운드
	bool isTownBGMON;
	bool isOpenSound;
	bool isCloseSound;

	//던전입구애니메이션
	float next_dungeonEat;
	bool doorOpen;//던전입구출력여부 캐릭터의 월드좌표가 3865~ 3865+780범위내일경우 호출
	bool doorAni;//던전입구 애니메이션 스타트
	DWORD curtime;

	//좌표관련
	int cameraX;
	int cameraY;
	int playerX;
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

	//사각형좌표
	RECT town_RecT[20];//RECT충돌영역배열

	//선좌표
	Line town_Line[20];//LINE충돌영역배열

	//std::list<RECT> town_RecT;
public :
	Town();
	~Town();





	
	double skyY;


	void Init();
	void Update(double frame);
	void Draw();
	void Reset();
	void SetPos(Position&p,int, int, int, int);
	void SetLine(Line& l, int, int, int, int);

	double& GetSkyY();
};

extern Town town;