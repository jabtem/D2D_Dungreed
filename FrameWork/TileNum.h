#pragma once
//�Է��� �迭���ڸ�ŭ �������迭����
class TileNum
{
public:
	//TileNum();
	TileNum(int, int);
	~TileNum();
	void Reset();//�ʱ�ȭ
	void SetData();//������
	int Get_itemX(int);
	int Get_itemY(int);

private:
	POINT* arr;
	int length;
	int width;//�ѹ����� �̹����� ����ĭ��
	int countX;
	int countY;


};
