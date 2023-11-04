#include "main.h"
#include <ctime>

clock_t startTime = clock();
clock_t lastCreationTime = clock();
clock_t endTime;

Player player;
Player* playerPointer = &player;
Map stage1(1);
vector<Bubble> bubbles;
vector<Monster> monsters;

Texture stoneTexture(STONE);
Texture brickTexture(BRICK);
Texture defaultTexture;

bool keystates[5];

void initialize() {
	for (int i = 0; i < 3; i++) {
		monsters.push_back(Monster(CREATURE));
	}
	monsters[0].setPosition(0.0f, -0.53f);
	monsters[1].setPosition(0.0f, -0.11);
	monsters[2].setPosition(0.0f, 0.36f);

	stoneTexture.initTexture();
	brickTexture.initTexture();
	defaultTexture.initTexture();
}

void idle() {
	endTime = clock();
	if (endTime - startTime > 1000 / 30) {

		if (keystates[KEY::LEFT]) {
			//  case of player's direction changes from RIGHT to LEFT
			if (player.direction == KEY::RIGHT) player.direction = KEY::LEFT;
			else {
				if (player.state == FALL) player.translate(-0.015f, 0.0f);
				else player.translate(-0.025f, 0.0f);
				stage1.checkLEFT();
			}
		}

		if (keystates[KEY::RIGHT]) {
			//  case of player's direction changes from LEFT to RIGHT
			if (player.direction == KEY::LEFT) player.direction = KEY::RIGHT;
			else {
				if (player.state == FALL) player.translate(0.015f, 0.0f);
				else player.translate(0.025f, 0.0f);
				stage1.checkRIGHT();
			}
		}

		if (keystates[KEY::DOWN]) {
			// case of player's state is JUMP or FALL
			if (player.state != STAY) {
				player.state = FALL;
				player.translate(0.0f, -0.01f);
			}
		}
		if (keystates[KEY::SPACEBAR] && (endTime - lastCreationTime) > 300) {

			Bubble bubble = player.shoot();
			bubbles.push_back(bubble);
			lastCreationTime = endTime;
		}

		if (player.state == STAY) {
			if (stage1.checkFALL()) {
				player.state = FALL;
			}
		}

		else if (player.state == JUMP) {
			if (player.getVelocityY() > 0) {
				player.setVelocityY(player.getVelocityY()-0.008f);
				player.translate(0.0f, player.getVelocityY());
				stage1.checkJUMP();
			}
			else {
				player.translate(0.0f, -0.01f);
				player.state = FALL;
			}
		}

		else if (player.state == FALL) {
			if (stage1.checkFALL()) {
				player.translate(0.0f, -0.01f);
			}
		}

		player.updatePosition();

		for (auto& bubble : bubbles) {
			if (!bubble.isGrown()) continue;
			if (bubble.collisionDetection(*playerPointer)) {
				bubble.alive = false;
			}
		}

		for (auto& monster : monsters) {
			if (monster.isTrapped()) {
				Bubble bubble = *monster.getTrappedBubble();
				float bubble_x = bubble.getPositionX(); float bubble_y = bubble.getPositionY();
				monster.setPosition(bubble_x - bubble.max_radius, bubble_y - bubble.max_radius);
				continue;
			}
			if (monster.direction == LEFT) {
				if (stage1.checkMonster(monster)) monster.translate(-0.015f, 0.0f);
				else {
					monster.direction = RIGHT;
					monster.translate(0.015f, 0.0f);
				}
			}
			else {
				if (stage1.checkMonster(monster)) monster.translate(0.015f, 0.0f);
				else {
					monster.direction = LEFT;
					monster.translate(-0.015f, 0.0f);
				}
			}
		}

		for (auto& bubble : bubbles) {
			float speed = bubble.horizontal_speed;
			float size = bubble.size;

			bubble.setSize(min(bubble.size + 0.1f, 1.0f));

			float x = bubble.getPositionX(); float y = bubble.getPositionY();
			if (bubble.direction == D_LEFT) bubble.translate(-speed, 0.0f);
			if (bubble.direction == D_RIGHT) bubble.translate(speed, 0.0f);
			if (bubble.direction == D_UP) bubble.translate(0.0f, speed * 0.1);
			if (bubble.mapCollision(stage1.borderHard) || bubble.isGrown()) bubble.direction = D_UP;

			if (bubble.getPositionX() < -1.0f) bubble.setPositionX(1.0f);
			if (bubble.getPositionX() > 1.0f) bubble.setPositionX(-1.0f);
			if (bubble.getPositionY() > 1.0f) bubble.setPositionY(-1.0f);

			for (auto& monster : monsters) {
				if (bubble.collisionDetection(monster) && !monster.isTrapped() && !bubble.isGrown()) {
					bubble.direction = D_UP;
					bubble.size = 1.0f;
					bubble.capturing = true;
					monster.trap(bubble);
				}
			}
			if (clock() - bubble.createdTime > 5000) bubble.alive = false;
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
	glOrtho(-1.0f, 1.0f, -1.0f, 1.f, -5.0f, 5.0f);
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
	light1.setPosition(10.0f, 10.0f, 10.0f, 1.0f);
	light1.setSpecular(0.5f, 0.5f, 0.0f, 1.0f);
	glEnable(GL_LIGHT0);
	light1.draw();

	for (auto& monster : monsters) {
		if (monster.collisionDetection(*playerPointer) && !monster.isTrapped()) {
			if (!player.isInvincible()) {
				player.giveInvincibility();
				player.decreaseLife();
			}
		}
	}
	player.drawPlayer();

	glColor3f(0.3f, 0.9f, 0.2f);
	int i = 0;
	while (bubbles.begin() + i < bubbles.end()) {
		if (bubbles[i].alive) {
			bubbles[i].draw();
			i++;
		}
		else {
			bubbles.erase(bubbles.begin() + i);
		}
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
	stage1.drawMap(brickTexture, stoneTexture, defaultTexture);
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