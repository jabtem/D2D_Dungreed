#pragma once
#include "Include.h"
#include <string>
#include "fmod/inc/fmod.hpp"
#pragma comment (lib,"fmod/lib/fmodex64_vc.lib")

using namespace FMOD;

#include <map>


class SoundManager
{
private:
	System* m_pSystem;//�������
	System* m_pSystem2;//ȿ������
	int m_Index;
	Channel* m_pBGChannel;
	float m_volum;

	//�����
	int MenuBGM;//�޴������
	int TownBGM;//���������
	int DungeonBGM;//���������


	//ȿ����
	int ssWEffect;//���ҵ� ȿ����
	int dungeonOpen;
	int dungeonClose;
	bool isEffectPlay;

public:
	//����Ʈä�� Ȯ�ο�
	Channel* test;

	std::map<std::string, int> m_CheckList;
	std::map<int, Sound*> m_SoundList;
	SoundManager();
	~SoundManager();
	void Init();
	int Get_BGM(int);
	int Get_Effect(int);
	int AddSoundFile(std::string _fullpath, bool  _IsLoop);
	int AddEffectFile(std::string _fullpath, bool  _IsLoop);

	void EffectPlay(int _SoundNum);
	void BGPlay(int _SoundNum);
	void BGMChange(int _SoundNum);
	void BGStop();
	void SoundPlay(int _SoundNUm);
	void  VolumDown();
	void  VolumUp();
	void BGReset();

	Channel* Get_Test();
};
extern SoundManager sound;