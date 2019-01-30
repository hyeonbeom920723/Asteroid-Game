/*********************************************************************
 * File: game.h
 * Description: The game of Asteroid. This class holds each piece
 *  of the game. It also has methods that make the game happen (advance, interact, etc.)
 *********************************************************************/

#ifndef GAME_H
#define GAME_H
#include "point.h"
#include "velocity.h"
#include "uiInteract.h"
#include <vector>
#include "rocks.h"
#include "uiDraw.h"
#include "largeAsteroid.h"
#include "ship.h"
#include <list>
#include "bullet.h"

 /*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
private:
	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;

	//Rocks vectors and pointers
	vector<Rocks*> rocks;

	//ship(rocket)
	Ship rocket;

	//bullets
	list<Bullet> bullets;

	//WrapPoint (if flyingobject is out of -200 and 200 it will be wrap on the screen)
	Point wrapPoint(Point location);

	//number of life for ship
	int numLife;

	//respond time for ship
	int respondTime;

	//score
	int score;

public:
	/*********************************************
	* Constructor
	* Initializes the game
	*********************************************/
	Game(Point tl, Point br);

	/*********************************************
	* Function: advance
	* Description: Move everything forward one
	*  step in time.
	*********************************************/
	void advance();

	/*********************************************
	* Function: handleInput
	* Description: Takes actions according to whatever
	*  keys the user has pressed.
	*********************************************/
	void handleInput(const Interface pUI);

	/*********************************************
	* Function: draw
	* Description: draws everything for the game.
	*********************************************/
	void draw(const Interface pUI);

	/*********************************************
	* Function: getCloseDistance
	* Description: if rocks and bullet is whthin
	*				a certain distance, we can consider rocks dead
	*********************************************/
	float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;

	/*********************************************
	* Function: CreatRocks
	* Description: Create Rocks
	*********************************************/
	Rocks* createRocks();

	/*********************************************
	* Function: cleanUpZombies
	* Description: clean and delete dead flyingObjects
	*********************************************/
	void cleanUpZombies();

	/*********************************************
	* Function:handleCollisions
	* Description: Handle everything about collisions
	*********************************************/
	void handleCollisions();
 
 	/*********************************************
	* Function:restartGame
  * Restart game
	*********************************************/
	void restartGame();
};



#endif /* GAME_H */
