#pragma once
#include "Include.h"
class newFish
{
private:
	Sprite Nfimg;

public:
	newFish();
	~newFish();

	double m_W;
	double m_H;

	void Init();
	void Update();
	void Draw();
	void Reset();
};

extern newFish newfish;