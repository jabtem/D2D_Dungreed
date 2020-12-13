#include "Include.h"
SoundManager sound;
SoundManager::SoundManager()
{
	System_Create(&m_pSystem);
	m_pSystem->init(10, FMOD_INIT_NORMAL, 0);
	m_Index = 0;
	m_volum = 1.0f;
	m_pBGChannel = nullptr;
}
SoundManager::~SoundManager()
{
	m_CheckList.clear();
	for (auto& iter : m_SoundList)
	{
		iter.second->release();
	}
	m_SoundList.clear();
	m_pSystem->release();
	m_pSystem->close();
}
void SoundManager::Init()
{
	MenuBGM = AddSoundFile("./resources/sound/Ui/bgm/title.wav", true);//메뉴배경음악
	TownBGM = AddSoundFile("./resources/sound/Ui/bgm/0.Town.wav", true);//마을배경음악
}

int SoundManager::AddSoundFile(std::string _fullpath, bool  _IsLoop)
{
	auto Find = m_CheckList.find(_fullpath);
	if (Find != m_CheckList.end())
	{
		return Find->second;
	}
	Sound* pSound = nullptr;
	int Mode = FMOD_HARDWARE | (_IsLoop ? FMOD_LOOP_NORMAL | FMOD_DEFAULT : FMOD_LOOP_OFF);
	m_pSystem->createSound(_fullpath.c_str(), Mode, 0, &pSound);
	if (pSound == nullptr)
	{
		return -1;
	}
	m_CheckList.insert(std::make_pair(_fullpath, m_Index));
	m_SoundList.insert(std::make_pair(m_Index, pSound));
	return m_Index++;
}
void SoundManager::EffectPlay(int _SoundNum)
{
	auto Find = m_SoundList.find(_SoundNum);
	Channel* pChannel = nullptr;

	m_pSystem->playSound(FMOD_CHANNEL_FREE, Find->second, 0, &pChannel);
}
void SoundManager::BGPlay(int _SoundNum)
{
	auto Find = m_SoundList.find(_SoundNum);
	m_pSystem->playSound(FMOD_CHANNEL_REUSE, Find->second, 0, &m_pBGChannel);
}
void SoundManager::BGStop()
{
	if (m_pBGChannel != nullptr)
	{
		m_pBGChannel->stop();
	}
}
void  SoundManager::VolumDown()
{
	m_volum -= 0.1f;
	if (m_volum <= 0)
		m_volum = 0;
	m_pBGChannel->setVolume(m_volum);
}
void SoundManager::VolumUp()
{
	m_volum += 0.1f;
	if (m_volum >= 1.0)
		m_volum = 1.0;
	m_pBGChannel->setVolume(m_volum);
}

void SoundManager::BGReset()
{
	m_pBGChannel = nullptr;
}

int SoundManager::Get_BGM(int _BGM)
{
	switch (_BGM)
	{
	case MENUBGM:
		return MenuBGM;
		break;
	case TOWNBGM:
		return TownBGM;
		break;
	}
}