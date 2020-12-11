#include "include.h"

newFish newfish;

newFish::newFish()
{
	m_W = 300;
	m_H = 100;
}
newFish::~newFish()
{
}

void newFish::Init()
{
	char FileName[256];
	int i = 0;
	sprintf_s(FileName, "./resource/Img/newfish/%d.tga", i);
	Nfimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void newFish::Update()
{

}

void newFish::Draw()
{
	if (Gmanager.m_GameStart == true)
		Nfimg.Render(m_W, m_H, 0, 1, 1);
}

void newFish::Reset()
{
	m_W = 300;
	m_H = 100;
}