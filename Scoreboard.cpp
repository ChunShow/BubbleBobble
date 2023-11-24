#include "main.h"

void displayStrokeCharacters(void* font, string c, float lnWidth, float x, float y) {
	float scale = 1/ 1200.0f;

	glPushMatrix();
	glLineWidth(lnWidth);
	glTranslatef(x, y, 0.0f);
	glScalef(scale, scale, scale);
	for (int i = 0; i < c.size(); i++)
		glutStrokeCharacter(font, c[i]);
	glPopMatrix();
}

Scoreboard::Scoreboard()
{
	score = 0;
	lastClearTime = clock();
	scoreByTime = 0;
}

int Scoreboard::getScore()
{
	return score;
}

void Scoreboard::addScore(int score)
{
	this->score += score;
}

void Scoreboard::setLastClearTime()
{
	lastClearTime = clock();
}


void Scoreboard::draw(bool isMapMoving)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	clock_t time = getLeftTime(lastClearTime);
	int time_left = getLeftTime(lastClearTime);

	if (!isMapMoving) {
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(time_left), 5.0f, position[0] - 0.8f, position[1] + 0.8f);
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(score), 5.0f, position[0] + 0.6f, position[1] + 0.8f);
	}
	else {
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(scoreByTime), 5.0f, position[0] - 0.8f, position[1] + 0.8f);
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(score), 5.0f, position[0] + 0.6f, position[1] + 0.8f);
	}
}

int Scoreboard::getLeftTime(clock_t lastClearTime)
{
	int time = (int)(clock() - lastClearTime);

	return 100 - time/1000;
}

void Scoreboard::changeLeftTimeToScore(clock_t lastClearTime)
{
	scoreByTime = getLeftTime(lastClearTime);
}

void Scoreboard::addScoreByTime()
{
	if (scoreByTime > 0) {
		score += 1;
		scoreByTime -= 1;
	}
}

void Scoreboard::reset()
{
	score = 0;
	lastClearTime = clock();
	scoreByTime = 0;
}
