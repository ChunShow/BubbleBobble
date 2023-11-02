#pragma once
#include <GL/freeglut.h>
#include <FreeImage.h>

enum TEXTURE { BRICK, STONE, DEFAULT };

class Texture{
public:
	Texture();
	Texture(TEXTURE type);
	FIBITMAP* createBitMap(char const* filename);
	void generateTexture();
	void initTexture();
	void setTextureFile(FIBITMAP* &bitmap);
	GLuint getTextureID() const;

private:
	GLuint textureID;
	GLubyte* textureData;
	int imageWidth, imageHeight;
	TEXTURE textureType;
};