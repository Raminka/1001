#include "stdafx.h"
#include "Obstacle.h"


Obstacle::Obstacle(double fois_x, double fois_y)
	:x(fois_x*tailleX)
	,y(fois_y*tailleY)
{
}



double Obstacle::getX()const {
	return x;
}
double Obstacle::getY() const {
	return y;
}