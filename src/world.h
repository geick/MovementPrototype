#pragma once
#include "tile.h"

class world
{
	public:
		world();
		~world();

		void paint(unsigned short sX, unsigned short sY);
		void setResolution(float res);
		void move(float vX, float vY);
		short* getDimensions();
		bool isBlocked(int pX, int pY);
        bool characterCanMoveTo(float* hPos, int* gridPos, float* hVel, int dir);

	private:
		unsigned char xCount, yCount;
		float resolution;
		ofImage mapImage;
		ofPixels mapPixels;
		tile** tiles;
		ofImage* textures;
};

