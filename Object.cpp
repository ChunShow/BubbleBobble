#include "Object.h"

Object::Object() {
	position[0] = 0.0f, position[1] = 0.0f;
	velocity[0] = 0.0f, velocity[1] = 0.0f;
}

void Object::setPosition(float x, float y)
{
	position[0] = x; position[1] = y;
}

float* Object::getPosition()
{
	return position;
}

void Object::setPositionX(float x)
{
	position[0] = x;
}

float Object::getPositionX()
{
	return position[0];
}

void Object::setPositionY(float y)
{
	position[1] = y;
}

float Object::getPositionY()
{
	return position[1];
}

void Object::translate(float x, float y)
{
	setPosition(getPositionX() + x, getPositionY() + y);
}

void Object::setVelocity(float v1, float v2)
{
	velocity[0] = v1; velocity[1] = v2;
}

float* Object::getVelocity()
{
	return velocity;
}

void Object::setVelocityX(float v1)
{
	velocity[0] = v1;
}

float Object::getVelocityX()
{
	return velocity[0];
}

void Object::setVelocityY(float v2)
{
	velocity[1] = v2;
}

float Object::getVelocityY()
{
	return velocity[1];
}

bool Object::collisionDetection(Object& other)
{
	float* hitbox1 = getHitbox();
	float* hitbox2 = other.getHitbox();
	
	float xleft1 = hitbox1[0]; float xright1 = hitbox1[2]; float ybottom1 = hitbox1[3]; float ytop1= hitbox1[4];
	float xleft2 = hitbox2[0]; float xright2 = hitbox2[2]; float ybottom2 = hitbox2[3]; float ytop2 = hitbox2[4];

	bool xCollision = ((xleft1 <= xright2) && (xright1 >= xleft2));
	bool yCollision = ((ytop1 >= ybottom2) && (ybottom1 <= ytop2));

	return xCollision && yCollision;
}

float* Object::getHitbox()
{
	float hitbox[4];
	cout << "this method should not be called" << endl;
	return hitbox;
}
