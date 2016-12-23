#include "FakeWall.h"


FakeWall::FakeWall()
{
	this->isRigidBody = true;
}

FakeWall::~FakeWall()
{
}

void FakeWall::draw()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { this->position->getX(), this->position->getY() };
	SetConsoleCursorPosition(this->consoleOutput, pos);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "O" << std::endl;
//	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
