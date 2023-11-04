#pragma once
class Hitbox
{
public:
	Hitbox(float xl, float xr, float yb, float yt);
	bool collisionDetection(Hitbox other);
private:
	float xLeft; float xRight; float yBottom; float yTop;
};

