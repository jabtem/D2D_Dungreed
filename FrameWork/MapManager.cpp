#include "Include.h"
MapManager map;
MapManager::MapManager()
{
	isMapChange = false;//맵교체가 일어날때만 true로변경
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