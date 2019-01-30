#include "bullet.h"
#include <cmath>
#include <iostream>

using namespace std;

// constructor for bullet set frame lives to 0
Bullet::Bullet() 
{
	frameLived = 0;
};


// fire bullets
void Bullet::fire(Point point, float angle)
{
	setPoint(point);
	velocity.setDy(-BULLET_SPEED * (-cos(M_PI / 180.0 * angle)) + velocity.getDy());
	velocity.setDx(-BULLET_SPEED * (sin(M_PI / 180.0 * angle)) + velocity.getDx());

	// bullet is alived
	alive = true;
}

// draw bullets
void Bullet::draw()
{
	drawDot(point);
}

//movement for bullets and handle bullet's life
void Bullet::advance()
{
	FlyingObject::advance();
	frameLived++;
	if (frameLived > BULLET_LIFE)
	{
		kill();
	}
}