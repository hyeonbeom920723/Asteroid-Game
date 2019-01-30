#include "rocks.h"

// set angle of rocks
void Rocks::setAngle(int angle)
{
	if (angle < 0)
	{
		angle = 360 + angle;
	}

	this->angle = angle % 360;
}