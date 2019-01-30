/***********************************************************************
* Header File:
*    Mediumasteroid
* Author:
*    Brother Macbeth
* Summary: Class description for Mediumasteroid
************************************************************************/
#ifndef MEDIUMASTEROID_H
#define MEDIUMASTEROID_H

#include <iostream>
#include "rocks.h"
#include "smallAsteroid.h"

class MediumAsteroid : public Rocks
{
private:

public:
	//constructor for MediumAsteroid
	MediumAsteroid();

	//break apart Mediumasteroid
	void breakApart(vector <Rocks*> &rocks);

	// draw Mediumasteroid
	void draw();
	
	// hit Mediumasteroid
	int hit();

	// rotate Mediumasteroid
	void rotate();
};
#endif