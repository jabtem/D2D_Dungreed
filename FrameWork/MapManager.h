#pragma once
#include "Include.h"
//�ʱ�ü ������ Ŭ����
class MapManager
{
public:
	MapManager();
	~MapManager();
	void Set_isMApChange(bool);
	bool Get_isMapChange();

private:
	bool isMapChange;//�ʱ�ü�� �̷������� ����
};
extern MapManager map;
