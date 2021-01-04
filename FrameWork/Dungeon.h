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
	void Update();
	void Draw();
	void DrawRoom0();
	void DrawTile(float,float,int);

private:
	Sprite DungeonAtlas;
	TileNum* tile;
	RoomData* roominfo;
	int cameraX;
	int cameraY;
	int roomnum;
	RECT wall[20];//���� �ٴ�
	RECT RoomZero_World;//������ 0���� �����
};

extern Dungeon dungeon;