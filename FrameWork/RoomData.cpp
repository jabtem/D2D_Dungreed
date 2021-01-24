
//던전의 각각 방에대한정보를가진 클래스
#include "Include.h"
RoomData::RoomData()
{
}

RoomData::~RoomData()
{
}

const int RoomData::Get_Room(int row, int col, int roomNum)
{
	switch (roomNum)
	{
	case 0:
		return Room0[row][col];
		break;
	case 1:
		return Room1[row][col];
		break;
	case 2:
		return Room2[row][col];
		break;
	}
	
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
	case 1:
		size.col = sizeof(Room1[0]) / sizeof(int);
		size.row = sizeof(Room1) / sizeof(Room1[0]);
		return size;
		break;
	case 2:
		size.col = sizeof(Room2[0]) / sizeof(int);
		size.row = sizeof(Room2) / sizeof(Room2[0]);
		return size;
		break;
	}
}