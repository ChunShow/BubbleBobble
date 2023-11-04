#include "main.h"

using namespace std;

Bubble::Bubble()
{
	capturing = false;
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

	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.shininess);

	setSize(1.0);
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

bool Bubble::isCapturing()
{
	return capturing;
}

bool Bubble::mapCollision(vector<vector<float>> borderHard)
{
	float x, y, width, height;
	float r = getRadius();
	float b_x=0.0f, b_y=0.0f;
	for (const auto& border : borderHard) {
		x = border[0]; y = border[1]; width = border[2]; height = border[3];
		b_x = getPositionX(); b_y = getPositionY();
		if (y - height - r < b_y && b_y  < y + r) {
			if (x - r < b_x && b_x< x + width + r) {
				switch (direction) {
				case(D_LEFT):
					size = 1.0f;
					setPositionX(x + width + max_radius);
					return true;
				case(D_RIGHT):
					size = 1.0f;
					setPositionX( x - max_radius);
					return true;
				case(D_UP):
					setPositionY(y - height - max_radius);
					return true;
				}
			}
		}
	}
	return false;
}

float Bubble::getRadius()
{
	return size * max_radius;
}

float* Bubble::getHitbox()
{
	float r = getRadius();
	float hitbox[4] = { getPositionX() - r,  getPositionX() + r, getPositionY() - r, getPositionY() + r };
	return hitbox;
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