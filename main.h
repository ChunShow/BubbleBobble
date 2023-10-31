#pragma once
#include <GL/freeglut.h>
#include <FreeImage.h>

#include "iostream"
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "keyFunction.h"
#include "Bubble.h"

#include <ctime>

using namespace std;

#define WINDOW_X 400
#define WINDOW_Y 100

#define WINDOW_WIDTH 640		// window's width
#define WINDOW_HEIGHT 640		// window's height

extern Player player;
extern vector<Monster> creature;
extern bool keystates[5];

extern GLuint stoneTexture;
extern GLuint brickTexture;
void initTexture();