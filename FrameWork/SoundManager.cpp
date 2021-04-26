#include "Include.h"
SoundManager sound;
SoundManager::SoundManager()
{
	System_Create(&m_pSystem);//배경음채널
	System_Create(&m_pSystem2);//효과음채널
	m_pSystem->init(10, FMOD_INIT_NORMAL, 0);
	m_pSystem2->init(10, FMOD_INIT_NORMAL, 0);
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
	m_pSystem2->release();
	m_pSystem2->close();
}
void SoundManager::Init()
{
	/// <배경음악>
	MenuBGM = AddSoundFile("./resources/sound/Ui/bgm/title.wav", true);//메뉴배경음악
	TownBGM = AddSoundFile("./resources/sound/Ui/bgm/0.Town.wav", true);//마을배경음악
	DungeonBGM = AddSoundFile("./resources/sound/Ui/bgm/1.JailField.wav", true);//던전배경음악
	/// </배경음악>

	/// <효과음>
	ssWEffect = AddEffectFile("./resources/sound/MeleeWeapon/generalAttack.wav", false);//숏쇼드 효과음
	dungeonOpen = AddEffectFile("./resources/sound/DungreedSound/DungeonOpen.wav", false);//던전입구 열리는효과음
	dungeonClose = AddEffectFile("./resources/sound/DungreedSound/DungeonClose.wav", false);//던전입구 닫히는 효과음
	/// </효과음>

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
int SoundManager::AddEffectFile(std::string _fullpath, bool  _IsLoop)
{
	auto Find = m_CheckList.find(_fullpath);
	if (Find != m_CheckList.end())
	{
		return Find->second;
	}
	Sound* pSound = nullptr;
	int Mode = FMOD_HARDWARE | (_IsLoop ? FMOD_LOOP_NORMAL | FMOD_DEFAULT : FMOD_LOOP_OFF);
	m_pSystem2->createSound(_fullpath.c_str(), Mode, 0, &pSound);
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
	
	m_pSystem2->playSound(FMOD_CHANNEL_FREE, Find->second, 0, &pChannel);

	test = pChannel;
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
void SoundManager::BGMChange(int _SoundNum)
{
	BGStop();//배경음악 중지
	BGReset();//배경음악 채널 리셋
	BGPlay(_SoundNum);
}

//효과음한번만나게 하기위함
void SoundManager::SoundPlay(int _SoundNum)
{
	isEffectPlay = false;
	if (!isEffectPlay)
	{
		EffectPlay(_SoundNum);
		isEffectPlay = true;
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
	case DUNGEONBGM:
		return DungeonBGM;
		break;
	}
}

int SoundManager::Get_Effect(int _Effect)
{
	switch (_Effect)
	{
	case SSWSWING:
		return ssWEffect;
		break;
	case DUNOPEN:
		return dungeonOpen;
		break;
	case DUNCLOSE:
		return dungeonClose;
		break;

	}
}

//배경채널 상태 확인용 테스트
Channel* SoundManager::Get_Test()
{
	return m_pBGChannel;
}