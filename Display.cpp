#include "main.h"

Display::Display() {};

void Display::operate()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	displayBlend();
	displayLight();

	displayMap();
	displayBubble();
	displayItem();
	displayMonster();
	displayPlayer();
	glDisable(GL_LIGHT0);
	displayBoard();

	//Detect clear
	if (monsters.size() == 0) clear = true;
	handleGameover();

	//Detect win
	if (stages.isFinalStage() && clear) {
		win = true;
		clear = false;
		board.computeFinalScore();
	}
	handleWin();

	//Detect clear
	if (clear) clearDataToChangeStage();
	glutSwapBuffers();
}

void Display::displayBlend()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void Display::displayLight()
{
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
	light1.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_LIGHT0);
	light1.draw();
}
void Display::displayMap()
{
	stages.drawMap(monsters, clear, gamestart);
}
void Display::displayMonster()
{
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
}
void Display::displayBubble()
{
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
			audio[2].PlayBubblePop();
		}
	}

	int k = 0;
	while (explosions.begin() + k < explosions.end()) {
		if (explosions[k].isAlive()) {
			explosions[k].draw();
			k++;
		}
		else explosions.erase(explosions.begin() + k);
	}
	glDisable(GL_DEPTH_TEST);
}
void Display::displayPlayer()
{
	for (auto& monster : monsters) {
		if (monster.collisionDetection(player) && !monster.isTrapped()) {
			if (!player.isInvincible()) player.giveInvincibility(27);
		}
	}

	if (!player.isBlink()) player.drawPlayer();
	player.drawLife();
}

void Display::displayItem()
{
	int i = 0;
	while (items.begin() + i < items.end()) {
		if (items[i].visible()) items[i].draw();

		if (items[i].isDisappeared() || items[i].isEffectFinished()) items.erase(items.begin() + i);
		else i++;
	}
}
void Display::displayBoard()
{
	board.draw(stages.isMoving());
}


void Display::displayTitle()
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
void Display::displayGameover()
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
void Display::displayWin()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, gmwin.getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 0.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 0.6f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, 0.0f);
	glEnd();
}

void Display::clearDataToRestart() {
	stages.resetStage();
	bubbles.clear();
	monsters.clear();
	explosions.clear();
	items.clear();
	bubble_total_num = 0;
	board.reset();
	input.reset();
	displayHelp = false;
}

void Display::clearDataToChangeStage() {
	if (dataClearedForMoving) return;
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
	board.changeLeftTimeToScore(lastClearTime);
	dataClearedForMoving = true;
}
void Display::handleGameover()
{
	if (!player.isAlive()) {
		player.reset();
		gameover = true;
	}
	if (gameover == true) {
		displayGameover();
	}
	if (restarted == true) {
		clearDataToRestart();
		initialize(restarted);
		restarted = false;
	}
}

void Display::handleWin()
{
	if (win == true) {
		glColor3f(0.0f, 0.0f, 0.0f);
		input.displayName();
		board.displayLeaderboard();
		displayWin();
	}
	if (restarted == true) {
		clearDataToRestart();
		initialize(restarted);
		restarted = false;
	}
}
