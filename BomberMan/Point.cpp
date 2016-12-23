#include "Point.h"


Point::Point()
{
}

Point::Point(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

Point::~Point()
{
}

void Point::setX(int x)
{
	this->m_x = x;
}

int Point::getX()
{
	return this->m_x;
}

void Point::setY(int y)
{
	this->m_y = y;
}

int Point::getY()
{
	return this->m_y;
}
