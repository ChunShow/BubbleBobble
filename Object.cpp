#include "Object.h"

//  constructor
Object::Object() {
	position[0] = 0.0f, position[1] = 0.0f;
	velocity[0] = 0.0f, velocity[1] = 0.0f;
}

//  position methods
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

//  velocity methods
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

Hitbox Object::getHitbox()
{
	Hitbox hitbox = Hitbox(0.0f, 0.0f, 0.0f, 0.0f);
	return hitbox;
}

void Object::translate(float x, float y)
{
	setPosition(getPositionX() + x, getPositionY() + y);
}

bool Object::collisionDetection(Object& other)
{
	Hitbox hitbox1 = getHitbox();
	Hitbox hitbox2 = other.getHitbox();

	return hitbox1.collisionDetection(hitbox2);
}