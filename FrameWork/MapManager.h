#pragma once
#include "Include.h"
//맵교체 관리용 클래스
class MapManager
{
public:
	MapManager();
	~MapManager();
	void Set_isMApChange(bool);
	bool Get_isMapChange();

private:
	bool isMapChange;//맵교체가 이뤄졌는지 여부
};
extern MapManager map;
