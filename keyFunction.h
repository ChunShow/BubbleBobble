#pragma once

#define spacebar 32
#define backspace 8
#define restart 341

void specialKeyDown(int key, int x, int y);
void specialKeyUp(int key, int x, int y);
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);