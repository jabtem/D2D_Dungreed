#include "Include.h"

Key key;

Key::Key(void)
{
	isADown = false;//AŰ ���ȴ��� ����
	isDDown = false;//DŰ ���ȴ��� ����
	isSDown = false;//SŰ ���ȴ��� ����
}

Key::~Key(void)
{
}


void Key::Update()
{
	// �ý��ۿ� ����...GetTickCount/GetTickCount64
	if(KeyDown('1'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//map.m_Stage = 1;
			KeyTime = GetTickCount64();
		}
	}

	if(KeyDown('2'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			//map.m_Stage = 2;
			KeyTime = GetTickCount64();
		}
		
	}

	if(KeyDown('3'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			Gmanager.m_Collision = true;
			KeyTime = GetTickCount64();
		}
		
	}
	
	if(KeyDown('4'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			monster.Reset();
			KeyTime = GetTickCount64();
		}
		
	}

	if(KeyDown('5'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	
	}
	
	if(KeyDown('6'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}



	if(KeyDown('7'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
		
	}


	if(KeyDown('8'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

		}
		
	}

	if(KeyDown('9'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
		
	}


	if(KeyDown('0'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
		
	}






	if(KeyDown(VK_F1))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F2))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F3))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F4))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F5))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F6))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F7))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
		
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F8))
	{
		if(GetTickCount64() - KeyTime > 200)
		{		
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F9))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F10))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F11))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F12))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	






	if(KeyDown(VK_LEFT))
	{
		if(GetTickCount64() - KeyTime1 > 10)
		{
			KeyTime1 = GetTickCount64();
		}
	}

	if(KeyDown(VK_RIGHT))
	{
		if(GetTickCount64() - KeyTime1 > 10)
		{

			KeyTime1 = GetTickCount64();
		}
		
	}
	
	if(KeyDown(VK_UP))
	{
		if(GetTickCount64() - KeyTime3 > 10)
		{	

			KeyTime3 = GetTickCount64();
		}
		
	}

	if(KeyDown(VK_DOWN))
	{

		if(GetTickCount64() - KeyTime3 > 10)
		{
		

			KeyTime3 = GetTickCount64();
		}
		
	}


	if(KeyDown('C') )
	{
		if(GetTickCount64() - KeyTime1 > 200)
		{	
			KeyTime1 = GetTickCount64();
		}
	}




	
	if(KeyDown('N'))
	{
		
		if(GetTickCount64() - KeyTime > 200)
		{			
			KeyTime = GetTickCount64();
		}
	}

	




#pragma region ����Ű
	if(KeyDown('W') )
	{
		if(GetTickCount64() - KeyTime > 10)
		{
			KeyTime = GetTickCount64();
		}

	}
	if (KeyDown('A')&&!isSDown)//�����̵�
	{
		isADown = true;
		//character.Set_Direction(Left);
		if (!character.Get_IsJump())
			character.Set_Sate(Move);
		else
			character.Set_Sate(Jump);
		if (GetTickCount64() - KeyTime > 10)
		{
			if (Gmanager.m_GameStart == true)
			{
				character.MoveLeft();
			}

			KeyTime = GetTickCount64();
		}
	}
	else if (KeyUp('A') && isADown)//AŰ�� �������� ����
	{
		character.Set_Sate(Idle);
		isADown = false;
		KeyTime = GetTickCount64();
	}

	if (KeyDown('S'))
	{
		isSDown = true;
		if (KeyDown(VK_SPACE)&&!collision.Get_TBCol())
		{
			collision.Get_Trigger() = true;
			character.Set_Sate(Jump);
		}

		if (GetTickCount64() - KeyTime > 10)
		{

			KeyTime = GetTickCount64();
		}
	}
	else if (KeyUp('S') && isSDown)//DŰ�� �������� ����
	{
		isSDown = false;
		KeyTime = GetTickCount64();
	}

	if (KeyDown('D')&&!isADown)//�������̵�
	{
		isDDown = true;
		//character.Set_Direction(Right);
		if (!character.Get_IsJump())
			character.Set_Sate(Move);
		else
			character.Set_Sate(Jump);
		if (GetTickCount64() - KeyTime > 10)
		{

			if (Gmanager.m_GameStart == true )
			{
				character.MoveRight();
			}
			KeyTime = GetTickCount64();
		}
	}
	else if (KeyUp('D') && isDDown)//DŰ�� �������� ����
	{
		character.Set_Sate(Idle);
		isDDown = false;
		KeyTime = GetTickCount64();
	}

	if (KeyDown(VK_SPACE) &&!isSDown)//����
	{

		if (GetTickCount64() - KeyTime2 > 200)
		{
			if (Gmanager.m_GameStart == true)
			{
				character.Set_Sate(Jump);
			}

			KeyTime2 = GetTickCount64();
		}

	}
#pragma endregion


	if(KeyDown('E')  )
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
		
	}


	if(KeyDown('R') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}

	if(KeyDown(VK_RETURN) ) 
	{
		
		if(GetTickCount64() - KeyTime1 > 200)
		{

			KeyTime1 = GetTickCount64();
		}
		
	}


}

bool& Key::Get_isSDown()
{
	return isSDown;
}