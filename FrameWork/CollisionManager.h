#pragma once
#include "Include.h"

class Collision
{
public:
	Collision();
	~Collision();
	void Coll_Character_Map(RECT,RECT);//ĳ���Ϳ� �ʻ������浹�˻�(�����浹)
	bool& Get_TBCol();
	bool& Get_Trigger();
	bool Get_LineCol();
	bool Get_isRoomChange();
	void Set_isRoomChange(bool);
	void Coll_Character_MoveZone(RECT, RECT);//AABB�浹 ĳ���Ϳ� ������ ������������ �浹����Ȯ��
	bool Line_Line(float, float, float, float, float, float, float, float);//���� �� �浹
	void Line_RECT(Line, RECT);//���� �簢���浹
	RECT Get_MoveZone();

	bool col;
private:
	RECT rcTemp;//�ӽ�
	RECT moveZone;
	bool isTBCol;//���Ʒ��浹����
	bool isRoomChange;
	bool isLRCol;//�¿��浹����
	bool isLineCol;//���浹����
	bool trigger;//�ϴ����������� Ʈ���ź���

	bool isMoveCol;//�̵����� �浹
	int triggercnt;//�����ð��� Ʈ��������
	float intersectionX;//������ x��ǥ���庯��
	float intersectionY;//������ y��ǥ���庯��

	//float left_intersectionX;//�簢���� ���ʸ�� �� �浹�� ���� ���庯��
	//float left_intersectionY;

	//float right_intersectionX;//�簢���� �����ʸ�� �� �浹�� ���� ���庯��
	//float right_intersectionY;
};

extern Collision collision;