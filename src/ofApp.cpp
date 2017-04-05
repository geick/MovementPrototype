#include "ofApp.h"

//--------------------------------------------------------------
// Initiate Level, set hero, world and screen position
// check
void ofApp::setup() {
	ofHideCursor();
	resolution = 50;
	unsigned short xCount = round(ofGetWidth() / resolution);

	world.setResolution(resolution);

	worldTiles = world.getDimensions();

	hero.setSize(resolution);
	hero.setPosition(round(worldTiles[0] / 2)*resolution, round(worldTiles[1] / 2)*resolution);

    // Center screen on hero;
    screenX = hero.getPosition()[0] - ofGetWidth() / 2;
    screenY = hero.getPosition()[1] - ofGetHeight() / 2;
}

//--------------------------------------------------------------
// Apply changes in world, characters and other objects
void ofApp::update() {
	hero.update(world);

    if (screenX > 0 && screenY > 0 && hero.triggersScroll(screenX, screenY)) {
    float* hVel = hero.getVelocity();
        screenX += hVel[0];
        screenY += hVel[1];
    }
}

//--------------------------------------------------------------
// Display all the things!
void ofApp::draw() {
	ofClear(0);
	ofPushMatrix();
	    ofTranslate(-screenX, -screenY);
	    world.paint(screenX, screenY);
	    hero.paint();
	ofPopMatrix();

    cout << "fps: " << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
// General keyboard input
void ofApp::keyPressed(int key) {
	switch (key) {
	case 'w':
		hero.move(0, true);
		break;
	case 's':
		hero.move(1, true);
		break;
	case 'a':
		hero.move(2, true);
		break;
	case 'd':
		hero.move(3, true);
		break;
    case 'e':
        hero.setMaxSpeed(5);
        break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	switch (key) {
		case 'w':
			hero.move(0, false);
			break;
		case 's':
			hero.move(1, false);
			break;
		case 'a':
			hero.move(2, false);
			break;
		case 'd':
			hero.move(3, false);
			break;
        case 'e':
            hero.resetSpeed();
            break;
		default:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
