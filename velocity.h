/***********************************************************************
* Header File:
*    Velocity
* Author:
*    Brother Macbeth
* Summary: Class description for Velocity
************************************************************************/
#ifndef Velocity_H
#define Velocity_H

#include<iostream>

using namespace std;

/*********************************************
* Velocity class
*********************************************/
class Velocity
{
private:
	float Dx;
	float Dy;

public:
	//constructors ( defaut and non default)
	Velocity();
	Velocity(float Dx, float Dy);

	//getters
	float getDx() {
		return Dx;
	}
	float getDy() {
		return Dy;
	}

	//setters
	void setDx(float Dx) 
	{
		this->Dx = Dx;
	}
	void setDy(float Dy) 
	{
		this->Dy = Dy;
	}
};

#endif
