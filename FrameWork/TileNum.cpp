#include "Include.h"
#include "TileNum.h"
TileNum::TileNum(int len, int w)
{
	arr = new POINT[len];
	this->length = len;
	this->width = w;
	Reset();
	SetData();
}

TileNum::~TileNum()
{
	delete[]arr;
}

void TileNum::Reset()
{
	for (int i = 0; i < length;++i)
	{
		arr[i].x = 0;
		arr[i].y = 0;
	}
}
void TileNum::SetData()
{
	countX = 0;
	countY = 0;
	for (int i = 0;i < length;++i)
	{
		arr[i].x = countX;
		arr[i].y = countY;
		++countX;//���� 1������
		if (countX == width)
		{
			++countY;//���� ������ ũ�⸸ŭĿ���� ����������Ű�� �����ʱ�ȭ
			countX = 0;
		}
	}
}
int TileNum::Get_itemX(int i)
{
	return arr[i].x;
}
int TileNum::Get_itemY(int i)
{
	return arr[i].y;
}