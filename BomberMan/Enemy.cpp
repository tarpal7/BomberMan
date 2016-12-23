#include "Enemy.h"
#include "Scene.h"
#include "PlayerMan.h"
Enemy::Enemy()
{
	//	this->startTime = clock();
		this->stateEnemy = MOVE_UP;
}

Enemy::~Enemy()
{
}


void Enemy::update()
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	if (clockTicksTaken >2000)
	{
	COORD pos = { this->position->getX(), this->position->getY() };// ��������� �� �����������
	SetConsoleCursorPosition(this->consoleOutput, pos);
	Point* nextPosition = new Point(*this->position); // ���� ������� ���� ��������� ����������
	switch (stateEnemy)
	{
	case 1:nextPosition->setX(this->position->getX() + 1); break;
	case 2:nextPosition->setY(this->position->getY() + 1); break;
	case 3:nextPosition->setX(this->position->getX() - 1); break;
	case 0:nextPosition->setY(this->position->getY() - 1); break;

	}

	
	GameObject* go = Scene::getInstance()->getGameObjectByPosition(nextPosition);

	if (go != NULL && go->getIsRigidBody())
	{
		switch (stateEnemy)
		{
		case 0:this->stateEnemy = MOVE_RIGHT; break;
		case 1:this->stateEnemy = MOVE_DOWN;  break;
		case 2:this->stateEnemy = MOVE_LEFT;  break;
		case 3:this->stateEnemy = MOVE_UP;  break;

		}
		return;
	}
	else
	{
				
		this->position = nextPosition;
	
	

			switch (stateEnemy)
			{
			case 1:this->moveRight(); kill(); break;
			case 2:this->moveDown(); kill(); break;
			case 3:this->moveLeft(); kill(); break;
			case 0:this->moveUp(); kill(); break;

			}
		}
	}

		


}

// ��� � ���������� ��������
void Enemy::move ()
{
	COORD pos = { this->position->getX(), this->position->getY() };// ��������� �� �����������
	SetConsoleCursorPosition(this->consoleOutput, pos);
	int i = rand() % 5;
	Point* nextPosition = new Point(*this->position); // ���� ������� ���� ��������� ����������
	switch (i)
	{
	case 1:nextPosition->setX(this->position->getX() + 1); break;
	case 3:nextPosition->setY(this->position->getY() + 1); break;
	case 2:nextPosition->setX(this->position->getX() - 1); break;
	case 4:nextPosition->setY(this->position->getY() - 1); break;
		
	}

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


// ��� ������
void Enemy::moveRight()
{
	COORD pos = { this->position->getX(), this->position->getY() };// ��������� �� �����������
	SetConsoleCursorPosition(this->consoleOutput, pos);

	Point* nextPosition = new Point(*this->position); // ���� ������� ���� ��������� ����������
	nextPosition->setX(this->position->getX() + 1); 
	
	GameObject* go = Scene::getInstance()->getGameObjectByPosition(nextPosition);

	if (go != NULL && go->getIsRigidBody())//���� ������� ���� �� �� ������
	{
		return;// ��������� ������� ��� ���
	}
	else
	{
		this->position = nextPosition;// ��������� ������� , �� ��� ��������
	}
}

//��� ����
void Enemy::moveLeft()
{
	COORD pos = { this->position->getX(), this->position->getY() };// ��������� �� �����������
	SetConsoleCursorPosition(this->consoleOutput, pos);

	Point* nextPosition = new Point(*this->position); // ���� ������� ���� ��������� ����������
	//nextPosition->setX(this->position->getX() + 1);
	//nextPosition->setY(this->position->getY() + 1);
	nextPosition->setX(this->position->getX() - 1);
	//nextPosition->setY(this->position->getY() - 1); 


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

//��� �����
void Enemy::moveUp()
{
	COORD pos = { this->position->getX(), this->position->getY() };// ��������� �� �����������
	SetConsoleCursorPosition(this->consoleOutput, pos);

	Point* nextPosition = new Point(*this->position); // ���� ������� ���� ��������� ����������
	//nextPosition->setX(this->position->getX() + 1);
	//nextPosition->setY(this->position->getY() + 1);
	//nextPosition->setX(this->position->getX() - 1);
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



//��� ����
void Enemy::moveDown()
{
	COORD pos = { this->position->getX(), this->position->getY() };// ��������� �� �����������
	SetConsoleCursorPosition(this->consoleOutput, pos);

	Point* nextPosition = new Point(*this->position); // ���� ������� ���� ��������� ����������
	//nextPosition->setX(this->position->getX() + 1);
	nextPosition->setY(this->position->getY() + 1);
	//nextPosition->setX(this->position->getX() - 1);
	//nextPosition->setY(this->position->getY() - 1);


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


void Enemy::kill()
{
	Point* meetingPlayer = new Point(this->position->getX(), this->position->getY());
	GameObject* killPlayer = Scene::getInstance()->getGameObjectByPosition(meetingPlayer);
	if (dynamic_cast<PlayerMan*>(killPlayer))//�������� �� � ���� �������
	{
		GameObject::removeGameObject(killPlayer);
		cout <<"Game over\n";
		exit(0);
	}
}

void Enemy::draw()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { this->position->getX(), this->position->getY() };
	SetConsoleCursorPosition(this->consoleOutput, pos);
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	std::cout << "&" << std::endl;

	//SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
}
