#include "Texture.h"
#include <iostream>

Texture::Texture() {}
Texture::Texture(TEXTURE type, TEXTURE_BLOCK block) : textureType(type), textureBlock(block) {}
Texture::Texture(TEXTURE type, TEXTURE_DIRECTION dir, TEXTURE_MOTION motion) : textureType(type), textureDir(dir), textureMotion(motion) {}

FIBITMAP* Texture::createBitMap(char const* filename) {
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);
	if (format == -1) { //  couldn't find image
		exit(-1);
	}
	else if (format == FIF_UNKNOWN) { //  couldn't determine file format
		//  attemp to get from file extension
		format = FreeImage_GetFIFFromFilename(filename);
		if (!FreeImage_FIFSupportsReading(format)) {
			exit(-1);
		}
	}
	FIBITMAP* bitmap = FreeImage_Load(format, filename);
	int bitsPerPixel = FreeImage_GetBPP(bitmap);
	FIBITMAP* bitmap32;
	if (bitsPerPixel == 32) {
		bitmap32 = bitmap;
	}
	else {
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
	}
	return bitmap32;
}
void Texture::generateTexture() {
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight,
		0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, textureData);
}
void Texture::initTexture() {
	FIBITMAP* bitmap32;
	if (textureType == _PLAYER) setPlayerFile(bitmap32);
	else if (textureType == _MONSTER) setMonsterFile(bitmap32);
	else setMapFile(bitmap32);

	imageWidth = FreeImage_GetWidth(bitmap32);
	imageHeight = FreeImage_GetHeight(bitmap32);
	textureData = FreeImage_GetBits(bitmap32);
	generateTexture();
}
GLuint Texture::getTextureID() const {
	return textureID;
}
void Texture::setPlayerFile(FIBITMAP*& bitmap) {
	switch (textureDir) {
	case _RIGHT:
		switch (textureMotion) {
		case _ATTACK:
			bitmap = createBitMap("texture/character/Dragon_right_attack.png");
			break;
		case _DAMAGE:
			bitmap = createBitMap("texture/character/Dragon_right_damage.png");
			break;
		case _FALL1:
			bitmap = createBitMap("texture/character/Dragon_right_fall1.png");
			break;
		case _FALL2:
			bitmap = createBitMap("texture/character/Dragon_right_fall2.png");
			break;
		case _JUMP:
			bitmap = createBitMap("texture/character/Dragon_right_jump.png");
			break;
		case _STAY1:
			bitmap = createBitMap("texture/character/Dragon_right_stay1.png");
			break;
		case _STAY2:
			bitmap = createBitMap("texture/character/Dragon_right_stay2.png");
			break;
		case _CLEAR:
			bitmap = createBitMap("texture/character/Dragon_clearStage.png");
			break;
		default:
			bitmap = createBitMap("texture/character/Dragon_right_stay1.png");
			break;
		}
		break;
	case _LEFT:
		switch (textureMotion) {
		case _ATTACK:
			bitmap = createBitMap("texture/character/Dragon_left_attack.png");
			break;
		case _DAMAGE:
			bitmap = createBitMap("texture/character/Dragon_left_damage.png");
			break;
		case _FALL1:
			bitmap = createBitMap("texture/character/Dragon_left_fall1.png");
			break;
		case _FALL2:
			bitmap = createBitMap("texture/character/Dragon_left_fall2.png");
			break;
		case _JUMP:
			bitmap = createBitMap("texture/character/Dragon_left_jump.png");
			break;
		case _STAY1:
			bitmap = createBitMap("texture/character/Dragon_left_stay1.png");
			break;
		case _STAY2:
			bitmap = createBitMap("texture/character/Dragon_left_stay2.png");
			break;	
		case _CLEAR:
			bitmap = createBitMap("texture/character/Dragon_clearStage.png");
			break;
		default:
			bitmap = createBitMap("texture/character/Dragon_left_stay1.png");
			break;
		}
		break;
	default:
		bitmap = createBitMap("texture/character/Dragon_left_stay1.png");
		break;
	}
}
void Texture::setMonsterFile(FIBITMAP*& bitmap) {
	switch (textureDir) {
	case _RIGHT:
		switch (textureMotion) {
		case _ATTACK:
			bitmap = createBitMap("texture/character/Dragon_right_attack.png");
			break;
		case _DAMAGE:
			bitmap = createBitMap("texture/character/Dragon_right_damage.png");
			break;
		case _FALL1:
			bitmap = createBitMap("texture/character/Dragon_right_fall1.png");
			break;
		case _FALL2:
			bitmap = createBitMap("texture/character/Dragon_right_fall2.png");
			break;
		case _JUMP:
			bitmap = createBitMap("texture/character/Dragon_right_jump.png");
			break;
		case _STAY1:
			bitmap = createBitMap("texture/character/Dragon_right_stay1.png");
			break;
		case _STAY2:
			bitmap = createBitMap("texture/character/Dragon_right_stay2.png");
			break;
		case _CLEAR:
			bitmap = createBitMap("texture/character/Dragon_clearStage.png");
			break;
		default:
			bitmap = createBitMap("texture/character/Dragon_right_stay1.png");
			break;
		}
		break;
	case _LEFT:
		switch (textureMotion) {
		case _ATTACK:
			bitmap = createBitMap("texture/character/Dragon_left_attack.png");
			break;
		case _DAMAGE:
			bitmap = createBitMap("texture/character/Dragon_left_damage.png");
			break;
		case _FALL1:
			bitmap = createBitMap("texture/character/Dragon_left_fall1.png");
			break;
		case _FALL2:
			bitmap = createBitMap("texture/character/Dragon_left_fall2.png");
			break;
		case _JUMP:
			bitmap = createBitMap("texture/character/Dragon_left_jump.png");
			break;
		case _STAY1:
			bitmap = createBitMap("texture/character/Dragon_left_stay1.png");
			break;
		case _STAY2:
			bitmap = createBitMap("texture/character/Dragon_left_stay2.png");
			break;
		case _CLEAR:
			bitmap = createBitMap("texture/character/Dragon_clearStage.png");
			break;
		default:
			bitmap = createBitMap("texture/character/Dragon_left_stay1.png");
			break;
		}
		break;
	default:
		bitmap = createBitMap("texture/character/Dragon_right_stay1.png");
		break;
	}
}
void Texture::setMapFile(FIBITMAP*& bitmap) {
	switch (textureBlock) {
	case _BRICK:
		bitmap = createBitMap("texture/brick1.png");
		break;
	case _STONE:
		bitmap = createBitMap("texture/stone2.png");
		break;
	case _GRASS:
		bitmap = createBitMap("texture/grass.png");
		break;
	case _LEAF:
		bitmap = createBitMap("texture/leaf.png");
		break;
	case _FIELD:
		bitmap = createBitMap("texture/field.png");
		break;
	case _GAMEOVER:
		bitmap = createBitMap("texture/gameover.png");
		break;
	default:
		bitmap = createBitMap("texture/Dragon.png");
		break;
	}
}