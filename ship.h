/***********************************************************************
* Header File:
*    Ship
* Author:
*    Hyeonbeom Lee
* Summary:
*    Class description for ship
************************************************************************/
#ifndef ship_h
#define ship_h

#include "flyingObject.h"
#include <cmath>
#include "uiDraw.h"

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5


class Ship : public FlyingObject
{
private:
	//private data
	int angle;
	bool isThrust;
 bool shielded;
 int shieldTime;
 int coolDownTime;

public:
	//default-constructor
  // set ship's values as a default.
	Ship()
	{
		angle = 0;
		isThrust = false;
   shielded = false;
   shieldTime = 50;
   coolDownTime = 0;
	}
	
	// movement
	void move();

	//rotate left and right
	void rotateLeft();
	void rotateRight();

	//draw
	void draw();

	//get angle
	int getAngle();
 // some functions for shield.
 void shieldUp();
 bool isShielded();
 void advance();
 void damageShield();
};

#endif
