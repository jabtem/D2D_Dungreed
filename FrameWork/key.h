#pragma once
#include "Include.h"

class Key
{
private:
	bool isADown;
	bool isDDown;
	bool isSDown;

public:
	Key(void);
	~Key(void);
	
	DWORD KeyTime;
	// ���� Ű ������ ����
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;
	
	bool& Get_isSDown();

	void Update();
};

extern Key key;