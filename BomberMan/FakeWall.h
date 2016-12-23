#pragma once
#include "GameObject.h"
class FakeWall :
	public GameObject
{
public:
	FakeWall();
	virtual ~FakeWall();
	void draw();
};

