#include "main.h"

using namespace std;

Bubble::Bubble()
{
	trapping = false;
	alive = true;
}

void Bubble::setMaterial(Material m)
{
	mtl = m;
}

void Bubble::setSize(float s) {
	size = s;
}

void Bubble::setDirection(DIRECT k) {
	direction = k;
}

void Bubble::initialize()
{
	Material mtl;
	mtl.setEmission(0.0f, 0.0f, 0.0f, 1.0f);
	mtl.setAmbient(0.0f, 0.1f, 0.06f, 1.0f);
	mtl.setDiffuse(0.0f, 0.5098f, 0.5098f, 1.0f);
	mtl.setSpecular(0.502f, 0.502f, 0.502f, 1.0f);
	mtl.setShininess(32.0f);

	setMaterial(mtl);

	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.getEmission());
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.getAmbient());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.getDiffuse());
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.getSpecular());
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.getShininess());

	setSize(1.0);
}

void Bubble::grow()
{
	setSize(min(size + 0.1f, 1.0f));
}

bool Bubble::checkVerticalBoundary()
{
	return (getPositionX() - getRadius() < -0.95f || getPositionX() + getRadius() > 0.95f);
}

bool Bubble::checkUpperBoundary()
{
	return (getPositionY() > 1.0f);
}

bool Bubble::isGrown()
{
	return size == 1.0f;
}

bool Bubble::isTrapping()
{
	return trapping;
}

bool Bubble::isAlive()
{
	return alive;
}

void Bubble::kill()
{
	alive = false;
}

bool Bubble::mapCollision(vector<vector<float>> borderHard)
{
	float x, y, width, height;
	float r = getRadius();
	float b_x=0.0f, b_y=0.0f;

	for (const auto& border : borderHard) {

		float xLeft = border[0]; float yTop = border[1];
		float xRight = xLeft + border[2]; float yBottom = yTop - border[3];

		float bb_x = getPositionX(); float bb_y = getPositionY();

		if (getHitbox().collisionDetection(Hitbox(border))) {
			size = 1.0f;
			switch (direction) {
			case (D_LEFT):
				if (bb_y - max_radius < yBottom && yBottom < bb_y + max_radius) setPositionY(yBottom - max_radius);
				else setPositionX(xRight + max_radius);
				return true;
			case (D_RIGHT):
				if (bb_y - max_radius < yBottom && yBottom < bb_y + max_radius) setPositionY(yBottom - max_radius);
				else setPositionX(xLeft - max_radius);
				return true;
			case (D_UP):
				setPositionY(yBottom - max_radius);
				return true;
			}
		}
	}
	return false;
}

float Bubble::getRadius()
{
	return size * max_radius;
}

Hitbox Bubble::getHitbox()
{
	float r = getRadius();
	return Hitbox(getPositionX() - r,  getPositionX() + r, getPositionY() - r, getPositionY() + r);
}

clock_t Bubble::getCreatedTime()
{
	return createdTime;
}

void Bubble::draw()
{
	glPushMatrix();
	glTranslatef(getPositionX(), getPositionY(), 0.0f);
	glScalef(size, size, size);
	glutSolidSphere(max_radius, 20, 20);
	glPopMatrix();
}