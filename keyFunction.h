#pragma once

#define spacebar 32
#define BACKSPACE 8
#define restart 341
#define ENTER 13

void specialKeyDown(int key, int x, int y);
void specialKeyUp(int key, int x, int y);
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);