#include "main.h"
#include <map>

Player player;
Player* playerPointer = &player;

vector<Map> stages;
map<int, Bubble> bubbles;
vector<Monster> monsters;

int bubble_total_num=0;
int level;
bool clear;
bool keystates[5];

Idle idleFunc;
clock_t startTime = clock();
clock_t lastCreationTime = clock();

void initialize()
{
	player = Player();
	level = 0;
	clear = false;

	for (int i = 0; i < 3; i++) {
		stages.push_back(Map(i));
	}

	for (int i = 0; i < 4; i++) {
		monsters.push_back(Monster(CREATURE));
	}
	monsters[0].setPosition(0.0f, -0.45f);
	monsters[1].setPosition(0.0f, 0.10f);
	monsters[2].setPosition(-0.85f, 0.55f);
	monsters[3].setPosition(0.85f, 0.55f);
}

void idle()
{
	idleFunc.operate();
}

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -5.0f, 5.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	Light light1;
	light1.setAmbient(1.0f, 1.0f, 1.0f, 1.0f);
	light1.setDiffuse(1.0f, 1.0f, 1.0f, 1.0f);
	light1.setLightID(GL_LIGHT0);
	light1.setPosition(10.0f, 10.0f, 10.0f, 1.0f);
	light1.setSpecular(0.5f, 0.5f, 0.0f, 1.0f);
	glEnable(GL_LIGHT0);
	light1.draw();

	stages[level].drawMap(clear);

	for (auto& monster : monsters) {
		if (monster.collisionDetection(*playerPointer) && !monster.isTrapped()) {
			if (!player.isInvincible()) {
				player.giveInvincibility(27);
				player.decreaseLife();
			}
		}
	}
<<<<<<< HEAD
=======

	player.drawPlayer();
>>>>>>> a21887bb3932a2e92e57ba28dc9986cfa3e9f5eb

	glEnable(GL_DEPTH_TEST);
	glColor3f(0.3f, 0.9f, 0.2f);

	for (auto itr = bubbles.begin(); itr != bubbles.end();) {
		int key = (*itr).first; Bubble& bubble = (*itr).second;
		if (bubble.isAlive()) {
			bubble.draw();
			++itr;
		}
		else {
			bubbles.erase(itr++);
		}
	}
<<<<<<< HEAD
	glDisable(GL_DEPTH_TEST);
=======
>>>>>>> a21887bb3932a2e92e57ba28dc9986cfa3e9f5eb

	int j = 0;
	while (monsters.begin() + j < monsters.end()) {
		if (!monsters[j].isTrapped()) {
			monsters[j].drawMonster();
			j++;
		}
		else if (!monsters[j].isAlive()) {
			monsters.erase(monsters.begin() + j);
		}
		else {
			monsters[j].drawMonster();
			j++;
		}
	}

	if (monsters.size() == 0) {
		clear = true;
		monsters.push_back(Monster(CREATURE));
		monsters[0].setPosition(0.0f, -0.95f);
	}

	player.drawPlayer();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
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