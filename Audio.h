#pragma once
#include"fmod.hpp"
#include"fmod_errors.h"

using namespace FMOD;

class Audio {
public:
	Audio();
	void SoundSystem();
	void PlayJump();
	void PlayBubblePop();
	void PlayBubbleShoot();
	void PlayBGM1();
	void PlayClick();

private:
	System* pSystem;
	Sound* pSound[10];
	Channel* pChannel[10];
};

