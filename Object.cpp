#include "Object.h"

void Object::setPosition(float x, float y)
{
	position[0] = x; position[1] = y;
}

void Object::setVelocity(float v1, float v2)
{
	velocity[0] = v1; velocity[1] = v2;
}

bool Object::collisionDetection(Object obj1, Object obj2)
{
	float* hitbox1 = obj1.getHitbox();
	float* hitbox2 = obj2.getHitbox();
	
	float xleft1 = hitbox1[0]; float xright1 = hitbox1[2]; float ybottom1 = hitbox1[3]; float ytop1= hitbox1[4];
	float xleft2 = hitbox1[0]; float xright2 = hitbox1[2]; float ybottom2 = hitbox1[3]; float ytop2 = hitbox1[4];

	bool xCollision = (xleft1 <= xright2) && (xright1 >= xleft2);
	bool yCollision = (ytop1 >= ybottom2) && (ybottom1 <= ytop2);

	return xCollision && yCollision;
}

float* Object::getHitbox()
{
	float hitbox[4];
	cout << "this method must be overrided" << endl;
	return hitbox;
}
