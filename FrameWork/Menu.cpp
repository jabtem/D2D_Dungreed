#include "Include.h"

static DWORD KeyTime = GetTickCount();

Menu::Menu()
{
	mx = 0;
	mx2 = 0;
	SoundOn = false;
}

Menu::~Menu()
{
}

void Menu::Init()
{
	count = 0;
	alpha = 0;
	menuimg.Create("./resources/Images/MainScene/MainLogo.png", false, D3DCOLOR_XRGB(0, 0, 0));
	menuimg1.Create("./resources/Images/MainScene/FrontCloud.png", false, D3DCOLOR_XRGB(0, 0, 0));
	menuimg2.Create("./resources/Images/MainScene/BackCloud.png", false, D3DCOLOR_XRGB(0, 0, 0));
	BGM = sound.Get_BGM(MENUBGM);

}

// Chap, 재정의 함수 호출
void Menu::Update(double frame)
{
	if (!SoundOn)//한번만 호출
	{
		sound.BGPlay(BGM);
		SoundOn = true;
	}

	//key.Update();
	mx += 1;
	mx2 += 1.5;
	if (mx + 2530 <= 0)
	{
		mx += 2530;
	}

	if (mx2 - 2816 >= 0)
	{
		mx2 -=2816;
	}

	//if (xx.xxx > 100 * xxx.xxx)
	//{
	//	if (GetTickCount() - CoinTime > 100)
	//	{
	//		count++;
	//		CoinTime = GetTickCount();
	//	}
	//	if (count > 1) count = 0;
	//}


}

void Menu::Draw()
{

	menuimg2.Render(mx2, 0, 0, 1.0, 1.0); //이미지출력
	menuimg2.Render(-2816+mx2, 0, 0, 1.0, 1.0); //이미지출력
	menuimg1.Render(mx, 0, 0, 1.0, 1.0); //이미지출력
	menuimg1.Render(mx+2530, 0, 0, 1.0, 1.0); //이미지출력
	menuimg.Render(350, 80, 0, 1.0, 1.0); //이미지출력

}

void Menu::OnMessage(MSG* msg)
{
	//char aaa[256];
	//_itoa_s(msg->message, aaa,2);
	//dv_font.DrawString(aaa, 10 , 210 ) ;   
	//PostQuitMessage(0);

	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F2:
			//MessageBox(NULL, "", "", 0);
			if (g_Mng.n_Chap == MENU) {

				g_Mng.n_Chap = GAME;
				//sound.BGStop();
				//sound.m_Bk1->Play(0, DSBPLAY_LOOPING);

			}
			break;
		}
		
	}

}