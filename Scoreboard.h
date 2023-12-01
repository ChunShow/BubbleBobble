#pragma once
#include "Object.h"
#include <string>
#include <fstream>
#include <ctime>
#include <io.h>
#include <map>

using namespace std;

struct cmpByScore {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		int a_sc = a.second; int b_sc = b.second;
		int a_id = a.first; int b_id = b.first;

		if (a_sc != b_sc) return a_sc > b_sc;
		else return a_id < b_id;
	}
};

class Scoreboard : public Object
{
public:
	Scoreboard();
	int getScore();
	void addScore(int score);
	void setLastClearTime();

	void draw(bool isMapMoving);
	void displayLeaderboard();

	int getLeftTime(clock_t lastClearTime);
	void changeLeftTimeToScore(clock_t lastClearTime);
	void addScoreByTime();

	void reset();
	void computeFinalScore();
	void displayFinalScore();

	void loadLeaderboard();
	void writeLeaderboard();
	void addMyrecord(string name);

	bool isSaved();
	void save();

private:
	int score;
	int scoreByTime;
	bool fixed = false;
	bool saved = false;
	map<pair<int, int>, string, cmpByScore> leaderboard;
};

