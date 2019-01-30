/***********************************************************************
* Header File:
*    FlyingObject
* Author:
*    Brother Macbeth
* Summary: Class description for FlyingObject(Rocks ship bullets)
*		   Have all common requirment for rocks, ship and bullets
************************************************************************/
#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

using namespace std;

#include "point.h"
#include "velocity.h"

class FlyingObject
{
	// Put protected instead of private to let children classes to use values
  protected:
    Point point;
    Velocity velocity;
    bool alive;
    
  public:
	  //constructor and make alive is true
     FlyingObject()
	{
		 alive = true;
	}
	 // getters
    Point getPoint() const {return point;}
    Velocity getVelocity() const {return velocity;}
	
	// Determine if objects are alive or not
    bool isAlive(){return alive;}

	//setters
	void setAlive(bool isAlive) { this->alive = alive; }
    void setPoint(Point point){this->point = point;}
    void setVelocity(Velocity velocity){this->velocity = velocity;}

	// movement
	void virtual advance();
	
	// virtual function
	// draw objects
	void virtual draw() = 0;

	// kill function and make alive to false.
    void kill(){alive = false;}
};

#endif

