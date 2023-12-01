#include "main.h"

void Input::addLetter(char c)
{
	if (length < 5) {
		name[length] = c;
		length += 1;
		cout << c << " added" << endl;
	}
}

void Input::deleteLastLetter()
{
	if (length >= 1) {
		name[length-1] = ' ';
		length -= 1;
		cout << "deleted" << endl;
	}
}

string Input::getName()
{
	return string(name);
}
