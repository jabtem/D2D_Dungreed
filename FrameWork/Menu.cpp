#include "Include.h"

static DWORD KeyTime = GetTickCount();

Menu::Menu()
{
	mx = 0;
	mx2 = 0;
	SoundOn = false;
	cursorOnPlay = false;
	cursorOnExit = false;
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
	char FileName[256];
	//���۹�ư
	sprintf_s(FileName, "./resources/Images/MainScene/PlayOn_Kor.png");
	PlayOn.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resources/Images/MainScene/PlayOff_Kor.png");
	PlayOff.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	//�����ư
	sprintf_s(FileName, "./resources/Images/MainScene/ExitOn_Kor.png");
	ExitOn.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resources/Images/MainScene/ExitOff_Kor.png");
	ExitOff.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

// Chap, ������ �Լ� ȣ��
void Menu::Update(double frame)
{
	if (!SoundOn)//�ѹ��� ȣ��
	{
		int MBGM = sound.Get_BGM(MENUBGM);
		sound.BGPlay(MBGM);
		SoundOn = true;
	}
	mouseP = mouse.Get_MousePoint();//���콺������ ��ġ
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
	CheckPlayOn();
	CheckExitOn();


	if (mouse.Get_isLclick())
	{
		mouse.Set_isLclik(false);//���콺Ŭ���� �ѹ����ν��ϵ���

		if(cursorOnPlay)
			g_Mng.n_Chap = GAME;
		if (cursorOnExit)
			PostQuitMessage(0);

		
	}

}

void Menu::Draw()
{


	//683-72
	menuimg2.Render(mx2, 0, 0, 1.0, 1.0); //�̹������
	menuimg2.Render(-2816+mx2, 0, 0, 1.0, 1.0); //�̹������
	menuimg1.Render(mx, 0, 0, 1.0, 1.0); //�̹������
	menuimg1.Render(mx+2530, 0, 0, 1.0, 1.0); //�̹������
	menuimg.Render(350, 80, 0, 1.0, 1.0); //�̹������

	SetRect(&playRect, 583, 500, 783, 548);//��ŸƮ��ư �νĹ���
	if (!cursorOnPlay)
		PlayOn.Render(683 - 72, 500, 0, 1, 1);
	else if(cursorOnPlay)
		PlayOff.Render(683 - 72, 500, 0, 1, 1);

	SetRect(&exitRect, 583, 600, 783, 648);//�����ư �νĹ���
	if (!cursorOnExit)
		ExitOn.Render(683 - 42, 600, 0, 1, 1);
	if (cursorOnExit)
		ExitOff.Render(683 - 42, 600, 0, 1, 1);
	mouse.Draw();

}

void Menu::OnMessage(MSG* msg)
{

	switch (msg->message)
	{
	//case WM_KEYDOWN:
	//	switch (msg->wParam) {
	//	case VK_F2:
	//		if (g_Mng.n_Chap == MENU) {

	//			g_Mng.n_Chap = GAME;

	//		}
	//		break;
	//	}
		
	}

}

//���콺Ŀ���� �÷��̹�ư �νĹ����� ��Ҵ��� üũ�ϴ��Լ�
void Menu::CheckPlayOn()
{
	if (mouseP.x >= playRect.left && mouseP.x <= playRect.right && mouseP.y >= playRect.top && mouseP.y <= playRect.bottom)
		cursorOnPlay = true;
	else
		cursorOnPlay = false;
}

//���콺Ŀ���� �����ư �νĹ����� ��Ҵ��� üũ�ϴ� �Լ�
void Menu::CheckExitOn()
{
	if (mouseP.x >= exitRect.left && mouseP.x <= exitRect.right && mouseP.y >= exitRect.top && mouseP.y <= exitRect.bottom)
		cursorOnExit = true;
	else
		cursorOnExit = false;
}