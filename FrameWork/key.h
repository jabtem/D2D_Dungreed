#pragma once
#include "Include.h"

class Key
{
private:
	bool isADown;
	bool isDDown;
	bool isSDown;
	bool inputOK;//키보드 입력가능여부

public:
	Key(void);
	~Key(void);
	
	DWORD KeyTime;
	// 동시 키 선택을 위함
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;
	
	bool& Get_isSDown();

	void Update();
	void Set_inputOk(bool);
};

extern Key key;