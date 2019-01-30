#include "mediumAsteroid.h"
#include <iostream>

using namespace std;

//default constructor
// set medium asteroid's default values(rock size)
MediumAsteroid::MediumAsteroid()
{
	rockSize = MEDIUM_ROCK_SIZE;
}

// break MediumAsteroid according to the game rule (two small asteroids)
void MediumAsteroid::breakApart(vector <Rocks*> &rocks)
{
	Rocks* temp = new SmallAsteroid();
	temp->setPoint(getPoint());
	Velocity v = getVelocity();
	v.setDx(v.getDx() + 3);
	temp->setVelocity(v);
	rocks.push_back(temp);

	temp = new SmallAsteroid();
	temp->setPoint(getPoint());
	v = getVelocity();
	v.setDx(v.getDx() - 3);
	temp->setVelocity(v);
	rocks.push_back(temp);
}

//rotate MediumAsteroid
void MediumAsteroid::rotate()
{
	angle = (angle + MEDIUM_ROCK_SPIN) % 360;
}

// if bullet hit MediumAsteroid return 3 points
int MediumAsteroid::hit()
{
	alive = false;
	return 3;

}

//draw MediumAsteroid
void MediumAsteroid::draw()
{
	drawMediumAsteroid(point, angle);
}