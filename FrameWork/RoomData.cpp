
//던전의 각각 방에대한정보를가진 클래스
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

//해당하는 던전룸의 가로 세로 크기를 반환
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