#include "Bomb.h"
#include "Scene.h"
#include "FakeWall.h"
#include "PlayerMan.h"
#include "Enemy.h"
#include "Wall.h"
#define explostionSize 2

Bomb::Bomb()
{
	this->startTime = clock();
	this->state = BOMB_STATE::IDLE;
}

Bomb::Bomb(Point* point) :GameObject(point)
{
	this->startTime = clock();
	this->state = BOMB_STATE::IDLE;
}

Bomb::~Bomb()
{
}

void Bomb::removeObjects()
{
	for (int i = 0; i <= explostionSize; ++i)
	{
		Point* leftPoint = new Point(this->position->getX() - i, this->position->getY());
		GameObject* leftGo = Scene::getInstance()->getGameObjectByPosition(leftPoint);
		if (dynamic_cast<Wall*>(leftGo))//перевірка чи є обєкт зліва стіною
			break;
		this->checkObjectBeforeRemove(leftGo);
	}
	

	for (int i = 0; i <= explostionSize; ++i)
	{
		Point* rightPoint = new Point(this->position->getX() + i, this->position->getY());
		GameObject* rightGo = Scene::getInstance()->getGameObjectByPosition(rightPoint);
		if (dynamic_cast<Wall*>(rightGo))
			break;
		this->checkObjectBeforeRemove(rightGo);
	}
	
	for (int i = 0; i <= explostionSize; ++i)
	{
		Point* topPoint = new Point(this->position->getX(), this->position->getY() - i);
		GameObject* topGo = Scene::getInstance()->getGameObjectByPosition(topPoint);
		if (dynamic_cast<Wall*>(topGo))
			break;
		this->checkObjectBeforeRemove(topGo);
	}
	
	for (int i = 0; i <= explostionSize; ++i)
	{
		Point* bottomPoint = new Point(this->position->getX(), this->position->getY() + i);
		GameObject* bottomGo = Scene::getInstance()->getGameObjectByPosition(bottomPoint);
		if (dynamic_cast<Wall*>(bottomGo))
			break;
		this->checkObjectBeforeRemove(bottomGo);
	}
}

void Bomb::checkObjectBeforeRemove(GameObject* gameObject)
{
	if (dynamic_cast<FakeWall*>(gameObject) || dynamic_cast<PlayerMan*>(gameObject) || dynamic_cast<Enemy*>(gameObject))
	{
		GameObject::removeGameObject(gameObject);
	}
}

void Bomb::update()
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	if (clockTicksTaken > 2000 && clockTicksTaken < 4000)
	{
		this->state = BOMB_STATE::EXPLOSION;
	}
	else if (clockTicksTaken > 4000)
	{
		this->state = BOMB_STATE::REMOVE;
		this->removeObjects();
		GameObject::removeGameObject(this);
	}
}

void Bomb::draw()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (this->state)
	{
	case IDLE:
	{
		COORD pos = { this->position->getX(), this->position->getY() };
		SetConsoleCursorPosition(this->consoleOutput, pos);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << "+" << std::endl;
		break;
	}
	case EXPLOSION:
	{
		COORD pos = { this->position->getX(), this->position->getY() };
		COORD pos_begin = pos;
		SetConsoleCursorPosition(this->consoleOutput, pos);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << "+" << std::endl;
		
		for (int i = 1; i <= explostionSize; ++i)
		{
			
			Point* leftPoint = new Point(this->position->getX()-i , this->position->getY());
			GameObject* leftGo = Scene::getInstance()->getGameObjectByPosition(leftPoint);
			if (dynamic_cast<Wall*>(leftGo))//перевірка чи є обєкт зліва стіною
				break;
			pos.X--;
			SetConsoleCursorPosition(this->consoleOutput, pos);
			
		
	
			//CONSOLE_SCREEN_BUFFER_INFO csbi;
		//	WORD oldColorAttr;

		//	GetConsoleScreenBufferInfo(hConsole, &csbi);

		

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-" << std::endl;
		//	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE);

		//	oldColorAttr = csbi.wAttributes;
		}

		pos.X= pos_begin.X;
		for (int i = 1; i <= explostionSize; ++i)
		{
			Point* rightPoint = new Point(this->position->getX() + i, this->position->getY());
			GameObject* rightGo = Scene::getInstance()->getGameObjectByPosition(rightPoint);
			if (dynamic_cast<Wall*>(rightGo))
				break;
			pos.X++;
			SetConsoleCursorPosition(this->consoleOutput, pos);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-" << std::endl;
		//	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		}

		pos.X = pos_begin.X;
		for (int i = 1; i <= explostionSize; ++i)
		{
			Point* topPoint = new Point(this->position->getX(), this->position->getY() - i);
			GameObject* topGo = Scene::getInstance()->getGameObjectByPosition(topPoint);
			if (dynamic_cast<Wall*>(topGo))
				break;
			pos.Y--;
			SetConsoleCursorPosition(this->consoleOutput, pos);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "|" << std::endl;
			//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		}

		pos.Y = pos_begin.Y;
		
		for (int i = 1; i <= explostionSize; ++i)
		{
			Point* bottomPoint = new Point(this->position->getX(), this->position->getY() + i);
			GameObject* bottomGo = Scene::getInstance()->getGameObjectByPosition(bottomPoint);
			if (dynamic_cast<Wall*>(bottomGo))
				break;
			pos.Y++;
			SetConsoleCursorPosition(this->consoleOutput, pos);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "|" << std::endl;
			//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		}



		break;
	}
	default:
		break;
	}
	
}

