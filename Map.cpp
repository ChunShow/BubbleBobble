#include "main.h"

//  initial setting of map
Map::Map(int level) : stage(level), drawn(false), time(0.0f)
{
	for (int i = 0; i < 11; i++) {
		textures.push_back(Texture(_MAP, (TEXTURE_BLOCK)i));
		textures[i].initTexture();
	}
}

void Map::drawMap(vector<Monster>& monsters, bool& clear, bool gamestart)
{
	if (gamestart) drawBackground();

	glPushMatrix();
	if (time >= 0.6f) glTranslatef(0.0f, time - 0.6f, 0.0f);
	//  draw map according to the level
	drawStage(stage);

	if (gamestart && clear) {
		glTranslatef(0.0f, -2.4f, 0.0f);
		border.clear();
		borderHard.clear();
		drawStage(stage + 1);
		changeMap(monsters, clear);
	}
	glPopMatrix();
	drawScoreBoard();
}
void Map::drawStage(int level) {
	switch (level) {
	case 0:
		drawStage0();
		break;
	case 1:
		drawStage1();
		break;
	case 2:
		drawStage2();
		break;
	case 3:
		drawStage3();
		break;
	case 4:
		drawStage4();
		break;
	default:
		drawStage0();
		break;
	}
}
void Map::drawBackground()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, textures[_FIELD_SKY].getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.2f, 1.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.2f, 1.2f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.2f, -1.2f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.2f, -1.2f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Map::changeMap(vector<Monster>& monsters, bool& clear)
{
	if (clear) {
		time += 0.015f;
		moving = true;
		if (time >= 3.0f) {
			time = 0.0f;
			stage++;
			drawn = false;
			clear = false;
			moving = false;
			dataClearedForMoving = false;
			lastClearTime = clock();
			setMonsters(monsters);
		}
	}
}

