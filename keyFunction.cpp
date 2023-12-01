#include "main.h"

void specialKeyDown(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		keystates[KEY::LEFT] = 1;
		break;
	case GLUT_KEY_RIGHT:
		keystates[KEY::RIGHT] = 1;
		break;
	case GLUT_KEY_UP:
		keystates[KEY::UP] = 1;
		if (player.getState() == STAY) {
			PlaySound(TEXT("sound/jump"), 0, SND_FILENAME | SND_ASYNC);
			player.setState(JUMP);
			player.setVelocityY(0.10f);
		}
		break;
	case GLUT_KEY_DOWN:
		keystates[KEY::DOWN] = 1;
		break;
	case GLUT_KEY_CTRL_L:
		keystates[KEY::RESTART] = 1;
		break;
	}
}

void specialKeyUp(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		keystates[KEY::LEFT] = 0;
		break;
	case GLUT_KEY_RIGHT:
		keystates[KEY::RIGHT] = 0;
		break;
	case GLUT_KEY_UP:
		keystates[KEY::UP] = 0;
		break;
	case GLUT_KEY_DOWN:
		keystates[KEY::DOWN] = 0;
		break;
	case GLUT_KEY_CTRL_L:
		keystates[KEY::RESTART] = 0;
		break;
	}
}

void keyDown(unsigned char key, int x, int y)
{
	if ('a' <= key && key <= 'z' && win) {
		input.addLetter(key);
	}
	if (key == backspace) {
		input.deleteLastLetter();
	}

	switch (key) {
	case spacebar:
		keystates[KEY::SPACEBAR] = 1;
		break;
	case 'h':
		displayHelp = !displayHelp;
		break;
	case 'H':
		displayHelp = !displayHelp;
		break;
	}
}

void keyUp(unsigned char key, int x, int y) 
{
	switch (key) {
	case spacebar:
		keystates[KEY::SPACEBAR] = 0;
		break;
	}
}