#pragma once
#include "GameObject.h"
#include "KeyboardListener.h"  
class PlayerMan :
	public GameObject
{

public:
	enum PLAYER_TYPE
	{
		FIRST = 0,
		SECOND = 1
	};
	PlayerMan();
	PlayerMan(PLAYER_TYPE type);
	virtual ~PlayerMan();
	void draw();
	void moveLeft();
	static void staticWraperMoveLeft(void* object);
	void moveRight();
	static void staticWraperMoveRight(void* object);
	void moveTop();
	static void staticWraperMoveTop(void* object);
	void moveDown();
	static void staticWraperMoveDown(void* object);
	void planeBomb();
	static void staticWraperPlaneBomb(void* object);
};