void Map::setMonsters(vector<Monster>& monsters) {
	switch (stage) {
	case 0:
		break;
	case 1:
		for (int i = 0; i < 4; i++) {
			monsters.push_back(Monster(CREATURE));
		}
		monsters[0].setPosition(0.0f, -0.1f);
		monsters[1].setPosition(0.0f, 0.35f);
		monsters[2].setPosition(-0.8f, 0.25f);
		monsters[3].setPosition(0.8f, 0.25f);
		break;
	case 2:
		for (int i = 0; i < 4; i++) {
			monsters.push_back(Monster(GHOST));
		}
		monsters[0].setPosition(-0.6f, -0.15f);
		monsters[1].setPosition(-0.2f, -0.15f);
		monsters[2].setPosition(0.2f, -0.15f);
		monsters[3].setPosition(0.6f, -0.15f);

		for (int i = 0; i < 4; i++) {
			monsters.push_back(Monster(CREATURE));
		}
		monsters[4].setPosition(-0.6f, 0.3f);
		monsters[5].setPosition(-0.2f, 0.3f);
		monsters[6].setPosition(0.2f, 0.3f);
		monsters[7].setPosition(0.6f, 0.3f);

		for (int i = 0; i < 4; i++) {
			monsters.push_back(Monster(ROBOT));
		}
		monsters[8].setPosition(-0.6f, 0.75f);
		monsters[9].setPosition(-0.2f, 0.75f);
		monsters[10].setPosition(0.2f, 0.75f);
		monsters[11].setPosition(0.6f, 0.75f);
		break;
	case 3:
		monsters.push_back(Monster(CREATURE));
		monsters[0].setPosition(0.08f, 0.4f);

		for (int i = 0; i < 3; i++) {
			monsters.push_back(Monster(ROBOT));
		}
		monsters[1].setPosition(-0.8f, -0.15f);
		monsters[2].setPosition(-0.8f, 0.35f);
		monsters[3].setPosition(-0.95f, 0.85f);

		for (int i = 0; i < 3; i++) {
			monsters.push_back(Monster(GHOST));
		}
		monsters[4].setPosition(0.8f, 0.35f);
		monsters[5].setPosition(0.8f, 0.85f);
		monsters[6].setPosition(0.8f, -0.15f);

		break;
	case 4:
		monsters.push_back(Monster(CREATURE));
		monsters[0].setPosition(0.08f, 0.4f);

		for (int i = 0; i < 6; i++) {
			monsters.push_back(Monster(ROBOT));
		}
		monsters[1].setPosition(-0.8f, -0.15f);
		monsters[2].setPosition(0.8f, -0.15f);
		monsters[3].setPosition(-0.8f, 0.35f);
		monsters[4].setPosition(0.8f, 0.35f);
		monsters[5].setPosition(-0.8f, 0.85f);
		monsters[6].setPosition(0.8f, 0.85f);
		break;
	default:
		monsters.push_back(Monster(CREATURE));
		monsters[0].setPosition(0.08f, 0.4f);

		for (int i = 0; i < 6; i++) {
			monsters.push_back(Monster(ROBOT));
		}
		monsters[1].setPosition(-0.8f, -0.15f);
		monsters[2].setPosition(0.8f, -0.15f);
		monsters[3].setPosition(-0.8f, 0.35f);
		monsters[4].setPosition(0.8f, 0.35f);
		monsters[5].setPosition(-0.8f, 0.85f);
		monsters[6].setPosition(0.8f, 0.85f);
		break;
	}
}
void Map::drawScoreBoard()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, textures[_TIME].getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.95f, 0.95f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.95f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(-0.71f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(-0.71f, 0.95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textures[_SCORE].getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.45f, 0.95f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.45f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(0.75f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(0.75f, 0.95);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}


void Map::drawBlock(float x, float y, float width, float height) 
{
	if (!drawn) setBorder(x, y, width);

	for (float i = 0.00f; i < width; i += 0.05f) {
		for (float j = 0.00f; j < height; j += 0.05f) {
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex2f(x + i, y - j);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(x + i + 0.05f, y - j);
			glTexCoord2f(1.0f, 0.0f); glVertex2f(x + i + 0.05f, y - j - 0.05f);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(x + i, y - j - 0.05f);
			glEnd();
		}
	}
}
void Map::drawHard(float x, float y, float width, float height) 
{
	if (!drawn) setHard(x, y, width, height);

	for (float i = 0.00f; i < width; i += 0.05f) {
		for (float j = 0.00f; j < height; j += 0.05f) {
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex2f(x + i, y - j);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(x + i + 0.05f, y - j);
			glTexCoord2f(1.0f, 0.0f); glVertex2f(x + i + 0.05f, y - j - 0.05f);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(x + i, y - j - 0.05f);
			glEnd();
		}
	}
}
void Map::setBorder(float x, float y, float width) 
{
	border.push_back(vector<float>());
	border.back().push_back(x);
	border.back().push_back(y);
	border.back().push_back(width);
}
void Map::setHard(float x, float y, float width, float height) 
{
	setBorder(x, y, width);
	borderHard.push_back(vector<float>());
	borderHard.back().push_back(x);
	borderHard.back().push_back(y);
	borderHard.back().push_back(width);
	borderHard.back().push_back(height);
}

void Map::drawStage0()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, textures[_TITLE].getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
	glEnd();

	if (displayHelp) {
		glBindTexture(GL_TEXTURE_2D, textures[_HELP].getTextureID());
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.9f, 0.45f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(0.9f, 0.45f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(0.9f, -0.45f);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.9f, -0.45f);
		glEnd();
	}
	if (displayLeaderboard) {
		glBindTexture(GL_TEXTURE_2D, textures[_LEADERBOARD].getTextureID());
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.6f, 0.4f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(0.6f, 0.4f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(0.6f, -0.8f);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.6f, -0.8f);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		glDisable(GLUT_DEPTH);
		board.displayLeaderboard();
		glEnable(GLUT_DEPTH);
	}

	glDisable(GL_TEXTURE_2D);
}
void Map::drawStage1()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	//  the side layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.0f, 0.25f, 2.2f);
	drawHard(0.95f, 1.0f, 0.25f, 2.2f);

	//  the bottom layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-0.95f, -0.95f, 1.9f, 0.25f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, -1.0f, 2.4f, 0.2f);

	//  the top layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.4f, 2.4f, 0.45f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, 1.4f, 2.4f, 0.4f);

	//  the first layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_RED].getTextureID());
	drawBlock(-0.95f, -0.5f, 0.25f, 0.05f);
	drawBlock(0.7f, -0.5f, 0.25f, 0.05f);
	drawBlock(-0.4f, -0.3f, 0.8f, 0.05f);

	//  the second layer
	drawBlock(-0.95f, -0.05f, 0.25f, 0.05f);
	drawBlock(0.7f, -0.05f, 0.25f, 0.05f);
	drawBlock(-0.4f, 0.15f, 0.8f, 0.05f);

	//  the third layer
	drawBlock(-0.95f, 0.4f, 0.25f, 0.05f);
	drawBlock(0.7f, 0.4f, 0.25f, 0.05f);

	glDisable(GL_TEXTURE_2D);
	drawn = true;
}
void Map::drawStage2()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	//  the first layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_RED].getTextureID());
	drawBlock(-0.8f, -0.5f, 1.75f, 0.05f);

	//  the second layer
	drawBlock(-0.95f, -0.05f, 1.75f, 0.05f);

	//  the third layer
	drawBlock(-0.8f, 0.4f, 1.75f, 0.05f);

	//  the side layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.0f, 0.25f, 2.2f);
	drawHard(0.95f, 1.0f, 0.25f, 2.2f);

	//  the bottom layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-0.95f, -0.95f, 1.9f, 0.25f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, -1.0f, 2.4f, 0.2f);

	//  the top layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.2f, 2.4f, 0.25f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, 1.2f, 2.4f, 0.2f);

	glDisable(GL_TEXTURE_2D);
	drawn = true;
}
void Map::drawStage3() 
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	//  the side layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.0f, 0.25f, 1.0f);
	drawHard(-1.2f, -0.45f, 0.25f, 0.75f);
	drawHard(0.95f, 1.0f, 0.25f, 1.0f);
	drawHard(0.95f, -0.45f, 0.25f, 0.75f);

	//  the bottom layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-0.95f, -0.95f, 0.75f, 0.25f);
	drawHard(0.2f, -0.95f, 0.75f, 0.25f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, -1.0f, 1.0f, 0.2f);
	drawBlock(0.2f, -1.0f, 1.0f, 0.2f);

	//  the top layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.2f, 1.0f, 0.25f);
	drawHard(0.2f, 1.2f, 1.0f, 0.25f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, 1.2f, 1.0f, 0.2f);
	drawBlock(0.2f, 1.2f, 1.0f, 0.2f);

	//  the first layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_RED].getTextureID());
	drawBlock(-0.95f, -0.45f, 0.25f, 0.05f);
	drawBlock(0.7f, -0.45f, 0.25f, 0.05f);
	drawBlock(-0.4f, -0.45f, 0.8f, 0.05f);

	//  the second layer
	drawBlock(-0.95f, 0.05f, 0.25f, 0.05f);
	drawBlock(0.7f, 0.05f, 0.25f, 0.05f);

	//  the third layer
	drawBlock(-0.95f, 0.55f, 0.25f, 0.05f);
	drawBlock(0.7f, 0.55f, 0.25f, 0.05f);

	//  the middle object
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawHard(-0.4f, 0.40f, 0.10f, 0.40f);
	drawHard(-0.3f, 0.10f, 0.6f, 0.10f);
	drawHard(0.3f, 0.40f, 0.10f, 0.40f);

	glDisable(GL_TEXTURE_2D);
	drawn = true;
}
void Map::drawStage4()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	//  the side layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.0f, 0.25f, 1.0f);
	drawHard(-1.2f, -0.45f, 0.25f, 0.75f);
	drawHard(0.95f, 1.0f, 0.25f, 1.0f);
	drawHard(0.95f, -0.45f, 0.25f, 0.75f);

	//  the bottom layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-0.95f, -0.95f, 0.75f, 0.25f);
	drawHard(0.2f, -0.95f, 0.75f, 0.25f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, -1.0f, 1.0f, 0.2f);
	drawBlock(0.2f, -1.0f, 1.0f, 0.2f);

	//  the top layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLUE].getTextureID());
	drawHard(-1.2f, 1.2f, 1.0f, 0.25f);
	drawHard(0.2f, 1.2f, 1.0f, 0.25f);
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawBlock(-1.2f, 1.2f, 1.0f, 0.2f);
	drawBlock(0.2f, 1.2f, 1.0f, 0.2f);

	//  the first layer
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_RED].getTextureID());
	drawBlock(-0.95f, -0.45f, 0.25f, 0.05f);
	drawBlock(0.7f, -0.45f, 0.25f, 0.05f);
	drawBlock(-0.4f, -0.45f, 0.8f, 0.05f);

	//  the second layer
	drawBlock(-0.95f, 0.05f, 0.25f, 0.05f);
	drawBlock(0.7f, 0.05f, 0.25f, 0.05f);

	//  the third layer
	drawBlock(-0.95f, 0.55f, 0.25f, 0.05f);
	drawBlock(0.7f, 0.55f, 0.25f, 0.05f);

	//  the middle object
	glBindTexture(GL_TEXTURE_2D, textures[_BRICK_BLACK].getTextureID());
	drawHard(-0.4f, 0.40f, 0.10f, 0.40f);
	drawHard(-0.3f, 0.10f, 0.6f, 0.10f);
	drawHard(0.3f, 0.40f, 0.10f, 0.40f);

	glDisable(GL_TEXTURE_2D);
	drawn = true;
}

