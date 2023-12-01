#pragma once
class Display
{
public:
	Display();

	void operate();
	void displayBlend();
	void displayLight();
	void displayMap();
	void displayMonster();
	void displayBubble();
	void displayPlayer();
	void displayItem();
	void displayBoard();

	void displayTitle();
	void displayGameover();
	void clearDataToRestart();
	void clearDataToChangeStage();
	void detectGameover();
};

