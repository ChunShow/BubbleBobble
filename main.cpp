#include "main.h"
#include <ctime>
#include <iostream>

clock_t startTime = clock();
clock_t lastCreationTime = clock();
clock_t endTime;

Player player;
Map stage1(1);
vector<Bubble> bubbles;
vector<Monster> creature;

using namespace std;

bool keystates[5];

void initialize() {
	for (int i = 0; i < 3; i++) {
		creature.push_back(Monster(CREATURE));
	}
	creature[0].setPosition(0.0f, -0.53f);
	creature[1].setPosition(0.0f, -0.11);
	creature[2].setPosition(0.0f, 0.36f);
}

void idle() {
	endTime = clock();
	if (endTime - startTime > 1000 / 30) {
		if (keystates[KEY::LEFT]) {
			//  case of player's direction changes from RIGHT to LEFT
			if (player.direction == KEY::RIGHT) player.direction = KEY::LEFT; 
			else {
				if (player.state == FALL) player.setPosition(-0.015f, 0.0f);
				else player.setPosition(-0.025f, 0.0f);
				stage1.checkLEFT();
			}
		}
		if (keystates[KEY::RIGHT]) {
			//  case of player's direction changes from LEFT to RIGHT
			if (player.direction == KEY::LEFT) player.direction = KEY::RIGHT;
			else {
				if (player.state == FALL) player.setPosition(0.015f, 0.0f);
				else player.setPosition(0.025f, 0.0f);
				stage1.checkRIGHT();
			}
		}
		if (keystates[KEY::DOWN]) {
			// case of player's state is JUMP or FALL
			if (player.state != STAY) { 
				player.state = FALL;
				player.setPosition(0.0f, -0.01f);
			}
		}
		if (keystates[KEY::SPACEBAR] && (endTime - lastCreationTime) > 300) {

			Bubble bubble = player.shoot();
			bubbles.push_back(bubble);
			lastCreationTime = endTime;
		}

		for (auto& bubble : bubbles) {
			float speed = 0.04;
			float size = bubble.size;
			float x = bubble.pos[0]; float y = bubble.pos[1];
			bubble.setSize(min(bubble.size + 0.05, 1.0));
			if (bubble.checkVerticalBoundary() || bubble.isGrown()) {
				bubble.size = 1;
				bubble.direction = D_UP;
			}
			if (bubble.direction == D_LEFT) bubble.setPos(x - speed, y);
			if (bubble.direction == D_RIGHT) bubble.setPos(x + speed, y);
			if (bubble.direction == D_UP) bubble.setPos(x, y + speed);

		}

		if (player.state == STAY) {
			if (stage1.checkFALL()) {
				player.state = FALL;
			}
		}
		else if (player.state == JUMP) {
			if (player.velocity > 0) {
				player.setPosition(0.0f, player.velocity);
				stage1.checkJUMP();
				player.velocity -= 0.008f;
			}
			else {
				player.position[1] -= 0.01f;
				player.state = FALL;
			}
		}
		else if (player.state == FALL) {
			if (stage1.checkFALL()) {
				player.setPosition(0.0f, -0.01f);
			}
		}

		for (auto monster = creature.begin(); monster < creature.end(); monster++)  {
			if ((*monster).direction == LEFT) {
				if (stage1.checkMonster(*monster)) (*monster).setPosition(-0.015f, 0.0f);
				else {
					(*monster).direction = RIGHT;
					(*monster).setPosition(0.015f, 0.0f);
				}
			}
			else {
				if (stage1.checkMonster(*monster)) (*monster).setPosition(0.015f, 0.0f);
				else {
					(*monster).direction = LEFT;
					(*monster).setPosition(-0.015f, 0.0f);
				}
			}
		}

		startTime = endTime;
		glutPostRedisplay();
	}
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 1.0f, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	Light light1;
	light1.setAmbient(1.0f, 1.0f, 1.0f, 1.0f);
	light1.setDiffuse(1.0f, 1.0f, 1.0f, 1.0f);
	light1.setLightID(GL_LIGHT0);
	light1.setPosition(0.0f, 0.0f, 50.0f);
	light1.setSpecular(0.5f, 0.5f, 0.0f, 1.0f);
	glEnable(GL_LIGHT0);
	light1.draw();
	for (auto monster : creature) player.checkhit(monster.hitbox);
	player.drawPlayer();

	for (int i = 0; i < bubbles.size(); i++) {
		bubbles[i].draw();
	}

	for (auto monster : creature) monster.drawMonster();
	stage1.drawMap();

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Bubble Bobble");

	initialize();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}