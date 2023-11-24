#pragma once
#include <vector>
#include "Texture.h"
#include "Monster.h"

class Map {
public:
	//  constructor
	//	int level means the stage of map
	Map(int level);

	//  draw pixel image of map according to the stage
	void drawMap(vector<Monster>& monsters, bool& clear, bool gamestart);
	void drawStage(int level);
	void drawBackground();
	void changeMap(vector<Monster>& monsters, bool& clear);
	void setMonsters(vector<Monster>& monsters);

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
	void drawStage0();
	void drawStage1();
	void drawStage2();
	void drawStage3();
	void drawStage4();

	//  check whether player's movement is allowed or not
	bool checkFALL();
	void checkJUMP();
	void checkLEFT();
	void checkRIGHT();

	//  restrict monster's movement range
	bool checkMonster(Monster& monster);

	//  getter
	vector<vector<float>> getBorderHard () const;
	vector<vector<float>> getBorder() const;
	float getTime () const;

	// reset stage number
	void resetStage();

private:
	//  stage means the stage level
	int stage;

	// true if the map has been drawn
	bool drawn;

	//  time consumed moving motion
	float time;
	
	//  border has information of map's layers on which player's state will be STAY from FALL
	vector<vector<float>> border;
	//  borderHard has information of map's layers which player can't pass
	vector<vector<float>> borderHard;

	//  textures information used in map design
	vector<Texture> textures;
};