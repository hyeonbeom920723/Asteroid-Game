/***********************************************************************
* Header File:
*    Smallasteroid
* Author:
*    Brother Macbeth
* Summary: Class description for Smallasteroid
************************************************************************/
#ifndef SMALLASTEROID_H
#define SMALLASTEROID_H

#include <iostream>
#include "rocks.h"

class SmallAsteroid : public Rocks
{
private:

public:
	// constructor
	SmallAsteroid();

	//break apart for Smallasteroid
	void breakApart(vector <Rocks*> &rocks);

	//draw Smallasteroid
	void draw();

	//hit Smallasteroid
	int hit();
	
	//rotate Smallasteroid
	void rotate();
};
#endif