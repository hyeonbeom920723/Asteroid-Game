#include "ship.h"

// movement of ship

void Ship:: move()
{
	velocity.setDy(-THRUST_AMOUNT * (-cos(M_PI / 180.0 * angle)) + velocity.getDy());
	velocity.setDx(-THRUST_AMOUNT * (sin(M_PI / 180.0 * angle)) + velocity.getDx());
	isThrust = true;
}

//draw ship
void Ship::draw()
{
if (shielded == true)
{
  drawCircle(point,15);
}
  

	drawShip(point, angle, isThrust);
	isThrust = false;
}

// rotate ship to left
void Ship::rotateLeft()
{
	angle += ROTATE_AMOUNT;
}

// rotate ship to right
void Ship::rotateRight()
{
	angle -= ROTATE_AMOUNT;
}

// get angle for ship
int Ship::getAngle()
{
	return angle;
}

// add shield function if we are shileded, we want to decrease the time of shield if we do not have shield time, we reset the shield. else we decrease coolDownTime.
void Ship::advance()
{
  FlyingObject :: advance();
  if (shielded == true)
  {
    shieldTime--;
    if (shieldTime <= 0)
    {
      shielded = false;
      coolDownTime = 50;
      shieldTime = 50;
    }
  }
  
  else
  {
    coolDownTime--;
  }
}

// if we have enough coolDwonTime, raise the shield.
void Ship::shieldUp()
{
  if (coolDownTime <= 0)
  {
    shielded = true;
  }
}

// check if shield up.
bool Ship::isShielded()
{
  return shielded;
}

// if hit the rokcs, get damage
void Ship::damageShield()
{
  shieldTime -= 10;
}

