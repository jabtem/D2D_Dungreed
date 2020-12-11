#pragma once
#include "Include.h"

class Collision
{
public:
	Collision();
	~Collision();
	void Coll_Character_Map(RECT,RECT);//�簢���浹�˻�
	void Coll_Camera_Character(RECT, RECT);
	bool& Get_TBCol();
	bool& Get_Trigger();
	bool Get_LineCol();

	bool Line_Line(float, float, float, float, float, float, float, float);//���� �� �浹
	void Line_RECT(Line, RECT);//���� �簢���浹
private:
	RECT rcTemp;//�ӽ�
	bool isTBCol;//���Ʒ��浹����
	bool isLRCol;//�¿��浹����
	bool isLineCol;//���浹����
	bool trigger;//�ϴ����������� Ʈ���ź���
	int triggercnt;
	float intersectionX;//������ x��ǥ���庯��
	float intersectionY;//������ y��ǥ���庯��

	//float left_intersectionX;//�簢���� ���ʸ�� �� �浹�� ���� ���庯��
	//float left_intersectionY;

	//float right_intersectionX;//�簢���� �����ʸ�� �� �浹�� ���� ���庯��
	//float right_intersectionY;
};

extern Collision collision;