#include "Include.h"
MapManager map;
MapManager::MapManager()
{
	isMapChange = false;//�ʱ�ü�� �Ͼ���� true�κ���
}

MapManager::~MapManager()
{
}

void MapManager::Set_isMApChange(bool _TF)
{
	isMapChange = _TF;
}
bool MapManager::Get_isMapChange()
{
	return isMapChange;
}