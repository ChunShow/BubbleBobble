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
			audio[0].PlayJump();
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
	if (win) {
		if ('a' <= key && key <= 'z') {
			input.addLetter(key);
		}
		if (key == BACKSPACE) {
			input.deleteLastLetter();
		}
		if (key == ENTER) {
			if (!board.isSaved()) {
				board.addMyrecord(input.getName());
				board.save();
				board.setCounter(1);
			}
		}
	}

	switch (key) {
	case spacebar:
		keystates[KEY::SPACEBAR] = 1;
		break;
	case 'h':
		if (gamestart == false) {
			audio[4].PlayClick();
			displayHelp = !displayHelp;
			if (displayLeaderboard) displayLeaderboard = !displayLeaderboard;
		}
		break;
	case 'H':
		if (gamestart == false) {
			audio[4].PlayClick();
			displayHelp = !displayHelp;
			if (displayLeaderboard) displayLeaderboard = !displayLeaderboard;
		}
		break;
	case 'r':
		if (gamestart == false) {
			audio[4].PlayClick();
			displayLeaderboard = !displayLeaderboard;
			if (displayHelp) displayHelp = !displayHelp;
		}
		break;
	case 'R':
		if (gamestart == false) {
			audio[4].PlayClick();
			displayLeaderboard = !displayLeaderboard;
			if (displayHelp) displayHelp = !displayHelp;
		}
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