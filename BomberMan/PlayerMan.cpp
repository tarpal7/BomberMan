#include "PlayerMan.h"
#include "Bomb.h"
#include "Scene.h"
void PlayerMan::moveLeft()
{
	Point* nextPosition = new Point(*this->position);
	nextPosition->setX(this->position->getX() - 1);
	GameObject* go = Scene::getInstance()->getGameObjectByPosition(nextPosition);
	if (go != NULL && go->getIsRigidBody())
	{
		return;
	}
	else
	{
		this->position = nextPosition;
	}
}

void PlayerMan::staticWraperMoveLeft(void* object)
{
	PlayerMan* man = (PlayerMan*)object;
	man->moveLeft();
}

void PlayerMan::moveRight()
{
	Point* nextPosition = new Point(*this->position);
	nextPosition->setX(this->position->getX() + 1);
	GameObject* go = Scene::getInstance()->getGameObjectByPosition(nextPosition);
	if (go != NULL && go->getIsRigidBody())
	{
		return;
	}
	else
	{
		this->position = nextPosition;
	}
}

void PlayerMan::staticWraperMoveRight(void* object)
{
	PlayerMan* man = (PlayerMan*)object;
	man->moveRight();
}

void PlayerMan::moveTop()
{
	Point* nextPosition = new Point(*this->position);
	nextPosition->setY(this->position->getY() - 1);
	GameObject* go = Scene::getInstance()->getGameObjectByPosition(nextPosition);
	if (go != NULL && go->getIsRigidBody())
	{
		return;
	}
	else
	{
		this->position = nextPosition;
	}
}

void PlayerMan::staticWraperMoveTop(void* object)
{
	PlayerMan* man = (PlayerMan*)object;
	man->moveTop();
}

void PlayerMan::moveDown()
{
	Point* nextPosition = new Point(*this->position);
	nextPosition->setY(this->position->getY() + 1);
	GameObject* go = Scene::getInstance()->getGameObjectByPosition(nextPosition);
	if (go != NULL && go->getIsRigidBody())
	{
		return;
	}
	else
	{
		this->position = nextPosition;
	}
}

void PlayerMan::staticWraperMoveDown(void* object)
{
	PlayerMan* man = (PlayerMan*)object;
	man->moveDown();
}

void PlayerMan::planeBomb()
{
	Point* bombPosition = new Point(*this->position);
	Bomb* bomb = new Bomb(bombPosition);
}

void PlayerMan::staticWraperPlaneBomb(void* object)
{
	PlayerMan* man = (PlayerMan*)object;
	man->planeBomb();
}

PlayerMan::PlayerMan()
{
	KL::addKey('a', 0, PlayerMan::staticWraperMoveLeft, this);
	KL::addKey('d', 0, PlayerMan::staticWraperMoveRight, this);
	KL::addKey('w', 0, PlayerMan::staticWraperMoveTop, this);
	KL::addKey('s', 0, PlayerMan::staticWraperMoveDown, this);
	KL::addKey(32, 0, PlayerMan::staticWraperPlaneBomb, this);
}

PlayerMan::PlayerMan(PLAYER_TYPE type)
{
	switch (type)
	{
	case PlayerMan::FIRST:
	{
		KL::addKey('a', 0, PlayerMan::staticWraperMoveLeft, this);
		KL::addKey('d', 0, PlayerMan::staticWraperMoveRight, this);
		KL::addKey('w', 0, PlayerMan::staticWraperMoveTop, this);
		KL::addKey('s', 0, PlayerMan::staticWraperMoveDown, this);
		KL::addKey(32, 0, PlayerMan::staticWraperPlaneBomb, this);
		break;
	}
	case PlayerMan::SECOND:
	{
		KL::addKey('j', 0, PlayerMan::staticWraperMoveLeft, this);
		KL::addKey('l', 0, PlayerMan::staticWraperMoveRight, this);
		KL::addKey('i', 0, PlayerMan::staticWraperMoveTop, this);
		KL::addKey('k', 0, PlayerMan::staticWraperMoveDown, this);
		KL::addKey('p', 0, PlayerMan::staticWraperPlaneBomb, this);
		break;
	}
	default:
		break;
	}
}

PlayerMan::~PlayerMan()
{
}

void PlayerMan::draw()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { this->position->getX(), this->position->getY()};
	SetConsoleCursorPosition(this->consoleOutput, pos);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
	
	std::cout << "@" << std::endl;

	//SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
	
