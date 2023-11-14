#pragma once
#include <GL/freeglut.h>
#include <FreeImage.h>

enum TEXTURE { _PLAYER, _MONSTER, _MAP};
enum TEXTURE_BLOCK { _GRASS, _LEAF, _BRICK, _STONE, _DEFAULT, _FIELD, _GAMEOVER};
enum TEXTURE_DIRECTION { _LEFT, _RIGHT };
enum TEXTURE_MOTION { _ATTACK, _DAMAGE, _FALL1, _FALL2, _JUMP, _STAY1, _STAY2, _CLEAR };

class Texture{
public:
	//  constructor
	Texture();
	Texture(TEXTURE type, TEXTURE_BLOCK block);
	Texture(TEXTURE type, TEXTURE_DIRECTION dir, TEXTURE_MOTION motion);

	FIBITMAP* createBitMap(char const* filename);
	void generateTexture();
	void initTexture();
	void setPlayerFile(FIBITMAP*& bitmap);
	void setMonsterFile(FIBITMAP* &bitmacp);
	void setMapFile(FIBITMAP*& bitmap);
	GLuint getTextureID() const;

private:
	GLuint textureID;
	GLubyte* textureData;
	int imageWidth, imageHeight;
	TEXTURE textureType;
	TEXTURE_BLOCK textureBlock;
	TEXTURE_DIRECTION textureDir;
	TEXTURE_MOTION textureMotion;
};