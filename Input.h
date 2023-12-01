#pragma once
#include <string>

using namespace std;


class Input
{
public:
	void addLetter(char c);
	void deleteLastLetter();
	string getName();

private:
	char name[5] = {' ', ' ', ' ', ' ', ' ' };
	int length=0;
};

