/***********************************************************************
* Header File:
*    Largeasteroid
* Author:
*    Brother Macbeth
* Summary: Class description for Largeasteroid
************************************************************************/
#ifndef LARGEASTEROID_H
#define LARGEASTEROID_H

#include <iostream>
#include "rocks.h"
#include "uiDraw.h"
#include "mediumAsteroid.h"
#include "smallAsteroid.h"

class LargeAsteroid : public Rocks
{
private:

public:
	//constructor for large asteroid
	LargeAsteroid();

	//rotate large asteroid
	void rotate();

	// hit Largeasteroid (the reason why datatype is int is that I put score so score should be return)
	int hit();

	//draw Largeasteroid
	void draw();

	//break apart Largeasteroid
	void breakApart(vector <Rocks*> &rocks);
};
#endif