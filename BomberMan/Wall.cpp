#include "Wall.h"


Wall::Wall()
{
	this->isRigidBody = true;
}

Wall::~Wall()
{
}

void Wall::draw()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { this->position->getX(), this->position->getY() };
	SetConsoleCursorPosition(this->consoleOutput, pos);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	std::cout << "$" << std::endl;
	//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
