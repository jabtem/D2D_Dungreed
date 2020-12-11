#include "Include.h"


Target target;


Target::Target()
{
	m_W = 600;//초기x좌표
	m_H = 300;//초기 y좌표
	m_Target.dx = 635;
	m_Target.dy = 330;
}

Target::~Target()
{
}

void Target::Init()
{
	char FileName[256];
	
	for(int i = 0; i<2; i++ )
	{
		sprintf_s(FileName, "./resource/Img/taget/%02d.png", i );
		Tgimg[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}
	for(int i = 0; i<4; i++ )
	{
		sprintf_s(FileName, "./resource/Img/bullet/100%02d.png", i);
		Tgimg2[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}

}

void Target::Update()
{


	if(GetTickCount() - AniTime1 > 1000)
	{
		m_TgCount1++;
		if(m_TgCount1>1) m_TgCount1 = 0;
		AniTime1 = GetTickCount();
	}



	if(GetTickCount() - AniTime2 > 100)
	{
		target.m_TgCount2++;
		if(target.m_TgCount2>3) { target.m_TgCount2 = 0; target.m_Life = false;}

			
		AniTime2 = GetTickCount();
	}

}

void Target::Draw()
{
	if(Gmanager.m_GameStart==true) 
		Tgimg[m_TgCount1].Render(m_W, m_H, 0, 0.7, 0.7);

	if(m_Life==true && Gmanager.m_GameStart==true  )
	{
		Tgimg2[m_TgCount2].Render(m_W-20, m_H-20, 0, 1, 1);
	}

	//Collision Detect
	if(Gmanager.m_Collision == true)
	{
		SetRect(&m_rc,m_Target.dx,m_Target.dy,m_Target.dx+150,m_Target.dy+150);
		dv_font.Fonts->DrawTextA(NULL,"충",-1,&m_rc,DT_LEFT,D3DCOLOR_ARGB(255,255,0,0));
	}

}

void Target::Reset()
{
	m_W = 600;
	m_H = 300;
	m_Target.dx = 635;
	m_Target.dy = 330;
}