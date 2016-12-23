#pragma once
#include "GameObject.h"
#include "KeyboardListener.h" 
class Enemy :
	public GameObject
{
public:
	Enemy();
	virtual ~Enemy();
	void draw();
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	
	
	
	void move();
	
	
	void kill();
	
	
	static void staticWraperMove(void* object);
	void update();


private:
	clock_t startTime;

	enum ENEMY_STATE
	{
		MOVE_UP = 0, MOVE_RIGHT, MOVE_DOWN, MOVE_LEFT
	};
	
	ENEMY_STATE stateEnemy;


};

