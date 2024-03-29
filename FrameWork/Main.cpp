//#include <windows.h>
//#include <mmsystem.h>
#include "Include.h" 
const int TICKS_PER_SECOND = 60;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;
int loops;
float interpolation;
// 버퍼 추가
char buffer[128] = {0,0,0,0};
char ch[3] = {0,0,0}; //D  strcat 사용법 틀림 최소 널이 들어갈수 있도록 해줘야함
////////////////////////////////////
LRESULT CALLBACK WndProc( HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASSEX wc ;
	HWND g_hWnd ;
	wc.hInstance = GetModuleHandle( NULL ) ;
	wc.cbSize = sizeof( wc ) ;
	wc.style = CS_CLASSDC ;
	wc.cbClsExtra = NULL ;
	wc.cbWndExtra = NULL ;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH) ;
	wc.hCursor = LoadCursor( wc.hInstance, IDC_ARROW ) ;
	wc.hIcon = LoadIcon( wc.hInstance, IDI_APPLICATION ) ;
	wc.hIconSm = LoadIcon( wc.hInstance, IDI_APPLICATION ) ;
	wc.lpfnWndProc = WndProc ;
	wc.lpszClassName ="Game" ;
	wc.lpszMenuName = NULL ;

	RegisterClassEx( &wc ) ;

	RECT rt = {0, 0, SCREEN_WITH, SCREEN_HEIGHT};
	int W = rt.right - rt.left;
	int H = rt.bottom - rt.top;
	int X = (GetSystemMetrics(SM_CXSCREEN)/2) - SCREEN_WITH/2;
	int Y = ( (GetSystemMetrics(SM_CYSCREEN)/2) - SCREEN_HEIGHT/2 );


	g_hWnd = CreateWindowEx( NULL, wc.lpszClassName, 
		"Dungreed", 
		WS_OVERLAPPEDWINDOW/*WS_EX_TOPMOST | WS_POPUP*/,
		X, Y, W, H,
		NULL, NULL, wc.hInstance, NULL ) ;


	dv_font.Create(g_hWnd) ;


	ShowWindow( g_hWnd, SW_SHOW ) ;
	UpdateWindow( g_hWnd ) ;

	///////////////////////////////////////////////////////////////////
	ZeroMemory(&msg, sizeof(MSG));

	/////////// 챕터 초기화 /////////////////
	g_Mng.chap[LOGO] = new Logo;
	g_Mng.chap[MENU] = new Menu;
	g_Mng.chap[GAME] = new Game;
	g_Mng.chap[OVER] = new Over;
	/////////////////////////////////////////

	//모든챕터 한번 Init
	sound.Init();//사운드 설정
	mouse.Init();//마우스 커서이미지설정
	for(int i=0; i<TOTALCHAP; i++)
		g_Mng.chap[i]->Init();

	while( msg.message != WM_QUIT )
	{
		if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
		{
			if(GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			
			static DWORD next_game_tick = GetTickCount();

			loops = 0;

			while( GetTickCount64() > next_game_tick && loops < MAX_FRAMESKIP) 
			{
				interpolation = float(GetTickCount64() + SKIP_TICKS - next_game_tick ) / float( SKIP_TICKS );
				if(Gmanager.m_Pause == false) g_Mng.chap[g_Mng.n_Chap]->Update(interpolation);
				g_Mng.chap[g_Mng.n_Chap]->OnMessage(&msg);
				next_game_tick += SKIP_TICKS;
				loops++;
			}

			

			dv_font.Device9->BeginScene();
			if (g_Mng.n_Chap == MENU) {
				//배경색변경
				dv_font.Device9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(106, 174, 247), 0, 0);

			}
			else if (g_Mng.n_Chap == GAME)
			{
				dv_font.Device9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(51, 49, 67), 0, 0);
			}
			else
				dv_font.Device9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0, 0);


			g_Mng.chap[g_Mng.n_Chap]->Draw();

			dv_font.Device9->EndScene();
			dv_font.Device9->Present(NULL, NULL, NULL, NULL);
			
		}
	}

	return msg.wParam;

}

LRESULT CALLBACK WndProc( HWND g_hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch( uMsg )
	{

	case WM_DESTROY:
         PostQuitMessage( 0 );
         return 0;
	case WM_CHAR:
		 ch[0] = wParam;
		 strcat( buffer,ch);
		 // 문자열 위치 가져옴...
		 if (strstr(buffer, "p") != NULL)
		 {

			 if (GetTickCount64() - key.KeyTime > 200)
			 {
				 Gmanager.m_Pause = !Gmanager.m_Pause;

				 key.KeyTime = GetTickCount64();
			 }
		 }

        ZeroMemory( &buffer, sizeof(buffer) );
		break;

		return FALSE;


	case WM_MOUSEMOVE://마우스 움직이면호출
		mouse.Set_MousePoint(LOWORD(lParam), HIWORD(lParam));
		return FALSE;

	/// <좌클릭>
	case WM_LBUTTONDOWN:
		if ((g_Mng.n_Chap == MENU ||g_Mng.n_Chap == GAME)&&mouse.Get_clickOk())//인게임화면일때만 적용
			mouse.Set_isLclik(true);

		return FALSE;
	/// </좌클릭>


	/// <우클릭>
	case WM_RBUTTONDOWN:
		//대쉬 미완성
		//if (g_Mng.n_Chap == GAME)
		//	mouse.Set_isRclick(true);
	/// </summary>
	
	case WM_SETCURSOR:
		SetCursor(NULL);//기본마우스커서 안보이게설정
		break;
	}
	return DefWindowProc( g_hWnd, uMsg, wParam, lParam ) ;
}