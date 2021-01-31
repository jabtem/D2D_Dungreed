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
	dungeon.init();
	character.Init();
	weapon.init();
	Emanager.Init();
	
	monster.Init();

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
				//���� ���� �����ϰ�� �������� �̵��� 
				MapState = DUNGEON;
				character.Reset(200, 500);
				break;
			case DUNGEON:
				//���� ���� �����ϰ�� �������̵�
				MapState = TOWN;
				character.Reset(0, 400);
				break;
			}
			//�ʱ�ü�� ������ Ű��ݺ�Ȱ��, ī�޶��ʱ�ȭ
			key.Set_inputOk(true);
			mouse.Set_clickOk(true);
			camera.Cam_Reset();
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