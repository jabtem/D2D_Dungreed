#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"

GameManager Gmanager;
static DWORD ALPHATime = GetTickCount64();

GameManager::GameManager(void)
{
	GameTime = GetTickCount64();
	m_GameSpeed = 1;
	m_Pause = false;

	m_SysTem.m_Save1 = 100;
	m_SysTem.m_Save2 = 200;
	Save();

	m_GameStart = true;
}

GameManager::~GameManager(void)
{
}

void GameManager::Init()
{
	if ((fp = fopen("./Save/save.fss","rb"))== NULL)
	{
		return ;
	}
	
	fread(&m_SysTem,sizeof(SysTem),1,fp);

	fclose(fp);
	
}

void GameManager::Update()
{
	//if(���� �����) g_Mng.n_Chap = OVER; 
}
void GameManager::Save()
{
	// �ؽ�Ʈ ������ "w" ��
	if ((fp = fopen("./Save/save.fss", "wb")) == NULL)
	{
		return;
	}
	fwrite(&m_SysTem, sizeof(SysTem), 1, fp);
	fclose(fp);

}

void GameManager::Delete()
{
//	sound.g_pSoundManager->drr  

}
 



void GameManager::GameReset(void)  // ����� ���ӻ� ÷�� �ѹ���  �ʱ�ȭ�Ǵ� �κи� �־���.
{

}


void GameManager::Draw()
{

	char show[20];

	
}
