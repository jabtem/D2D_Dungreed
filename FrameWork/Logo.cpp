#define _CRT_NONSTDC_NO_DEPRECATE

#include "Include.h"

Logo::Logo()
{
	//// 데이타 베이스 관련
	//sql.mysql_Success = false;
	// 데이타 베이스 테스트 관련
	count = 0;
}

Logo::~Logo()
{
}

void Logo::Init()
{
	speed = 1000;
	alpha = 0;

	loadimg.Create("./resources/Images/MainScene/Logo.png", false, D3DCOLOR_XRGB(0, 0, 0));

}

void Logo::Update(double frame)
{
	alpha += speed * frame / 1000;
	if( alpha >= 255 )
	{
		alpha = 255;
		speed = -speed;
		//Draw();
	}
	if(alpha <= 0) {
		 g_Mng.n_Chap = MENU;
	}
	//Sound1.Play(0, DSBPLAY_LOOPING);
	
}

void Logo::Draw()
{
	loadimg.SetColor(255,255,255, alpha);  // 색상 변경
	loadimg.Draw(380,100,0,0.5,0.5);
}

void Logo::OnMessage( MSG* msg )
{
	switch(msg->message)
	{
	//ANY KEY INPUT LOGO SKIP
	case WM_KEYUP:
		if (g_Mng.n_Chap == LOGO ) {

			g_Mng.n_Chap = MENU;

		}
	}
}