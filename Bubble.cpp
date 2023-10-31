#include "main.h"

Bubble::Bubble()
{
	capturing = false;
}

void Bubble::setPos(float x, float y)
{
	pos[0] = x; pos[1] = y;
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
	mtl.setAmbient(0.0215f, 0.1745f, 0.0215f, 0.55f);
	mtl.setDiffuse(0.07568f, 0.61424f, 0.07568f, 0.55f);
	mtl.setSpecular(0.633f, 0.727811f, 0.633f, 0.55f);
	mtl.setShininess(76.8f);

	setMaterial(mtl);

	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.shininess);

	setPos(0.0f, 0.0f);
	setSize(1.0);
}

bool Bubble::checkVerticalBoundary()
{
	return (pos[0] - size * 0.1 < -0.95f || pos[0] + size * 0.1 > 0.95f);
}

bool Bubble::checkUpperBoundary()
{
	float radius = size * 0.1;
	return (pos[1] > 1.0f);
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
	float radius = size * 0.1;
	return (std::abs(pos[0] - boxCenterX) < (boxLengthX+0.05) && std::abs(pos[1] - boxCenterY) < (boxLengthY+0.05));
}

void Bubble::draw()
{
	glPushMatrix();
	glTranslatef(pos[0], pos[1], 0.0f);
	glScalef(size, size, size);
	glutSolidSphere(0.1f, 20, 20);
	glPopMatrix();
}