#include "main.h"

using namespace std;

Bubble::Bubble()
{
	capturing = false;
	velocity[0] = 0.09f;
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
	return (position[0] - getRadius() < -0.95f || position[0] + getRadius() > 0.95f);
}

bool Bubble::checkUpperBoundary()
{
	return (position[1] > 1.0f);
}

bool Bubble::isGrown()
{
	return size == 1.0f;
}

bool Bubble::isCapturing()
{
	return capturing;
}

bool Bubble::characterCollisionCheck(float hitbox[2][2])
{
	if (isGrown()) return false;
	float boxCenterX = (hitbox[0][0] + hitbox[0][1]) / 2;
	float boxCenterY = (hitbox[1][0] + hitbox[1][1]) / 2;
	float boxLengthX = (hitbox[0][1] - hitbox[0][0]) / 2;
	float boxLengthY = (hitbox[1][1] - hitbox[1][0]) / 2;
	return (std::abs(position[0] - boxCenterX) < (boxLengthX+0.05) && std::abs(position[1] - boxCenterY) < (boxLengthY+0.05));
}

bool Bubble::mapCollision(vector<vector<float>> borderHard)
{
	float x, y, width, height;
	float r = getRadius();
	float b_x=0.0f, b_y=0.0f;
	for (const auto& border : borderHard) {
		x = border[0]; y = border[1]; width = border[2]; height = border[3];
		b_x = position[0]; b_y = position[1];
		if (y - height - r < b_y && b_y  < y + r) {
			if (x - r < b_x && b_x< x + width + r) {
				switch (direction) {
				case(D_LEFT):
					size = 1.0f;
					position[0] = x + width + max_radius;
					return true;
				case(D_RIGHT):
					size = 1.0f;
					position[0] = x - max_radius;
					return true;
				case(D_UP):
					position[1] = y - height - max_radius;
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

float* Bubble::getHitBox()
{
	float r = getRadius();
	float hitbox[4] = { position[0] - r, position[0] + r, position[1] - r, position[1] + r };
	return hitbox;
}

clock_t Bubble::getCreatedTime()
{
	return createdTime;
}

void Bubble::draw()
{
	glPushMatrix();
	glTranslatef(position[0], position[1], 0.0f);
	glScalef(size, size, size);
	glutSolidSphere(max_radius, 20, 20);
	glPopMatrix();
}