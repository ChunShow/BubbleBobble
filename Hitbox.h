#pragma once
#include <vector>
using namespace std;

class Hitbox
{
public:
	Hitbox(float xl, float xr, float yb, float yt);
	Hitbox(vector<float> borderBox); //the length must be 4
	bool collisionDetection(Hitbox other);

private:
	float xLeft; float xRight; float yBottom; float yTop;
};