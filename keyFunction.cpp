#include "main.h"

void specialKeyDown(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		keystates[KEY::LEFT] = 1;
		break;
	case GLUT_KEY_RIGHT:
		keystates[KEY::RIGHT] = 1;
		break;
	case GLUT_KEY_UP:
		keystates[KEY::UP] = 1;
		if (player.state == STAY) {
			player.state = JUMP;
			player.setVelocityY(0.10f);
		}
		break;
	case GLUT_KEY_DOWN:
		keystates[DOWN] = 1;
		break;
	}
	glutPostRedisplay();
}

void specialKeyUp(int key, int x, int y) {
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
	}
	glutPostRedisplay();
}
void keyDown(unsigned char key, int x, int y) {
	switch (key) {
	case spacebar:
		keystates[KEY::SPACEBAR] = 1;
		break;
	}
}
void keyUp(unsigned char key, int x, int y) {
	switch (key) {
	case spacebar:
		keystates[KEY::SPACEBAR] = 0;
		break;
	}
}