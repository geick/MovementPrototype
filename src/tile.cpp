#include "ofApp.h"
#include "tile.h"

tile::tile()
{
	texture = 0;
}

tile::~tile()
{
}

void tile::setBlocking(bool b) {
	blocking = b;
}

bool tile::getBlocking() {
	return blocking;
}

void tile::setTexture(unsigned short t) {
	texture = t;
}

unsigned short tile::getTexture() {
	return texture;
}