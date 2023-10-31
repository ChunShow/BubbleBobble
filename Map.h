#pragma once
#include <vector>
using namespace std;

class Map {
public:
	//  constructor
	//	int n means the stage of map
	Map(int n);

	//  draw pixel image of map according to the stage
	void drawMap();

	/*  drawBlock draws block on which player's state will be STAY from FALL
	    drawHard draws hard block which player can't pass
		setBorder stores block information in border
		setHard stores hard block information in borderHard and block information in border
	*/
	void drawBlock(float x, float y, float width, float height);
	void drawHard(float x, float y, float width, float height);
	void setBorder(float x, float y, float width);
	void setHard(float x, float y, float width, float height);

	//  stages' pixel image setting
	void drawStage1();

	//  check whether player's movement is allowed or not
	bool checkFALL();
	void checkJUMP();
	void checkLEFT();
	void checkRIGHT();

	//  restrict monster's movement range
	bool checkMonster(Monster monster);

	//  stage means the stage number
	int stage;

	// true if the map has been drawn
	bool drawn;
	
	//  border has information of map's layers on which player's state will be STAY from FALL
	vector<vector<float>> border;
	//  borderHard has information of map's layers which player can't pass
	vector<vector<float>> borderHard;
};