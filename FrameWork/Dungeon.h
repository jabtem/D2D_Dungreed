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
	float alpha;//���̵��� ���İ�
	float speed;//���̵��� �ӵ�
	Monster mon[3];//���͸� �ִ� 3����������ġ
	bool fight;//���Ϳ� ������������
	Sprite DungeonAtlas;
	Sprite fadeIn;//������ �̵��� ���̵���ȿ���� 
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
	void resetAlpha();//���̵���ȿ�� ��������
	void resetRect();
};

extern Dungeon dungeon;