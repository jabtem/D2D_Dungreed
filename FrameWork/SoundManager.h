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
	System* m_pSystem;//배경음용
	System* m_pSystem2;//효과음용
	int m_Index;
	Channel* m_pBGChannel;
	float m_volum;

	//배경음
	int MenuBGM;//메뉴배경음
	int TownBGM;//마을배경음
	int DungeonBGM;//던전배경음


	//효과음
	int ssWEffect;//숏소드 효과음
	int dungeonOpen;
	int dungeonClose;
	bool isEffectPlay;

public:
	//이펙트채널 확인용
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