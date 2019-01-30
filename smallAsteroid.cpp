#include "smallAsteroid.h"
#include <iostream>

using namespace std;

//default-constructor for small rock size
SmallAsteroid::SmallAsteroid()
{
	rockSize = SMALL_ROCK_SIZE;
}

// break apart
void SmallAsteroid::breakApart(vector <Rocks*> &rocks) {}

//rotate small asteroid
void SmallAsteroid::rotate()
{
	angle = (angle + SMALL_ROCK_SPIN) % 360;
}

//if bullet hit small asteroid, get 5 points
int SmallAsteroid::hit()
{
	alive = false;
	return 5;
}

//draw small asteroid
void SmallAsteroid::draw()
{
	drawSmallAsteroid(point, angle);
}