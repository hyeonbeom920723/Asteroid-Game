#include "largeAsteroid.h"
#include <iostream>

using namespace std;

//constructor
LargeAsteroid::LargeAsteroid()
{
	rockSize = BIG_ROCK_SIZE;
}
// if bullet hit a large asteroid set alive to false and return 1 point
int LargeAsteroid::hit()
{
	alive = false;
	return 1;
}

//draw large asteroid
void LargeAsteroid::draw()
{
	drawLargeAsteroid(point, angle);
}

//rotate large asteroid accroding to the game rule
void LargeAsteroid::rotate() 
{
	angle = (angle + BIG_ROCK_SPIN) % 360;
}


//break large asteroid apart according to the game rule (two medium asteroid and one small)
void LargeAsteroid::breakApart(vector <Rocks*> &rocks)
{
	Rocks* temp = new MediumAsteroid();
	temp->setPoint(getPoint());
	Velocity v = getVelocity();
	v.setDy(v.getDy() + 1);
	temp->setVelocity(v);
	rocks.push_back(temp);

	temp = new MediumAsteroid();
	temp->setPoint(getPoint());
	Velocity v1 = getVelocity();
	v1.setDy(v1.getDy() - 1);
	temp->setVelocity(v1);
	rocks.push_back(temp);

	temp = new SmallAsteroid();
	temp->setPoint(getPoint());
	Velocity v2 = getVelocity();
	v2.setDx(v2.getDx() + 2);
	temp->setVelocity(v2);
	rocks.push_back(temp);
}