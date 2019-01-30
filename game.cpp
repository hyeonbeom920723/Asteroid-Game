/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include "game.h"
using namespace std;


/*********************************************
* Constructor
* Initializes the game
*********************************************/
Game::Game(Point tl, Point br)
{
	topLeft = tl;
	bottomRight = br;
	numLife = 3;
	respondTime = 0;
	score = 0;

	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
}


/***************************************
* GAME :: ADVANCE
* advance the game one unit of time
* Also, put some extended functions such as respond time
***************************************/
void Game::advance()
{
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i] != NULL && rocks[i]->isAlive())
		{
			rocks[i]->advance();
			rocks[i]->setPoint(wrapPoint(rocks[i] -> getPoint()));
		}
	}
	if (rocket.isAlive())
	{
		rocket.advance();
		rocket.setPoint(wrapPoint(rocket.getPoint()));
	}
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
	{
		if (it -> isAlive())
		{
			it->advance();
			it->setPoint(wrapPoint(it->getPoint()));
		}
	}

	handleCollisions();
	cleanUpZombies();
	if (respondTime <= 0 && numLife > 0 && !rocket.isAlive())
	{
		rocket = Ship();
	}
	else if(numLife > 0 && !rocket.isAlive())
	{
		respondTime--;
	}
}

/***************************************
* GAME :: WrapPoint
* Wrap objects around the screen
***************************************/
Point Game :: wrapPoint(Point location)
{
	if (location.getX() > 200)
	{
		location.setX(location.getX() - 400);
	}
	else if(location.getX() < -200)
	{
		location.setX(location.getX() + 400);
	}

	if (location.getY() > 200)
	{
		location.setY(location.getY() - 400);
	}
	else if (location.getY() < -200)
	{
		location.setY(location.getY() + 400);
	}
	return location;
}

/***************************************
* GAME :: HANDLE INPUT
* accept input from the user
***************************************/
void Game::handleInput(const Interface pUI)
{
	if (pUI.isLeft())
	{
		rocket.rotateLeft();
	}

	if (pUI.isRight())
	{
		rocket.rotateRight();
	}

	if (pUI.isUp())
	{
		rocket.move();
	}

	if (pUI.isSpace() && rocket.isAlive())
	{
		Bullet newBullet;
		newBullet.fire(rocket.getPoint(), rocket.getAngle());

		bullets.push_back(newBullet);
	}

if (rocket.isAlive() && pUI.isDown())
{
  rocket.shieldUp();
}

	if (!rocket.isAlive() && numLife == 0)
	{
		drawText(Point(-50, 0), "Type Down Key to play one more time!!");

		if (pUI.isDown())
		{
			restartGame();
		}
	}
}

/*********************************************
* GAME :: DRAW
* Draw everything on the screen
*********************************************/
void Game::draw(const Interface pUI)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i] != NULL && rocks[i]->isAlive())
		{
			rocks[i]->draw();
		}
	}

	if (rocket.isAlive())
	{
		rocket.draw();
	}

	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
	{
		if (it->isAlive())
		{
			it->draw();
		}
	}

	if (numLife > 2)
	{
		drawShip(Point(-180 , 180), 0, false);
	}
	if (numLife > 1)
	{
		drawShip(Point(-160,180),0, false);
	}
	if (numLife > 0)
	{
		drawShip(Point(-140, 180), 0, false);
	}

	drawNumber(Point(0, 180), score);
}

/**************************************************************************
* GAME :: CREATE Rocks
* Create a Large rocks according to the rules of the game. Also put some conditions to make rocks do not make in a certain area because I put respond function
**************************************************************************/
Rocks* Game::createRocks()
{
	Rocks* temp;

	Velocity v(random(-1, 1), random(-1, 1));
	Point p(random(-200, 200), random(-200, 200));

	while (p.getX() < 20 && p.getX() > -20 && p.getY() < 20 && p.getY() > -20)
	{
		p = Point (random(-200, 200), random(-200, 200));
	}

	temp = new LargeAsteroid();

	temp->setPoint(p);
	temp->setVelocity(v);
	

	return temp;
}

/**************************************************************************
* GAME :: CLEAN UP ZOMBIES
* Remove any dead objects
**************************************************************************/
void Game::cleanUpZombies()
{
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end();)
	{
		if (!it->isAlive())
		{
			it = bullets.erase(it);
		}
		else
			it++;
	}

	for (vector<Rocks*>::iterator it = rocks.begin(); it != rocks.end();)
	{
		if (*it == NULL)
		{
			it = rocks.erase(it);
		}
		else
			it++;
	}
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between a rocks and a bullet.
**************************************************************************/
void Game::handleCollisions()
{
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i] != NULL && rocks[i]->isAlive())
		{
			if (rocket.isAlive())
			{
				if (getClosestDistance(*rocks[i], rocket) < rocks[i]->getRockSize())
				{
					
					rocks[i]->breakApart(rocks);
					rocks[i]->kill();
                           
     if (!rocket.isShielded())
     {
         rocket.kill();
					numLife--;   
					respondTime = 100;
     }
     else
     {
       rocket.damageShield();
     }
     
      }
			}
			for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
			{
				if (it->isAlive())
				{
					if (getClosestDistance(*rocks[i], *it) < rocks[i]->getRockSize())
					{
						it->kill();
						rocks[i]->breakApart(rocks);
						rocks[i]->kill();
						score += rocks[i]->hit();
					}

				}
			}
		}
	}
}

/**************************************************************************
* GAME :: restartGame
* Restart game after three times respond.
**************************************************************************/
void Game::restartGame()
{
	score = 0;
	respondTime = 0;
	numLife = 3;
	bullets.clear();
	rocks.clear();

	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
	rocks.push_back(createRocks());
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

