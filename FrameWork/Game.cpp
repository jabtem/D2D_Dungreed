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
	character.Init();
	weapon.init();
	Emanager.Init();
	dungeon.init();
	//monster.Init();

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

	//monster.Draw();

	weapon.Draw();
	character.Draw();
	Emanager.Draw();
	Gmanager.Draw();

	// 데이타 베이스///////////////////
	//sql.Draw();
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
				break;
			case DUNGEON:
				MapState = TOWN;
				break;
			}
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
			dungeon.Update();
			break;
		}
		
		character.Update();
		weapon.Update();
		camera.Update();

	
		
		//monster.Update();
		// 입 맛에 맞게

		Emanager.Update();
		Gmanager.Update();
		// 데이타 베이스///////////////////
		// 입 맛에 맞게 (여기선 안쓰임..프레임 값이 필요 할때만.. 그냥 방법만...)
		//sql.Update(frame+3000);

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