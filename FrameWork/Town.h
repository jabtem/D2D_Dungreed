#pragma once
#include "Include.h"

class Town
{
private : 
	//��Ʋ�󽺿��� �̹��� �ڸ���ǥ
	Position g1;//��1��
	Position g2;//��2��
	Position p1;//�÷��� 1��

	Sprite TownBG_Sky;//�ϴ� ����
	Sprite TownBG_Mountain;//��
	Sprite TownBG_Tree;//����

	Sprite Town_Floor;
	Sprite TownAtlas;//Ÿ�� Ÿ�ϸ�

	Sprite DungeonEat;//�����Ա� X:480 Y:360���ڸ�

	RECT Town_World;


	//����
	bool isTownBGMON;
	bool isOpenSound;
	bool isCloseSound;

	//�����Ա��ִϸ��̼�
	float next_dungeonEat;
	bool doorOpen;//�����Ա���¿��� ĳ������ ������ǥ�� 3865~ 3865+780�������ϰ�� ȣ��
	bool doorAni;//�����Ա� �ִϸ��̼� ��ŸƮ
	DWORD curtime;

	//��ǥ����
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
	double gMoveCnt;//����Ÿ�� �̵�Ƚ��

	//�簢����ǥ
	RECT town_RecT[20];//RECT�浹�����迭

	//����ǥ
	Line town_Line[20];//LINE�浹�����迭

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