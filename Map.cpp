#include "main.h"

//  initial setting of map
Map::Map(int level) : stage(level)
{
	drawn = false;
	time = 0.0f;
}

void Map::drawMap(Texture texture1, Texture texture2, Texture texture3, Texture field, bool& clear)
{
	glTranslatef(0.0f, time, 0.0f);
	//  draw map according to the level of stage
	switch (stage) {
	case 0:
		drawStage0(texture1, texture2, texture3);
		break;
	case 1:
		drawStage1(texture1, texture2, texture3);
		break;
	case 2:
		drawStage2(texture1, texture2, texture3);
		break;
	default:
		drawStage0(texture1, texture2, texture3);
		break;
	}
	drawBackground(field);

	if (clear) {
		glTranslatef(0.0f, -2.4f, 0.0f);
		switch (stage + 1) {
		case 0:
			drawStage0(texture1, texture2, texture3);
			break;
		case 1:
			drawStage1(texture1, texture2, texture3);
			break;
		case 2:
			drawStage2(texture1, texture2, texture3);
			break;
		default:
			drawStage0(texture1, texture2, texture3);
			break;
		}
		drawBackground(field);
		changeMap(clear);
	}
}

void Map::drawBackground(Texture field)
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, field.getTextureID());
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Map::changeMap(bool& clear)
{
	if (clear) {
		time += 0.01f;
		if (time >= 2.4f) {
			time = 0.0f;
			stage++;
			border.erase(border.begin(), border.end());
			borderHard.erase(borderHard.begin(), borderHard.end());
			drawn = false;
			clear = false;
		}
	}
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

void Map::drawStage0(Texture texture1, Texture texture2, Texture texture3) 
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	//  the bottom layer
	glBindTexture(GL_TEXTURE_2D, texture3.getTextureID());
	drawHard(-1.2f, -0.95f, 1.0f, 0.25f);
	drawHard(0.2f, -0.95f, 1.0f, 0.25f);

	//  the top layer
	glBindTexture(GL_TEXTURE_2D, texture1.getTextureID());
	drawHard(-1.2f, 1.2f, 1.0f, 0.25f);
	drawHard(0.2f, 1.2f, 1.0f, 0.25f);

	//  the side layer
	glBindTexture(GL_TEXTURE_2D, texture1.getTextureID());
	drawHard(-1.2f, 1.0f, 0.25f, 1.0f);
	drawHard(-1.2f, -0.45f, 0.25f, 0.50f);
	drawHard(0.95f, 1.0f, 0.25f, 1.0f);
	drawHard(0.95f, -0.45f, 0.25f, 0.50f);

	//  the first layer
	glBindTexture(GL_TEXTURE_2D, texture3.getTextureID());
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
	glBindTexture(GL_TEXTURE_2D, texture2.getTextureID());
	drawHard(-0.4f, 0.40f, 0.10f, 0.40f);
	drawHard(-0.3f, 0.10f, 0.6f, 0.10f);
	drawHard(0.3f, 0.40f, 0.10f, 0.40f);

	glDisable(GL_TEXTURE_2D);
	drawn = true;
}

void Map::drawStage1(Texture texture1, Texture texture2, Texture texture3) 
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	//  the bottom layer
	glBindTexture(GL_TEXTURE_2D, texture3.getTextureID());
	drawHard(-1.2f, -0.95f, 2.4f, 0.25f);

	//  the top layer
	glBindTexture(GL_TEXTURE_2D, texture1.getTextureID());
	drawHard(-1.2f, 1.2f, 2.4f, 0.25f);

	//  the side layer
	drawHard(-1.2f, 1.0f, 0.25f, 2.4f);
	drawHard(0.95f, 1.0f, 0.25f, 2.4f);

	//  the first layer
	glBindTexture(GL_TEXTURE_2D, texture3.getTextureID());
	drawBlock(-1.2f, -0.53f, 0.5f, 0.05f);
	drawBlock(0.7f, -0.53f, 0.5f, 0.05f);
	drawBlock(-0.4f, -0.53f, 0.80f, 0.05f);

	//  the second layer
	drawBlock(-1.2f, -0.11f, 0.5f, 0.05f);
	drawBlock(0.7f, -0.11f, 0.5f, 0.05f);
	drawBlock(-0.4f, -0.11f, 0.8f, 0.05f);

	//  the third layer
	drawBlock(-1.2f, 0.36f, 0.5f, 0.05f);
	drawBlock(0.7f, 0.36f, 0.5f, 0.05f);
	drawBlock(-0.4f, 0.36f, 0.8f, 0.05f);

	glDisable(GL_TEXTURE_2D);
	drawn = true;
}

