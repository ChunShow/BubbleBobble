#include "Bubble.h"

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

void Bubble::draw()
{
	glPushMatrix();
	glTranslatef(pos[0], pos[1], 0.0f);
	glScalef(size, size, size);
	glutSolidSphere(0.1f, 20, 20);
	glPopMatrix();
}