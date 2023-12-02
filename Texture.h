#pragma once
#include <GL/freeglut.h>
#include <FreeImage.h>

enum TEXTURE { _PLAYER, _MONSTER, _MAP };
enum TEXTURE_BLOCK { _BRICK_RED, _BRICK_BLUE, _BRICK_BLACK, _FIELD_SKY, _GAMEOVER, _TITLE, _GAMEWIN, _HELP, _LEADERBOARD, _TIME, _SCORE, _STAGE, _APPLE, _HEART, _SPEED, _BUBBLE, _DOUBLE };
enum TEXTURE_DIRECTION { _LEFT, _RIGHT };
enum TEXTURE_MOTION { _ATTACK, _DAMAGE, _FALL1, _FALL2, _JUMP, _STAY1, _STAY2, _CLEAR };
enum TEXTURE_MONSTER { _ROBOT, _CREATURE, _GHOST };

class Texture{
public:
	//  constructor
	Texture();
	Texture(TEXTURE type, TEXTURE_BLOCK block);
	Texture(TEXTURE type, TEXTURE_DIRECTION dir, TEXTURE_MOTION motion);
	Texture(TEXTURE type, TEXTURE_MONSTER monster, TEXTURE_DIRECTION dir);

	FIBITMAP* createBitMap(char const* filename);
	void generateTexture();
	void initTexture();
	GLuint getTextureID() const;

	//  .png file path setting
	void setPlayerFile(FIBITMAP*& bitmap);
	void setMonsterFile(FIBITMAP* &bitmacp);
	void setMapFile(FIBITMAP*& bitmap);

private:
	GLuint textureID;
	GLubyte* textureData;
	int imageWidth, imageHeight;
	TEXTURE textureType;
	TEXTURE_BLOCK textureBlock;
	TEXTURE_DIRECTION textureDir;
	TEXTURE_MOTION textureMotion;
	TEXTURE_MONSTER textureMonster;
};