#pragma once
#include <string>

using namespace std;

class Input
{
public:
	void addLetter(char c);
	void deleteLastLetter();
	string getName();
	void displayName();

	void reset();

private:
	char name[5] = {' ', ' ', ' ', ' ', ' ' };
	int length=0;
};

