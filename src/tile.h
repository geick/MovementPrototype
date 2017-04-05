#pragma once

class tile
{
public:
	tile();
	~tile();
	void setBlocking(bool b);
	bool getBlocking();
	void setTexture(unsigned short t);
	unsigned short getTexture();

private:
	unsigned short texture;
	bool blocking;
};

