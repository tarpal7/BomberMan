#pragma once
#include "GameObject.h"
class Wall :
	public GameObject
{
public:
	Wall();
	virtual ~Wall();
	void draw();
};

