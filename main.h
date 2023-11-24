#pragma once
#include <GL/freeglut.h>

#include "iostream"
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "Bubble.h"
#include "Explosion.h"
#include "Item.h"

#include "keyFunction.h"
#include "Idle.h"

#include <map>

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

extern int level;
extern int bubble_total_num;
extern bool clear;
extern bool gameover;
extern bool restarted;
extern bool keystates[6];

extern clock_t startTime;
extern clock_t lastBubbleCreationTime;
extern clock_t lastItemCreationTime;