#include "Texture.h"

Texture::Texture() : textureType(DEFAULT) {}

Texture::Texture(TEXTURE type) : textureType(type) {}

FIBITMAP* Texture::createBitMap(char const* filename) 
{
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

void Texture::generateTexture() 
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight,
		0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, textureData);
}

void Texture::initTexture() 
{
	FIBITMAP* bitmap32;
	setTextureFile(bitmap32);
	imageWidth = FreeImage_GetWidth(bitmap32);
	imageHeight = FreeImage_GetHeight(bitmap32);
	textureData = FreeImage_GetBits(bitmap32);
	generateTexture();
}

//  a texture image file is assigned to a bitmap according to a texture type
void Texture::setTextureFile(FIBITMAP*& bitmap) 
{
	switch (textureType) {
	case GRASS:
		bitmap = createBitMap("texture/grass.png");
		break;
	case LEAF:
		bitmap = createBitMap("texture/leaf.png");
		break;
	case BRICK:
		bitmap = createBitMap("texture/brick1.png");
		break;
	case STONE:
		bitmap = createBitMap("texture/stone2.png");	
		break;
	case FIELD:
		bitmap = createBitMap("texture/field.png");
		break;
	default:
		bitmap = createBitMap("texture/default.png");
		break;
	}
}

GLuint Texture::getTextureID() const 
{
	return textureID;
}