bool Map::checkFALL() 
{
	float x, y, width;
	float pos[2];
	/*
		player's x coordinate range
		pos[0] means the left side of player's bottom
		pos[1] means the right side of player's bottom
	*/
	if (player.getDirection() == RIGHT) {
		pos[0] = player.getPositionX() + 0.02f;
		pos[1] = player.getPositionX() + 0.15f;
	}
	else {
		pos[0] = player.getPositionX();
		pos[1] = player.getPositionX() + 0.13f;
	}
	for (auto i = 0; i < border.size(); i++) {
		x = border[i][0];
		y = border[i][1];
		width = border[i][2];
		//  check whether player's left side or right side in border's x coordinate range
		if ((x <= pos[0] && pos[0] <= x + width) ||
			(x <= pos[0] + 0.07f && pos[0] + 0.07f <= x + width) ||
			(x <= pos[1] && pos[1] <= x + width)) {
			//  check whether player's y coordinate contacts border's y coordinate
			if (y - 0.02f <= player.getPositionY() && player.getPositionY() <= y) {
				player.setPositionY(y);
				player.setState(STAY);
				return false;
			}
		}
	}
	return true;
}

void Map::checkJUMP() 
{
	float x, y, width, height;
	float pos[2];
	/*
	player's x coordinate range
	pos[0] means the left side of player's bottom
	pos[1] means the right side of player's bottom
	*/
	if (player.getDirection() == RIGHT) {
		pos[0] = player.getPositionX() + 0.02f;
		pos[1] = player.getPositionX() + 0.15f;
	}
	else {
		pos[0] = player.getPositionX();
		pos[1] = player.getPositionX() + 0.13f;
	}
	for (auto i = 0; i < borderHard.size(); i++) {
		x = borderHard[i][0];
		y = borderHard[i][1];
		width = borderHard[i][2];
		height = borderHard[i][3];
		//  check whether player's left side or right side in borderHard's x coordinate range
		if ((x <= pos[0] && pos[0] <= x + width) || (x <= pos[1] && pos[1] <= x + width)) {
			//  check whether player's height contacts borderHard's (y coordinate - height)
			if (y - height <= player.getPositionY() + player.getHeight() && player.getPositionY() + player.getHeight() <= y - height + 0.08f) {
				player.setPositionY(y - height - player.getHeight());
			}
		}
	}
}

