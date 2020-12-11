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

	RECT Town_World;

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
	double gMoveCnt;//����Ÿ�� �̵�Ƚ��

	//std::list<RECT> town_RecT;
public :
	Town();
	~Town();

	//RECT plat_RecT;
	//RECT ground_RecT;
	RECT town_RecT[20];

	//����ǥ
	Line town_Line[20];


	
	double skyY;


	void Init();
	void Update(double frame);
	void Draw();
	void SetPos(Position&p,int, int, int, int);
	void SetLine(Line& l, int, int, int, int);

	double& GetSkyY();
};

extern Town town;