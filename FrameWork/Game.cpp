#include "Include.h"
Game::Game()
{
	
}

Game::~Game()
{
}

void Game::Init()
{
	MapState = TOWN;//기본적으로 마을에서 시작하도록
	deltaTime.Reset();
	town.Init();
	dungeon.init();
	character.Init();
	weapon.init();
	Emanager.Init();
	
	monster.Init();

	Gmanager.Init();
	// 데이타 베이스///////////////////
	//sql.Init();
}

void Game::Draw()
{


	switch (MapState)
	{
	case TOWN:
		town.Draw();
		break;
	case DUNGEON:
		dungeon.Draw();
		break;
	}
	weapon.Draw();
	character.Draw();
	mouse.Draw();
	Emanager.Draw();
	Gmanager.Draw();


}

void Game::Update(double frame)
{
	static DWORD time = 0;

	if (GetTickCount64() - time > frame)
	{

		if (map.Get_isMapChange())
		{
			switch (MapState)
			{
			case TOWN:
				//현재 맵이 마을일경우 던전으로 이동됨 
				MapState = DUNGEON;
				character.Reset(200, 500);
				break;
			case DUNGEON:
				//현재 맵이 던전일경우 마을로이동
				MapState = TOWN;
				character.Reset(0, 400);
				break;
			}
			//맵교체가 끝나면 키잠금비활성, 카메라초기화
			key.Set_inputOk(true);
			mouse.Set_clickOk(true);
			camera.Cam_Reset();
			map.Set_isMApChange(false);//맵교체가 한번이뤄졋으므로 상태복구
		}

		deltaTime.Update();
		
		key.Update();
		switch (MapState)
		{
		case TOWN:
			town.Update(100);
			break;
		case DUNGEON:
			dungeon.Update(frame);
			break;
		}
		
		
		weapon.Update();
		camera.Update();
		character.Update();

	
		
		monster.Update();

		Emanager.Update();
		Gmanager.Update();

		time = GetTickCount64();

	}
	

}


void Game::OnMessage( MSG* msg )
{

}

void Game::Set_MapState(int _Map)
{
	MapState = _Map;
}