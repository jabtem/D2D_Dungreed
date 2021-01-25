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
	void DrawRoom(int);
	void DrawTile(float,float,int);
	void RoomMove();
	bool col;

private:

	Monster mon[3];//���͸� �ִ� 3����������ġ

	Sprite DungeonAtlas;
	TileNum* tile;
	RoomData* roominfo;

	//����
	bool isDungeonBGMON;

	int preRoomNum;//���� ��������ġ
	int curRoomNum;
	bool canMove;//������ �̵����ɿ���(���� ����� �̵��Ұ��θ��������)
	int cameraX;
	int cameraY;
	int roomnum;
	RECT wall[10];//���� �ٴ�
	RECT moveZone[4];//���̵�����,0����,1������, 2 , 3�� �� �Ʒ��� ���� ����� 0���� 1���� ����ϵ�����
	RECT RoomZero_World;//������ 0���� �����
	RECT RoomOne_World;//������ 1���� �����
	RECT RoomTwo_World;//������ 2���� �����
	RECT ColZone; //�浹�� �̵���Ʈ
	void resetRect();
};

extern Dungeon dungeon;