#pragma once
#include"fmod.hpp"
#include"fmod_errors.h"

using namespace FMOD;

class Audio {
public:
	Audio(int key);
	void SoundSystem(int key);
	void PlayJump();
	void PlayBubblePop();
	void PlayBubbleShoot();
	void PlayBGM1();
	void PlayClick();
	void PlayBubblePlayer();
	void PlayBubbling();
	void PlayAttacked();
	void PlayItem();
	void PlayGameover();
	void PlayGameclear();

	void stopBGM1();
	void resetSoundGameover();
	void resetSoundGameclear();
	void setCounter();

private:
	System* pSystem;
	Sound* pSound[3];
	Channel* pChannel[3];
	int counter1;
	int counter2;
};

