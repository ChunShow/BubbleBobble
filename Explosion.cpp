#include "Explosion.h"

const float PI = 3.14159265358979323846f;

Explosion::Explosion(float x, float y, bool trapping)
{
	center[0] = x; center[1] = y;
	distance = 0.1f;
	this->trapping = trapping;
	creationTime = clock();
	alive = true;
	Material mtl;
	mtl.setEmission(0.0f, 0.0f, 0.0f, 1.0f);
	mtl.setAmbient(0.0f, 0.1f, 0.06f, 1.0f);
	mtl.setDiffuse(0.0f, 0.5098f, 0.5098f, 1.0f);
	mtl.setSpecular(0.502f, 0.502f, 0.502f, 1.0f);
	mtl.setShininess(32.0f);

	this->mtl = mtl;

	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.getEmission());
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.getAmbient());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.getDiffuse());
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.getSpecular());
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.getShininess());
}

void Explosion::increase(float d)
{
	distance += d;
}

void Explosion::draw()
{
	for (int i = 0; i < 8; i++) {
		srand(i);
		glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
		glPushMatrix();
		glTranslatef(center[0] + distance*cos(i*PI/4), center[1] + distance*sin(i*PI/4), 0.0f);
		glutSolidSphere(radius, 10, 10);
		glPopMatrix();
	}
}

bool Explosion::isAlive()
{
	return clock() - creationTime < lifeTime;
}
