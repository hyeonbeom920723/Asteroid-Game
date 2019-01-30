#include "flyingObject.h"
#include "point.h"
#include "velocity.h"
#include <iostream>

using namespace std;

/*************************************************************************
* Advance function. This is for all flyingObjects (rocks ship bullets)
*************************************************************************/
void FlyingObject::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}
