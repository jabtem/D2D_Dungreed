#include "Include.h"


Monster monster;



Monster::Monster(void)
{
	LifeTime = GetTickCount64();
	FishCountTime = GetTickCount64();
	FishMoveTime = GetTickCount64();
}

Monster::~Monster(void)
{
}

void Monster::Init()
{

	char FileName[256];

	for(int i = 0; i<15; i++ )
	{
		sprintf_s(FileName, "./resource/Img/Monster/1/fish_001_00%02d.png", i);
		fishimg1[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}
	for(int i = 0; i<30; i++ )
	{
		sprintf_s(FileName, "./resource/Img/Monster/2/fish_002_00%02d.png", i);
		fishimg2[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}

	for(int i = 0; i<26; i++ )
	{
		sprintf_s(FileName, "./resource/Img/Monster/boom/%02d.png", i);
		Boomimg1[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	}

}

void Monster::GoodFunction(double init_x, double init_y, double x, 
						   double y, int score, double speed, 
						   double scale, int pos, double dx, double dy, 
						   double dz, double w, int fishkind, int num)
{
	fish[num].init_x = init_x ;
	fish[num].init_y = init_y;
	fish[num].x = x;
	fish[num].y = y;
	fish[num].life = false;
	fish[num].score = score;

	fish[num].speed = speed;
	fish[num].scale = 0.8;
	fish[num].w = 0;
	fish[num].pos = pos;

	fish[num].dz = 0;
	fish[num].fishkind = fishkind;

	fish[num].drz = 0;
	fish[num].Shot = true;
	fish[num].bulletPX1 = -5;
	fish[num].bulletPY1 = -11;
	fish[num].bulletPX2 = 3;
	fish[num].bulletPY2 = -2;

	if(fish[num].fishkind == 0 && fish[num].pos==RIGHT)
	{
		fish[num].drx = fish[num].dx = init_x - 62.0f ;
		fish[num].dry = fish[num].dy = init_y + 30.0f;

	}
	else if(fish[num].fishkind == 0 && fish[num].pos==LEFT)
	{
		fish[num].drx = fish[num].dx = init_x + 37.0f ;
		fish[num].dry = fish[num].dy = init_y + 30.0f;

	}

	else if(fish[num].fishkind == 1 && fish[num].pos==RIGHT)
	{
		fish[num].drx = fish[num].dx = init_x - 55.0f ;
		fish[num].dry = fish[num].dy = init_y + 22.0f;

	}
	else if(fish[num].fishkind == 1 && fish[num].pos==LEFT)
	{
		fish[num].drx = fish[num].dx = init_x + 30.0f ;
		fish[num].dry = fish[num].dy = init_y + 22.0f;

	}
	else if(fish[num].fishkind == 2 && fish[num].pos==RIGHT)
	{
		fish[num].drx = fish[num].dx = init_x - 62.0f ;
		fish[num].dry = fish[num].dy = init_y + 35.0f;

	}
	else if(fish[num].fishkind == 2 && fish[num].pos==LEFT)
	{
		fish[num].drx = fish[num].dx = init_x + 37.0f ;
		fish[num].dry = fish[num].dy = init_y + 35.0f;
	}

}


void Monster::Reset()
{


	GoodFunction(2480, 220, 2480, 220, 50, 10, 3, LEFT, 30.0f, 50.0f, 0, 0, A_, 0);
	GoodFunction(-600, 580, -600, 580, 100, 5, 3, RIGHT, 40.0f, 30.0f, 0, 100.0f, B_, 1);

	m_FishLifeSelect = 0;

}
void Monster::Update()
{


	if(Gmanager.m_GameStart==true)
	{

		if(GetTickCount64() - LifeTime > 100)
		{
			for (m_FishLifeSelect = 0; m_FishLifeSelect < 2; m_FishLifeSelect++)
			{
				if (fish[m_FishLifeSelect].life == false)
				{
					fish[m_FishLifeSelect].life = true;
					
				}
				
			}
			m_FishLifeSelect = 0;
			LifeTime = GetTickCount64();
		}


	
		if(GetTickCount64() - FishMoveTime > 20)
		{
			for(int i=0; i<2; i++)
			{
				if(fish[i].pos == LEFT && fish[i].life == true )		// 오른쪽에서 왼쪽으로 가면!  x를 - 시켜야지
				{ fish[i].init_x -= fish[i].speed; fish[i].dx -= fish[i].speed;}
				else if(fish[i].pos == RIGHT && fish[i].life == true )
				{ fish[i].init_x += fish[i].speed;  fish[i].dx +=fish[i].speed;}
			
			}

			FishMoveTime = GetTickCount64();
		}



	
	
	for(int i=0; i<2; i++)
	{

		if(fish[i].life == true)
		{
			if(fish[i].pos == LEFT && fish[i].init_x < -200)
			{
				fish[i].life = false;
				fish[i].init_x = fish[i].x;
				fish[i].init_y = fish[i].y;

				fish[i].dx = fish[i].drx;
				fish[i].dy = fish[i].dry;

				fish[i].Shot=true;
			}
			else if(fish[i].pos == RIGHT && fish[i].init_x > 1548)
			{
				fish[i].life = false;
				fish[i].init_x = fish[i].x;
				fish[i].init_y = fish[i].y;

				fish[i].dx = fish[i].drx;
				fish[i].dy = fish[i].dry;

				fish[i].Shot=true;

			}
			else if(fish[i].pos == UP && fish[i].init_y < 0)
			{
				fish[i].life = false;
				fish[i].init_x = fish[i].x;
				fish[i].init_y = fish[i].y;

				fish[i].dx = fish[i].drx;
				fish[i].dy = fish[i].dry;

				fish[i].Shot=true;
			}
			else if(fish[i].pos == DOWN && fish[i].init_y > 768)
			{
				fish[i].life = false;
				fish[i].init_x = fish[i].x;
				fish[i].init_y = fish[i].y;

				fish[i].dx = fish[i].drx;
				fish[i].dy = fish[i].dry;

				fish[i].Shot=true;
			}
		}


	}
	if(GetTickCount64() - FishCountTime > 50)
	{
		m_Acount++;
		m_Bcount++;

		m_Bulletcount++;

		if(m_Acount > 14)  m_Acount = 0;
		if(m_Bcount > 29) m_Bcount = 0;

		if(m_Bulletcount > 20) m_Bulletcount = 0;
		FishCountTime = GetTickCount64();
	}

	 Boom();


	 if (m_Boom1 == true)
	 {
		 if (GetTickCount64() - BoomTime1 > 50)
		 {
			 m_BoomCount1++;
			 if (m_BoomCount1>25) { m_BoomCount1 = 0; m_Boom1 = false; }
			 BoomTime1 = GetTickCount64();
		 }
	 }


	}
}

void Monster::Boom()
{
	for(int i=0; i<2; i++)
	{
		if(fish[i].life == true && target.m_Life == true)
		{

			float distance = (float) sqrt( (target.m_Target.dx -fish[i].dx ) * (target.m_Target.dx -fish[i].dx ) + 
								 (target.m_Target.dy -fish[i].dy ) * (target.m_Target.dy -fish[i].dy ) );
			if(distance < 40 )
			{
		

				fish[i].life = false;
				fish[i].Shot=true;  
				m_Boom1 = true;

				m_BoomX1 = target.m_W - 30;
				m_BoomY1 = target.m_H - 30;
			//	sound.m_EDie->Play(NULL);
			}
		}
	}
		//if(target.m_Life == true)
		//target.m_Life = false;
}



void Monster::Draw()
{
	//fishimg1[m_Acount].SetColor(255, 255, 255, 255); 안먹힘
	//fishimg1[m_Acount].Render(300+(137*5), 100, D3DX_PI/180, -5, 5); // 반전시 이미지 크기 만큼 이동

	if (Gmanager.m_GameStart == true)
	{
		if (m_Boom1 == true)
		{
			Boomimg1[m_BoomCount1].Render(m_BoomX1, m_BoomY1, 0, 1.5, 1.5);

		}

		for (int i = 0; i < 2; i++)
		{
			if (fish[i].life == true)
			{
				m_Left = fish[i].dx;
				m_High = fish[i].dy;

				if (fish[i].pos == LEFT)
				{

					if (fish[i].fishkind == A_) fishimg1[m_Acount].Render(
						fish[i].init_x, fish[i].init_y, 0, fish[i].scale, fish[i].scale);

					if (fish[i].fishkind == B_) fishimg2[m_Bcount].Render(
						fish[i].init_x, fish[i].init_y, 0, fish[i].scale, fish[i].scale);

				}
				if (fish[i].pos == RIGHT)
				{

					if (fish[i].fishkind == A_) fishimg1[m_Acount].Render(
						fish[i].init_x + fish[i].w, fish[i].init_y, 0, -fish[i].scale, fish[i].scale);

					if (fish[i].fishkind == B_) fishimg2[m_Bcount].Render(
						fish[i].init_x + fish[i].w, fish[i].init_y, 0, -fish[i].scale, fish[i].scale);

				}

				if (Gmanager.m_Collision == true)
				{
					for (int i = 0; i < 2; i++)
					{
						if (fish[i].life == true)
						{

							float distance = (float)sqrt((target.m_Target.dx - fish[i].dx) * (target.m_Target.dx - fish[i].dx) +
								(target.m_Target.dy - fish[i].dy) * (target.m_Target.dy - fish[i].dy));
							if (distance < 40)
							{

								SetRect(&m_rc, m_Left, m_High, m_Left + 150, m_High + 150);
								dv_font.Fonts->DrawTextA(NULL, "중", -1, &m_rc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));

							}

						}

					}
				}



			}



		}

	}
}

