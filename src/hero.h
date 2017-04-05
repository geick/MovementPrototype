#pragma once
class hero
{
	public:
		hero();
		~hero();
		void update(world &world);
		void paint();
		void setPosition(int pX, int pY);
		float* getPosition();
        float* getVelocity();
        void setMaxSpeed(float v);
        void resetSpeed();
		int* getGridPosition();
		void move(int direction, bool m);
		void stop();
		void setSize(float s);
		bool triggersScroll(float screenX, float screenY);

	private:
		bool moves[4];
		float position[2];
		int gridPosition[2];
		float velocity[2];
		float acceleration;
		float size;
		float maxSpeed;
        float defaultSpeed;
};

