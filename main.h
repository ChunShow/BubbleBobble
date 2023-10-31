#pragma once
#include <GL/freeglut.h>
using namespace std;

#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "keyFunction.h"
#include "Bubble.h"

#define WINDOW_X 400
#define WINDOW_Y 100

#define WINDOW_WIDTH 640		// window's width
#define WINDOW_HEIGHT 640		// window's height

extern Player player;
extern bool keystates[5];