#include "main.h"

void displayStrokeCharacters(void* font, string c, float lnWidth, float x, float y, float scale) {
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
	leaderboard = map<pair<int, int>, string, cmpByScore>();
	loadLeaderboard();
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
	glColor3f(0.0f, 0.0f, 0.0f);
	clock_t time = getLeftTime(lastClearTime);
	int time_left = getLeftTime(lastClearTime);
	float scale = 1 / 2800.0f;

	if (!isMapMoving) {
		if  (time_left <= 50) glColor3f(5.0f, 0.0f, 0.0f);
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(time_left), 2.6f, - 0.7f, 0.96f, scale);
		glColor3f(0.0f, 0.0f, 0.0f);
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(score), 2.6f, 0.78f, 0.96f, scale);
	}
	else {
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(scoreByTime), 2.6f, - 0.7f, 0.96f, scale);
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(score), 2.6f, 0.78f, 0.96f, scale);
	}
	
	if (time_left == 0) {
		player.setLife(0);
	}
}

void Scoreboard::displayLeaderboard()
{
	float padding = 0.0f;
	gamestart ? glColor3f(1.0f, 1.0f, 1.0f) : glColor3f(0.0f, 0.0f, 0.0f) ;
	if (!gamestart) padding = 0.2f;

	auto itr = leaderboard.begin();
	float scale = 1 / 1600.0f;
	for (int i = 0; i < 5; i++) {
		string score = to_string((*itr).first.second); string name = (*itr).second;
		score.insert(score.begin(), 5 - score.size(), ' ');

		string line = to_string(i + 1) + ' ' + score + ' ' + name;
		displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, line, 2.6f, -0.427f, padding-0.35f - 0.10*i, scale);
		itr = next(itr);
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
	saved = false;
	fixed = false;
}

void Scoreboard::computeFinalScore()
{
	if (!fixed) {
		score = score + getLeftTime(lastClearTime);
		fixed = true;
	}
}

void Scoreboard::displayFinalScore()
{
	displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, to_string(score), 2.6f, 0.1f, -0.17f, 1/1000.0f);
}

void Scoreboard::loadLeaderboard()
{
	if (_access("leaderboard.txt", 0) == -1) ofstream("leaderboard.txt").close(); // make file if "leaderboard.txt" does not exists.

	fstream ifs("leaderboard.txt");
	int id; int sc; string name;
	while (ifs >> id >> sc >> name) {
		leaderboard.insert(make_pair(make_pair(id, sc), name));
	}
	ifs.close();
}

void Scoreboard::writeLeaderboard()
{
	fstream ofs("leaderboard.txt");
	for (auto itr = leaderboard.begin(); itr != leaderboard.end(); itr++) {
		ofs << (*itr).first.first << ' ' << (*itr).first.second << ' ' << (*itr).second << endl;
	}
	ofs.close();
}

void Scoreboard::addMyrecord(string name)
{
	int length = leaderboard.size();
	leaderboard.insert(make_pair(make_pair(length + 1, score), name));
}

bool Scoreboard::isSaved()
{
	return saved;
}

void Scoreboard::save()
{
	saved = true;
	writeLeaderboard();
}
