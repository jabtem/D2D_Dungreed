#include "Include.h"
#include "TileNum.h"
#include "RoomData.h"

#pragma once
class Dungeon
{
public:
	Dungeon();
	~Dungeon();
	void init();
	void Update(float);
	void Draw();
	void DrawRoom(int);
	void DrawTile(float,float,int);
	void RoomMove();
	bool col;

private:
	float alpha;//페이드인 알파값
	float speed;//페이드인 속도
	Monster mon[3];//몬스터를 최대 3마리까지배치
	bool fight;//몬스터와 전투시작유무
	Sprite DungeonAtlas;
	Sprite fadeIn;//던전룸 이동시 페이드인효과용 
	TileNum* tile;
	RoomData* roominfo;

	//사운드
	bool isDungeonBGMON;

	int preRoomNum;//이전 던전룸위치
	int curRoomNum;
	bool canMove;//던전간 이동가능여부(몬스터 등장시 이동불가로만들기위함)
	int cameraX;
	int cameraY;
	int roomnum;
	RECT wall[10];//벽과 바닥
	RECT moveZone[4];//맵이동영역,0왼쪽,1오른쪽, 2 , 3은 위 아래로 예정 현재는 0번과 1번만 사용하도록함
	RECT RoomZero_World;//던전룸 0번의 월드맵
	RECT RoomOne_World;//던전룸 1번의 월드맵
	RECT RoomTwo_World;//던전룸 2번의 월드맵
	RECT ColZone; //충돌한 이동렉트
	void resetAlpha();//페이드인효과 투명도리셋
	void resetRect();
};

extern Dungeon dungeon;