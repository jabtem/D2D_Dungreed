#pragma once
//�̹����� Ÿ�ϸ�ó�� �����ϱ����� Ŭ����
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
