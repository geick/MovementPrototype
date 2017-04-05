#include "ofApp.h"
#include "hero.h"
#include "world.h"

hero::hero()
{
	// NORTH, SOUTH, WEST, EAST
	for (int i = 0; i < 4; i++) {
		moves[i] = false;
	}
	velocity[0] = 0;
	velocity[1] = 0;
	acceleration = 0.45;
    defaultSpeed = 1.5;
    maxSpeed = defaultSpeed;
}

hero::~hero()
{
}

void hero::update(world &world) {
    cout << world.getDimensions()[0] << endl;
	bool moving = false;

	// NORTH
	if (moves[0]) {
		if (velocity[1] > -maxSpeed) {
			velocity[1] -= acceleration;
		} else {
            velocity[1] += acceleration;
        }
	} else if (velocity[1] < 0) {
		velocity[1] = 0;
	}

	// SOUTH
	if (moves[1]) {
		if (velocity[1] < maxSpeed) {
			velocity[1] += acceleration;
		} else {
            velocity[1] -= acceleration;
        }
	} else if (velocity[1] > 0) {
		velocity[1] = 0;
	}

	// WEST
	if (moves[2]) {
		if (velocity[0] > -maxSpeed) {
			velocity[0] -= acceleration;
		} else {
            velocity[0] += acceleration;
        }
	}
	else if (velocity[0] < 0) {
		velocity[0] = 0;
	}

	// EAST
	if (moves[3]) {
		if (velocity[0] < maxSpeed) {
			velocity[0] += acceleration;
		} else {
            velocity[0] -= acceleration;
        }
	} else if (velocity[0] > 0) {
		velocity[0] = 0;
	}

	if (velocity[0] == 0 && velocity[1] == 0) {
		stop();
	}

    // Collision detection

    if (!world.characterCanMoveTo(position, getGridPosition(), velocity, 0)) {
        velocity[1] = 0;
        moves[0] = false;
    }
    if (!world.characterCanMoveTo(position, getGridPosition(), velocity, 2)) {
        velocity[1] = 0;
        moves[2] = false;
    }
    if (!world.characterCanMoveTo(position, getGridPosition(), velocity, 1)) {
        velocity[0] = 0;
        moves[1] = false;
    }
    if (!world.characterCanMoveTo(position, getGridPosition(), velocity, 3)) {
        velocity[0] = 0;
        moves[3] = false;
    }

	position[0] += round(velocity[0]);
	position[1] += round(velocity[1]);
}

void hero::setSize(float s) {
	size = s;
}

void hero::setPosition(int pX, int pY) {
	position[0] = pX;
	position[1] = pY;
}

float* hero::getPosition() {
	return position;
}

float* hero::getVelocity() {
    return velocity;
}

int* hero::getGridPosition() {
	gridPosition[0] = round(position[0] / size);
	gridPosition[1] = round(position[1] / size);

	return gridPosition;
}

void hero::move(int direction, bool m) {
	moves[direction] = m;
}

// TODO smoother stopping
void hero::stop() {
	velocity[0] = 0;
	velocity[1] = 0;
	moves[0] = 0;
	moves[1] = 0;
}

void hero::setMaxSpeed(float v) {
    maxSpeed = v;
}

void hero::resetSpeed() {
    maxSpeed = defaultSpeed;
}


bool hero::triggersScroll(float screenX, float screenY) {
	if (position[0] <= screenX + ofGetWidth()/3
		|| position[0] >= screenX + ofGetWidth() - ofGetWidth() / 3
		|| position[1] <= screenY + ofGetHeight()/3
		|| position[1] >= screenY + ofGetHeight() - ofGetHeight()/3) {
		return true;
	}

	return false;
}

void hero::paint() {
    //cout << "h: " << position[0] << ";" << position[1] << endl;
    //cout << "v: " << velocity[0] << ";" << velocity[1] << endl;

	//ofSetColor(255, 255, 255);
	//getGridPosition();
	//ofRect(gridPosition[0] * size, gridPosition[1] * size, size, size);

	ofSetColor(255, 0, 0);
	ofRect(position[0], position[1], size, size);
}