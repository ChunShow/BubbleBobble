#include "main.h"
#include "Texture.h"
#include <map>

Player player;
Player* playerPointer = &player;

Map stages(0) ;
map<int, Bubble> bubbles;
vector<Monster> monsters;
vector<Explosion> explosions;
vector<Item> items;

int bubble_total_num=0;
int level;
bool clear;
bool gameover = false;
bool gamestart = true;
bool restarted = false;
bool keystates[6];

Idle idleFunc;
clock_t startTime = clock();
clock_t lastBubbleCreationTime = clock();
clock_t lastItemCreationTime = clock();

Texture gmover(_MAP, _GAMEOVER);
Texture title(_MAP, _TITLE);

void initialize(bool restarted)
{
	player = Player(5);
	level = 0;
	clear = false;

	stages = Map(level);

	for (int i = 0; i < 3; i++) {
		monsters.push_back(Monster(ROBOT));
	}

	monsters[0].setPosition(-0.4f, -0.25f);
	monsters[1].setPosition(0.25f, 0.25);
	monsters[2].setPosition(-0.4f, 0.75f);
}

void idle()
{
	idleFunc.operate();
}

//Erase everything and get ready to restart;
void clearDataToRestart() {
	stages.resetStage();
	bubbles.clear();
	monsters.clear();
	explosions.clear();
	items.clear();
	bubble_total_num = 0;
}

void clearDataToChangeStage() {
	bubbles.clear();
	for (auto& item : items) {
		switch (item.getType()) {
		case SPEED:
			player.setSpeedScale(1.0f);
			break;
		case DOUBLE:
			player.offDoubleShot();
			break;
		case RAPID:
			player.setDelay(300.0f);
			break;
		}
	}
	items.clear();
}

void displayGameover()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, gmover.getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 0.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 0.6f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, 0.0f);
	glEnd();
}
void displayTitle()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, title.getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
	glEnd();
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

	stages.drawMap(monsters, clear);

	//Detect clear
	if (clear) clearDataToChangeStage();

	for (auto& monster : monsters) {
		if (monster.collisionDetection(player) && !monster.isTrapped()) {
			if (!player.isInvincible()) player.giveInvincibility(27);
		}
	}

	glEnable(GL_DEPTH_TEST);
	glColor3f(0.3f, 0.9f, 0.2f);

	for (auto itr = bubbles.begin(); itr != bubbles.end();) {
		int key = (*itr).first; Bubble& bubble = (*itr).second;
		if (bubble.isAlive()) {
			bubble.draw();
			++itr;
		}
		else {
			explosions.push_back(Explosion(bubble.getPositionX(), bubble.getPositionY(), bubble.isTrapping()));
			bubbles.erase(itr++);
		}
	}

	int k = 0;
	while (explosions.begin() + k < explosions.end()) {
		if (explosions[k].isAlive()) {
			explosions[k].draw();
			k++;
		}
		else {
			explosions.erase(explosions.begin() + k);
		}
	}

	glDisable(GL_DEPTH_TEST);

	int i = 0;
	while (items.begin() + i < items.end()) {
		if (items[i].visible()) items[i].draw();
		
		if (items[i].isDisappeared() || items[i].isEffectFinished()) items.erase(items.begin() + i);
		else i++;
	}

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

	if (!player.isBlink()) player.drawPlayer();
	player.drawLife();

	if (monsters.size() == 0) {
		clear = true;
	}

	//Detect gameover
	if (!player.isAlive()) {
		player.reset();
		gameover = true;
	}
	
	if (gamestart) displayTitle();

	if (gameover == true){
		displayGameover();
	}

	if (restarted == true) {
		clearDataToRestart();
		initialize(restarted);
		restarted = false;
	}
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Bubble Bobble");

	initialize(false);

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
