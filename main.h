#pragma once
#include <GL/freeglut.h>

#include "iostream"
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "Bubble.h"
#include "Explosion.h"
#include "Item.h"
#include "Scoreboard.h"
#include "Input.h"
#include "Audio.h"

#include "keyFunction.h"
#include "Idle.h"
#include "Display.h"

#include <map>

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

#define WINDOW_X 400
#define WINDOW_Y 100
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

extern Player player;
extern Player* playerPointer;

extern Map stages;
extern map<int, Bubble> bubbles;
extern vector<Monster> monsters;
extern vector<Explosion> explosions;
extern vector<Item> items;
extern Scoreboard board;
extern Input input;

extern int level;
extern int bubble_total_num;
extern bool clear;
extern bool gameover;
extern bool gamestart;
extern bool restarted;
extern bool win;
extern bool displayHelp;
extern bool displayLeaderboard;
extern bool dataClearedForMoving;
extern bool keystates[6];

extern vector<Audio> audio;
extern clock_t startTime;
extern clock_t lastBubbleCreationTime;
extern clock_t lastItemCreationTime;
extern clock_t lastClearTime;

extern Texture gmover;
extern Texture title;
extern Texture gmwin;

void initialize(bool restarted);
void displayStrokeCharacters(void* font, string c, float lnWidth, float x, float y, float scale);