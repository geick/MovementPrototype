#include "ofApp.h"
#include "world.h"
#include "tile.h"

world::world()
{
	mapImage.loadImage("maps/world.png");
	mapPixels = mapImage.getPixels();

	xCount = mapImage.getWidth();
	yCount = mapImage.getHeight();

	tiles = new tile*[xCount];
	int i = 0;
	for (int x = 0; x < xCount; x++) {
		tiles[x] = new tile[yCount];

		for (int y = 0; y < yCount; y++) {
			ofColor color = mapImage.getColor(x, y);

			float brightness = color.getBrightness();
			if (brightness <= 127) {
				tiles[x][y].setBlocking(true);
			} else {
				tiles[x][y].setBlocking(false);
				tiles[x][y].setTexture(1);
			}

			i++;
		}
	}

	//textures = new ofImage[10];
	//textures[0].load("textures/terrain/00.png");
	//textures[1].load("textures/terrain/01.png");
}

world::~world()
{
}

void world::setResolution(float res) {
	resolution = res;
}

short* world::getDimensions() {
	short* dimensions = new short[2];
	dimensions[0] = mapImage.getWidth();
	dimensions[1] = mapImage.getHeight();
	return dimensions;
}

bool world::isBlocked(int pX, int pY) {
	if (tiles[pX][pY].getBlocking()) {
		return true;
	} else {
		return false;
	}
}

bool world::characterCanMoveTo(float* hPos, int* gridPos, float* hVel, int dir) {
    float x = hPos[0] + hVel[0];
    float y = hPos[1] + hVel[1];

    if (dir == 0 && hVel[1] < 0) {          // NORTH
        if (y < gridPos[1]*resolution // Below upper Tile border
            && (isBlocked(gridPos[0], gridPos[1]-1) // Center Tile has to be clear
                || (isBlocked(gridPos[0]-1, gridPos[1]-1) && x < gridPos[0]*resolution) // Left Tile
                || (isBlocked(gridPos[0]+1, gridPos[1]-1) && x > gridPos[0]*resolution) // Right Tile
                )
            ) {
                cout << "can't move north" << endl;
                return false;
        }
    } else if (hVel[1] > 0) {   // SOUTH
        if (y > gridPos[1]*resolution // Above lower Tile border
            && (isBlocked(gridPos[0], gridPos[1]+1) // Center Tile has to be clear
                || (isBlocked(gridPos[0]-1, gridPos[1]+1) && x < gridPos[0]*resolution) // Left Tile
                || (isBlocked(gridPos[0]+1, gridPos[1]+1) && x > gridPos[0]*resolution) // Right Tile
                )
            ) {
                cout << "can't move south" << endl;
                return false;
        }
    } else if (hVel[0] < 0) {   // WEST
        if (x < gridPos[0]*resolution // Behind western Tile border
            && (isBlocked(gridPos[0]-1, gridPos[1]) // Center Tile has to be clear
                || (isBlocked(gridPos[0]-1, gridPos[1]-1) && y < gridPos[1]*resolution) // Upper Tile
                || (isBlocked(gridPos[0]-1, gridPos[1]+1) && y > gridPos[1]*resolution) // Lower Tile
                )
            ) {
                cout << "can't move west" << endl;
                return false;
        }
    } else if (hVel[0] > 0) {   // EAST
        if (x > gridPos[0]*resolution // Before eastern Tile border
            && (isBlocked(gridPos[0]+1, gridPos[1]) // Center Tile has to be clear
                || (isBlocked(gridPos[0]+1, gridPos[1]-1) && y < gridPos[1]*resolution) // Upper Tile
                || (isBlocked(gridPos[0]+1, gridPos[1]+1) && y > gridPos[1]*resolution) // Lower Tile
                )
            ) {
                cout << "can't move east" << endl;
                return false;
        }
    }

    return true;
}

void world::paint(unsigned short sX, unsigned short sY) {
	unsigned short t;
	ofTexture texture;
	int i = 0;

	for (int x = 0; x*resolution < sX + ofGetWidth(); x++) {
		for (int y = 0; y*resolution < sY + ofGetHeight(); y++) {
			if ((x+1)*resolution > sX && x*resolution < sX + ofGetWidth() && (y+1)*resolution > sY && y*resolution < sY + ofGetHeight()) {
				t = tiles[x][y].getTexture();
				ofSetColor(0, t * 125, 0);
				ofRect(x*resolution, y*resolution, resolution, resolution);
                //ofSetColor(255, 0, 0);
                //ofDrawBitmapString(x, x*resolution, y*resolution + 20);
                //ofDrawBitmapString(y, x*resolution + 25, y*resolution + 20);
			}
		}
	}
}