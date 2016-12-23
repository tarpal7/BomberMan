#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
protected:
	int m_x;
	int m_y;
};

