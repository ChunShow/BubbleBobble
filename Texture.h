#pragma once
#include <GL/freeglut.h>
#include <FreeImage.h>

enum TEXTURE { GRASS, LEAF, BRICK, STONE, DEFAULT, FIELD, GAMEOVER};

class Texture{
public:
	//  constructor
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