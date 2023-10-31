#include "main.h"

GLuint stoneTexture;
GLuint brickTexture;
GLubyte* textureData[2];
int imageWidth[2], imageHeight[2];

FIBITMAP* createBitMap(char const* filename) {
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);
	if (format == -1) { // couldn't find image
		exit(-1);
	}
	else if (format == FIF_UNKNOWN) { // couldn't determine file format
		// attemp to get from file extension
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
void generateTexture(GLuint& textureID, int i) {
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth[i], imageHeight[i],
		0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, textureData[i]);
}
void initTexture() {
	FIBITMAP* stone = createBitMap("texture/stone1.png");
	imageWidth[0] = FreeImage_GetWidth(stone);
	imageHeight[0] = FreeImage_GetHeight(stone);
	textureData[0] = FreeImage_GetBits(stone);
	generateTexture(stoneTexture, 0);

	FIBITMAP* brick = createBitMap("texture/brick1.png");
	imageWidth[1] = FreeImage_GetWidth(brick);
	imageHeight[1] = FreeImage_GetHeight(brick);
	textureData[1] = FreeImage_GetBits(brick);
	generateTexture(brickTexture, 1);
}