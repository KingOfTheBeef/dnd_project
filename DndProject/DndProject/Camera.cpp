#include "Camera.h"

Camera* Camera::instance = 0;

Camera::Camera(float x, float y, float* target_x, float *target_y) {
	this->xCoord = x;
	this->yCoord = y;
	this->targetX = target_x;
	this->targetY = target_y;
	this->speed = 3;
}

void Camera::update()
{
	if (xCoord < *targetX)
	{
		xCoord += speed;
		if (xCoord > *targetX)
		{
			xCoord = *targetX;
		}
	}
	else if (xCoord > *targetX)
	{
		xCoord -= speed;
		if (xCoord < *targetX)
		{
			xCoord = *targetX;
		}
	}

	if (yCoord < *targetY)
	{
		yCoord += speed;
		if (yCoord > *targetY)
		{
			yCoord = *targetY;
		}
	}
	else if (yCoord > *targetY)
	{
		yCoord -= speed;
		if (yCoord < *targetY)
		{
			yCoord = *targetY;
		}
	}

	//xCoord = (xCoord + *targetX) / 2;
	//yCoord = (yCoord + *targetY) / 2;
}

void Camera::setTargetX(float * x)
{
	targetX = x;
	xCoord = *x;
}

void Camera::setTargetY(float * y)
{
	targetY = y;
	yCoord = *y;
}

void Camera::setX(float x)
{
	xCoord = x;
}

void Camera::setY(float y)
{
	yCoord = y;
}

float Camera::getX()
{
	return xCoord;
}

float Camera::getY()
{
	return yCoord;
}