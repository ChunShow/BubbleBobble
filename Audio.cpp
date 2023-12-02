#include "main.h"

Audio::Audio(int key) : counter1(0), counter2(0)
{
	SoundSystem(key);
}

void Audio::SoundSystem(int key) 
{
	System_Create(&pSystem);
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);
	
	switch (key) {
	case 0:
		pSystem->createSound("sound/jump.wav", FMOD_LOOP_OFF, NULL, &pSound[0]);
		break;
	case 1: 
		pSystem->createSound("sound/bubble_shoot.wav", FMOD_LOOP_OFF, NULL, &pSound[0]);
		break;
	case 2:
		pSystem->createSound("sound/bubble_pop.wav", FMOD_LOOP_OFF, NULL, &pSound[0]);
		break;
	case 3:
		pSystem->createSound("sound/bgm1.wav", FMOD_LOOP_NORMAL, NULL, &pSound[0]);
		break;
	case 4:
		pSystem->createSound("sound/click.wav", FMOD_LOOP_OFF, NULL, &pSound[0]);
		pSystem->createSound("sound/gameover.wav", FMOD_LOOP_OFF, NULL, &pSound[1]);
		pSystem->createSound("sound/gameclear.wav", FMOD_LOOP_OFF, NULL, &pSound[2]);
		break;
	case 5:
		pSystem->createSound("sound/bubbling.wav", FMOD_LOOP_NORMAL, NULL, &pSound[0]);
		pSystem->createSound("sound/bubble_player.wav", FMOD_LOOP_OFF, NULL, &pSound[1]);
		break;
	case 6:
		pSystem->createSound("sound/attacked.wav", FMOD_LOOP_OFF, NULL, &pSound[0]);
		break;
	case 7:
		pSystem->createSound("sound/item.wav", FMOD_LOOP_OFF, NULL, &pSound[0]);
		break;
	}
	pSystem->update();
}
void Audio::PlayJump()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
	pChannel[0]->setVolume(0.3);
}
void Audio::PlayBubblePop()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
	pChannel[0]->setVolume(0.5);
}
void Audio::PlayBubbleShoot()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
	pChannel[0]->setVolume(0.4);
}
void Audio::PlayBGM1()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
}
void Audio::PlayClick()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
}
void Audio::PlayBubblePlayer()
{
	if (pChannel[0]) pChannel[0]->stop();
	if (counter1++ == 0) pSystem->playSound(pSound[1], NULL, 0, &pChannel[1]);
}
void Audio::PlayBubbling()
{
	if (counter2++ == 0) pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
	pChannel[0]->setVolume(0.8);
	pChannel[0]->setPitch(0.4);
}

void Audio::PlayAttacked()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
}
void Audio::PlayItem()
{
	pSystem->playSound(pSound[0], NULL, 0, &pChannel[0]);
	pChannel[0]->setVolume(0.8);
	pChannel[0]->setPitch(0.8);
}
void Audio::PlayGameover()
{
	pSystem->playSound(pSound[1], NULL, 0, &pChannel[1]);
}
void Audio::PlayGameclear()
{
	if (counter1++ == 0) pSystem->playSound(pSound[2], NULL, 0, &pChannel[2]);
}

void Audio::stopBGM1()
{
	if (counter1++ == 0) {
		pChannel[0]->stop();
		pChannel[0]->setPosition(0, FMOD_TIMEUNIT_MS);
	}
}

void Audio::resetSoundGameover()
{
	if (pChannel[1]) {
		pChannel[1]->stop();
		pChannel[1]->setPosition(0, FMOD_TIMEUNIT_MS);
	}
}
void Audio::resetSoundGameclear()
{
	if (pChannel[2]) {
		pChannel[2]->stop();
		pChannel[2]->setPosition(0, FMOD_TIMEUNIT_MS);
	}
}
void Audio::setCounter()
{
	counter1 = 0;
	counter2 = 0;
}