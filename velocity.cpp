#include "velocity.h"
#include <iostream>

using namespace std;

/*********************************************
* Default constructor
*********************************************/
Velocity::Velocity()
{
	setDx(0);
	setDy(0);
}

/*********************************************
* Non-default constructor
*********************************************/
Velocity::Velocity(float Dx, float Dy)
{
	setDx(Dx);
	setDy(Dy);
}