void Map::checkLEFT() 
{
	float x, y, width, height;
	float pos[2];

	/*
	player's x coordinate range
	pos[0] means the left side of player's bottom
	pos[1] means the right side of player's bottom
	*/

	pos[0] = player.getPositionX();
	pos[1] = player.getPositionX() + 0.13f;
	for (auto i = 0; i < borderHard.size(); i++) {
		x = borderHard[i][0];
		y = borderHard[i][1];
		width = borderHard[i][2];
		height = borderHard[i][3];
		//  check whether player's height is in borderHard's y coordinate range
		if ((y - height <= player.getPositionY() && player.getPositionY() < y) ||
			(y - height <= player.getPositionY() + 0.09f && player.getPositionY() + 0.09f <= y) ||
			(y - height < player.getPositionY() + player.getHeight() && player.getPositionY() + player.getHeight() <= y)) {
			//  check whether player's left side contacts borderHard's (x coordinate + width)
			if (x + width - 0.025f*player.getSpeedScale() <= pos[0] && pos[0] <= x + width) {
				player.setPositionX(x + width);
			}
		}
	}
}

void Map::checkRIGHT() 
{
	float x, y, width, height;
	float pos[2];
	/*
	player's x coordinate range
	pos[0] means the left side of player's bottom
	pos[1] means the right side of player's bottom
	*/
	pos[0] = player.getPositionX() + 0.02f;
	pos[1] = player.getPositionX() + 0.15f;
	for (auto i = 0; i < borderHard.size(); i++) {
		x = borderHard[i][0];
		y = borderHard[i][1];
		width = borderHard[i][2];
		height = borderHard[i][3];
		//  check whether player's height is in borderHard's y coordinate range
		if ((y - height <= player.getPositionY() && player.getPositionY() < y) ||
			(y - height <= player.getPositionY() + 0.09f && player.getPositionY() + 0.09f <= y) ||
			(y - height < player.getPositionY() + player.getHeight() && player.getPositionY() + player.getHeight() <= y)) {
			//  check whether player's left side contacts borderHard's (x coordinate + width)
			if (x <= pos[1] && pos[1] <= x + 0.025f * player.getSpeedScale()) {
				player.setPositionX(x - 0.15f);
			}
		}
	}
}

