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
	//monster.Init();

	Gmanager.Init();
	// ����Ÿ ���̽�///////////////////
	//sql.Init();
}

void Game::Draw()
{
	town.Draw();
	//monster.Draw();

	weapon.Draw();
	character.Draw();
	Emanager.Draw();
	Gmanager.Draw();

	// ����Ÿ ���̽�///////////////////
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
		// �� ���� �°�
		town.Update(100);
		Emanager.Update();
		Gmanager.Update();
		// ����Ÿ ���̽�///////////////////
		// �� ���� �°� (���⼱ �Ⱦ���..������ ���� �ʿ� �Ҷ���.. �׳� �����...)
		//sql.Update(frame+3000);

		time = GetTickCount64();
	}
	

}


void Game::OnMessage( MSG* msg )
{

}