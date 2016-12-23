#pragma once
#include "GameObject.h"
class Bomb :
	public GameObject
{
private:
	enum BOMB_STATE
	{
		IDLE = 0,
		EXPLOSION = 1,
		REMOVE = 2
	};
	clock_t startTime;
	BOMB_STATE state;
	

public:
	Bomb();
	Bomb(Point* point);
	virtual ~Bomb();
	void removeObjects();
	void checkObjectBeforeRemove(GameObject* gameObject);
	void draw();
	void update();
};