void Map::drawStage2(Texture texture1, Texture texture2, Texture texture3) 
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	//  the bottom layer
	glBindTexture(GL_TEXTURE_2D, texture1.getTextureID());
	drawHard(-1.2f, -0.95f, 1.0f, 0.25f);
	drawHard(0.2f, -0.95f, 1.0f, 0.25f);

	//  the top layer
	drawHard(-1.2f, 1.2f, 1.0f, 0.25f);
	drawHard(0.2f, 1.2f, 1.0f, 0.25f);

	//  the side layer
	glBindTexture(GL_TEXTURE_2D, texture1.getTextureID());
	drawHard(-1.2f, 1.0f, 0.25f, 1.16f);
	drawHard(-1.2f, -0.53f, 0.25f, 0.47f);
	drawHard(0.95f, 1.0f, 0.25f, 1.16f);
	drawHard(0.95f, -0.53f, 0.25f, 0.47f);

	//  the first layer
	glBindTexture(GL_TEXTURE_2D, texture3.getTextureID());
	drawBlock(-1.2f, -0.53f, 0.5f, 0.05f);
	drawBlock(0.7f, -0.53f, 0.5f, 0.05f);
	drawBlock(-0.4f, -0.53f, 0.80f, 0.05f);

	//  the second layer
	drawBlock(-1.2f, -0.11f, 0.5f, 0.05f);
	drawBlock(0.7f, -0.11f, 0.5f, 0.05f);
	drawBlock(-0.4f, -0.11f, 0.8f, 0.05f);

	//  the third layer
	drawBlock(-1.2f, 0.31f, 0.5f, 0.05f);
	drawBlock(0.7f, 0.31f, 0.5f, 0.05f);

	//  the middle object
	glBindTexture(GL_TEXTURE_2D, texture2.getTextureID());
	drawHard(-0.4f, 0.66f, 0.10f, 0.40f);
	drawHard(-0.3f, 0.36f, 0.6f, 0.10f);
	drawHard(0.3f, 0.66f, 0.10f, 0.40f);

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
		pos[1] = player.getPositionX() + 0.16f;
	}
	else {
		pos[0] = player.getPositionX() + 0.01f;
		pos[1] = player.getPositionX() + 0.15f;
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
		pos[1] = player.getPositionX() + 0.16f;
	}
	else {
		pos[0] = player.getPositionX() + 0.01f;
		pos[1] = player.getPositionX() + 0.15f;
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

	pos[0] = player.getPositionX() + 0.01f;
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
			if (x + width - 0.025f <= pos[0] && pos[0] <= x + width) {
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
	pos[1] = player.getPositionX() + 0.16f;
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
			if (x <= pos[1] && pos[1] <= x + 0.025f) {
				player.setPositionX(x - 0.17f);
			}
		}
	}
}

bool Map::checkMonster(Monster monster) 
{
	float x, y, width;
	float pos[2];
	/*
	monster's x coordinate range
	pos[0] means the left side of monster's bottom
	pos[1] means the right side of monster's bottom
	*/
	pos[0] = monster.getPositionX() + 0.01f;
	pos[1] = monster.getPositionX() + 0.16f;
	for (auto i = 0; i < border.size(); i++) {
		x = border[i][0];
		y = border[i][1];
		width = border[i][2];
		//  check whether monster's left side or right side in border's x coordinate range
		if ((monster.getDirection() == LEFT) && (x <= pos[0] && pos[0] <= x + width)) {
			//  check whether monster's y coordinate contacts border's y coordinate
			if (y - 0.02f <= monster.getPositionY() && monster.getPositionY() <= y) {
				monster.setPositionY(y);
				return true;
			}
		}
		//  check whether monster's left side or right side in border's x coordinate range
		else if ((monster.getDirection() == RIGHT) && (x <= pos[1] && pos[1] <= x + width)) {
			//  check whether monster's y coordinate contacts border's y coordinate
			if (y - 0.02f <= monster.getPositionY() && monster.getPositionY() <= y) {
				monster.setPositionY(y);
				return true;
			}
		}
	}
	return false;
}

vector<vector<float>> Map::getBorderHard() 
{
	return borderHard;
}