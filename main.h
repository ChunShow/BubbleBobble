#pragma once
#include <GL/freeglut.h>

#include "iostream"
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "Bubble.h"

#include "keyFunction.h"
#include "Idle.h"

using namespace std;

#define WINDOW_X 400
#define WINDOW_Y 100
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

extern Player player;
extern Player* playerPointer;

extern vector<Map> stages;
extern vector<Bubble> bubbles;
extern vector<Monster> monsters;

extern int level;
extern bool clear;
extern bool keystates[5];

extern clock_t startTime;
extern clock_t lastCreationTime;