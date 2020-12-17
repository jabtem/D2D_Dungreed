#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
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
	town.Draw();
	dungeon.Draw();
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
		
		deltaTime.Update();
		
		key.Update();
		
		town.Update(100);
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