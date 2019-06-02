#pragma once

class Camera
{
private:
	float xCoord, yCoord, *targetX, *targetY, speed;

	static Camera *instance;

public:

	static Camera* Instance()
	{
		if (instance == 0)
		{
			instance = new Camera(0, 0, 0, 0);
		}
		return instance;
	}

	Camera(float x, float y, float* target_x, float *target_y);
	Camera() : Camera(0.0f, 0.0f, new float(0.0), new float(0.0)) {};


	void update();
	void setTargetX(float* x);
	void setTargetY(float* y);

	void setX(float x);
	void setY(float y);

	float getX();
	float getY();
};