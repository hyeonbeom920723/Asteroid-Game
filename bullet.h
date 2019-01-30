/***********************************************************************
* Header File:
*    Bullet
* Author:
*    Brother Macbeth
* Summary: Class description for Bullet
************************************************************************/

#ifndef BOOLLET_H
#define BOOLLET_H

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"
#include "uiDraw.h"
#include "point.h"
#include "velocity.h"

using namespace std;

class Bullet : public FlyingObject
{
public:
	// constructor
	Bullet();

	// shoot bullets
	void fire(Point point, float angle);

	// draw bullets
	void draw();
	
	//movement
	void advance();

private:
  // BULLET LIFE
	int frameLived;

};

#endif