bool Map::checkMonster(Monster& monster) 
{
	float x, y, width;
	float pos[2];
	bool xLeftContaining, xRightContaining, ySupporting;
	bool flag = false;
	bool notFloating = false;
	/*
	monster's x coordinate range
	pos[0] means the left side of monster's bottom
	pos[1] means the right side of monster's bottom
	*/
	float i, j;
	switch (monster.getType()) {
	case(ROBOT):
		i = 0.03f;
		j = 0.14f;
		break;
	case(CREATURE):
		i = 0.0f;
		j = 0.15f;
		break;
	case(GHOST):
		i = 0.04f;
		j = 0.15f;
		break;
	}

	pos[0] = monster.getPositionX() + i;
	pos[1] = monster.getPositionX() + j;
	for (auto i = 0; i < border.size(); i++) {
		x = border[i][0];
		y = border[i][1];
		width = border[i][2];
		//  check whether monster's left side or right side in border's x coordinate range

		xLeftContaining = (x <= pos[0] && pos[0] <= x + width);
		xRightContaining = (x <= pos[1] && pos[1] <= x + width);
		ySupporting = (y - 0.02f <= monster.getPositionY() && monster.getPositionY() <= y);

		if (ySupporting) notFloating = true;

		switch (monster.getDirection()) {
		case(LEFT):
			if (xLeftContaining && ySupporting) {
				monster.setPositionY(y);
				return true;
			}
			break;
		case(RIGHT):
			if (xRightContaining && ySupporting) {
				monster.setPositionY(y);
				return true;
			}
			break;
		case(DOWN):
			if ((xLeftContaining || xRightContaining)) {
				if (ySupporting) {
					monster.setPositionY(y);
					return false;
				}
				else {
					flag = true;
				}
			}
			break;
		}
	}
	if (!notFloating) {
		monster.setDirection(DOWN);
		return true;
	}
	return flag;
}

vector<vector<float>> Map::getBorderHard() const 
{
	return borderHard;
}

vector<vector<float>> Map::getBorder() const
{
	return border;
}

float Map::getTime() const
{
	return time;
}

bool Map::isMoving()
{
	return moving;
}

void Map::resetStage()
{
	stage = 0;
	drawn = false;
}

bool Map::isFinalStage()
{
	return stage == maxLevel;
}
