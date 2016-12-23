#pragma once

#include "Point.h"
#include "Windows.h"
#include <iostream>
#include <iomanip>
class GameObject
{
public:
	Point* position;
	bool getIsRigidBody();
	GameObject();
	GameObject(Point* point);
	~GameObject();
	virtual void update();
	virtual void draw() = 0;
	static void removeGameObject(GameObject* gameObject);
protected:
	HANDLE consoleOutput;
	bool isRigidBody;
};

