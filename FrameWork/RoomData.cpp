
//������ ���� �濡�������������� Ŭ����
#include "Include.h"
RoomData::RoomData()
{
}

RoomData::~RoomData()
{
}

const int RoomData::Get_Room0(int row, int col)
{
	return Room0[row][col];
}

//�ش��ϴ� �������� ���� ���� ũ�⸦ ��ȯ
arrSize RoomData::Get_Size(int num)
{
	arrSize size;
	switch (num)
	{
	case 0:
		size.col = sizeof(Room0[0])/sizeof(int);
		size.row = sizeof(Room0) / sizeof(Room0[0]);
		return size;
		break;
	}
}