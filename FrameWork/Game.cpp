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
	//monster.Init();

	Gmanager.Init();
	// 데이타 베이스///////////////////
	//sql.Init();
}

void Game::Draw()
{
	town.Draw();
	//monster.Draw();

	weapon.Draw();
	character.Draw();
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
		character.Update();
		weapon.Update();
		camera.Update();
		//monster.Update();
		// 입 맛에 맞게
		town.Update(100);

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