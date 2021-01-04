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
				character.Reset(200, 400);
				break;
			case DUNGEON:
				//현재 맵이 던전일경우 마을로이동
				MapState = TOWN;
				character.Reset(0, 400);
				break;
			}
			//맵교체가 끝나면 키잠금비활성, 카메라초기화
			key.Set_inputOk(true);
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
			dungeon.Update();
			break;
		}
		
		
		weapon.Update();
		camera.Update();
		character.Update();

	
		
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