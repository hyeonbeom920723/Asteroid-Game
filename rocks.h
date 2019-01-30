/***********************************************************************
* Header File:
*    Rocks
* Author:
*    Hyeonbeom Lee
* Summary:
*    Class description for Rocks
************************************************************************/
#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include <vector>
#include "uiDraw.h"



// Define the following classes here:
class Rocks : public FlyingObject
{
	//protected class description because children classes will use data
protected:
	int angle;
	int rockSize;


public:
	//constructor for Rocks
	Rocks() 
	{
		rockSize = BIG_ROCK_SIZE;
		angle = 0;
	}

	//Gettter
	int getAngle()
	{
		return angle;
	}

	//Setter
	void setAngle(int angle);

	//movement and rotate
	void advance()
	{
		FlyingObject::advance();
		rotate();
	}

	// rotate (this is for large asteroid but medium and small will use this function)
	void virtual rotate()
	{
		angle = (angle + BIG_ROCK_SPIN) % 360;
	}

	// hit function
	int virtual hit() = 0;

	//Get rock size
	int getRockSize()
	{
		return rockSize;
	}

	// break apart to small pieces
	void virtual breakApart(vector <Rocks*> &rocks){}

};
#endif 
