#include "Include.h"
EffectManager Emanager;
EffectManager::EffectManager()
{
	next_swing = 0;
	PlayerX = 0;
	PlayerY = 0;
	swingEF = false;
}

EffectManager::~EffectManager()
{
}

void EffectManager::Init()
{
	char FileName[256];
	sprintf_s(FileName, "./resources/images/MeleeWeapon/SwingFX.png");//가로 112 세로 160씩자름
	swing1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void EffectManager::Update()
{
	if (GetTickCount64() - curTime > 100)
	{
		if (swingEF)
		{
			/// <베기효과> 한애니메이션다끝나면 알아서 상태초기화
			//next_swing = 0;
			next_swing += 112;
			if (next_swing - 336 == 0)
			{
				next_swing -= 336;
				swingEF = false;
			}
			/// </베기효과>

		}
		curTime = GetTickCount64();
	}
	weaponNum = character.Get_Curweapon();

	if (mouse.Get_Lclick())//인게임 마우스 클릭이벤트 발생한 시점의 캐릭터 x,y좌표와 방향, 캐릭터와 마우스커서 사이의 각도
	{
		PlayerX = character.Get_PlayerX() + CHARACTER_WIDTH * 0.5;//현재 캐릭터의 가운데좌표
		PlayerY = character.Get_PlayerY() - CHARACTER_HEIGHT * 0.5;
		PlayerDirection = character.Get_Direction();
		angleR = weapon.Get_Angle1();
		angleR2 = weapon.Get_Angle2();
	}
	CameraX = camera.Get_CameraX();
	CameraY = camera.Get_CameraY();

	//캐릭터와 마우스포인터사이의 각도


	andgleD = angleR * -180 / M_PI;//라디안값으로 각도구함
	//andgleD2 = angleR2 * 180 / M_PI;

	//무조건 오른쪽기준 양수좌표로계산
	if (andgleD >= 0)
		andgleD = andgleD;
	else if (andgleD < 0)
		andgleD = 360 + andgleD;

}
//상시로 좌표를받는게아닌 마우스 클릭한 시점의 캐릭터의 x,y값을받아 해당지점에 이펙트를 출력해야함
void EffectManager::Draw()
{
	TCHAR sztext[100];
	sprintf_s(sztext, __TEXT("andgleD : %f"), andgleD);
	dv_font.DrawString(sztext, 1100, 400);


	if (Gmanager.m_GameStart == true) {
		//if (PlayerDirection == Right)//오른쪽
		//{
		if (swingEF)//마우스 클릭될때만 Draw
		{
			float effectDegree;
			if (andgleD < 22.5 || andgleD>337.5)//오른쪽이펙트
			{
				effectDegree = 0;
				swing1.RenderDraw(PlayerX - CameraX, PlayerY - CameraY - 80, next_swing, 0, next_swing + 112, 160, effectDegree, 1.0, 1.0);
			}
			else if (andgleD >= 22.5 && andgleD < 77.5)
			{
				effectDegree = 45 * M_PI / 180;
				swing1.RenderDraw(PlayerX - CameraX - 60, PlayerY - CameraY - 80 + 40, next_swing+1, 0, next_swing + 112, 160, -effectDegree, 1.0, 1.0);
			}

		}

			
		//}
		//else if (PlayerDirection == Left)//왼쪽
		//{
		//	if (swingEF)//마우스 클릭될때만 Draw
		//		swing1.RenderDraw(PlayerX - CameraX, PlayerY - CameraY - 80, next_swing, 0, next_swing + 112, 160, 0, -1.0, 1.0);
		//}
	}

}
void EffectManager::Set_swingEF(bool _TF)
{
	swingEF = _TF;
}