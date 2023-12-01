#include "main.h"

void Input::addLetter(char c)
{
	if (length < 5) {
		name[length] = c;
		length += 1;
	}
}

void Input::deleteLastLetter()
{
	if (length >= 1) {
		name[length-1] = ' ';
		length -= 1;;
	}
}

string Input::getName()
{
	return string(name);
}

void Input::displayName()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	displayStrokeCharacters(GLUT_STROKE_MONO_ROMAN, getName(), 2.6f, 0.1f, 0.015f, 1 / 1000.0f);
}

void Input::reset()
{
	for (int i = 0; i < 5; i++) name[i] = ' ';
	length = 0;
}
