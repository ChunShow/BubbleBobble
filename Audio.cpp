#include "main.h"

Audio::Audio() 
{
	SoundSystem();
}

void Audio::SoundSystem() 
{
	System_Create(&pSystem);

	pSystem->init(32, FMOD_INIT_NORMAL, NULL);

	pSystem->createSound("sound/jump.wav", FMOD_LOOP_OFF, NULL, &pSound[0]);
	pSystem->createSound("sound/bubble_shoot.wav", FMOD_LOOP_OFF, NULL, &pSound[1]);
	pSystem->createSound("sound/bubble_pop.wav", FMOD_LOOP_OFF, NULL, &pSound[2]);
	pSystem->createSound("sound/bgm1.wav", FMOD_LOOP_NORMAL, NULL, &pSound[3]);
	pSystem->createSound("sound/click.wav", FMOD_LOOP_OFF, NULL, &pSound[4]);
	pSystem->update();
}
void Audio::PlayJump()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
}
void Audio::PlayBubblePop()
{
	pSystem->playSound(pSound[2], NULL, 0, &pChannel[1]);
}
void Audio::PlayBubbleShoot()
{
	pSystem->playSound(pSound[1], NULL, 0, &pChannel[2]);
}
void Audio::PlayBGM1()
{
	pSystem->playSound(pSound[3], NULL, 0, &pChannel[3]);
}
void Audio::PlayClick()
{
	pSystem->playSound(pSound[4], NULL, 0, &pChannel[4]);
}