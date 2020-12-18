#include "Include.h"
Game::Game()
{
	
}

Game::~Game()
{
}

void Game::Init()
{
	MapState = TOWN;//�⺻������ �������� �����ϵ���
	deltaTime.Reset();
	town.Init();
	character.Init();
	weapon.init();
	Emanager.Init();
	dungeon.init();
	//monster.Init();

	Gmanager.Init();
	// ����Ÿ ���̽�///////////////////
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

	// ����Ÿ ���̽�///////////////////
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
				//���� ���� �����ϰ�� �������� �̵��� 
				MapState = DUNGEON;
				break;
			case DUNGEON:
				MapState = TOWN;
				break;
			}
			map.Set_isMApChange(false);//�ʱ�ü�� �ѹ��̷���Ƿ� ���º���
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
		// �� ���� �°�

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

void Game::Set_MapState(int _Map)
{
	MapState = _Map;
}