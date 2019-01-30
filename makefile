###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Macbeth, CS165
# Author:
#     Hyeonbeom Lee
# Summary:
#     draw five large asteorids and break it by using contorl ship and shotting bullets
# Above and Beyond
#     I put three respond chances
#     Put score 
#     Put shield function so that ship can be protected for a certain amount of time and then it will be gone.
#     I put restart game function after three times responds.
#     Thrust fire when user type up arrow.
#     Change asteroid colors (Large = Blue , Medium = Green , Small = Red)
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o largeAsteroid.o mediumAsteroid.o smallAsteroid.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o largeAsteroid.o mediumAsteroid.o smallAsteroid.o $(LFLAGS)
	tar -j -cf asteroid.tar makefile *.h *.cpp
###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
#    largeAsteroid.o  Handles the large asteroid objects
#    mediumAsteroid.o  Handles the medium asteroid objects
#    smallAsteroid.o   Handles the small asteroid objects
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

largeAsteroird.o: largeAsteroid.h largeAsteroid.cpp
	g++ -c largeAsteroid.cpp

mediumAsteroird.o: mediumAsteroid.h mediumAsteroid.cpp
	g++ -c mediumAsteroid.cpp

smallAsteroird.o: smallAsteroid.h smallAsteroid.cpp
	g++ -c smallAsteroid.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
