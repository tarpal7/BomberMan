#include "Scene.h"

Scene* Scene::instance = 0;

Scene::Scene(clock_t period) : Updatable(period) // приватний конструктор від базового класу 
{

}

Scene* Scene::getInstance()
{
	if (Scene::instance == nullptr) // якщо не існує 
	{
		Scene::instance = new Scene(400); //то створюємо
	}
	
	return Scene::instance; // якщо існує то повертаємо вказівник на існуючий
}

Scene::~Scene()
{
}

void Scene::update()
{
	if (!this->isTimeToAction())
	{
		return;
	}

	system("cls");
	
	//clear_screen();
	for (int i = 0; i < this->gameObjects.size(); ++i)
	{
		GameObject* go = this->gameObjects[i];
		go->update();
		go->draw();
	}
}

void Scene::addGameObject(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);
}

void Scene::removeGameObject(GameObject* gameObject)
{
	std::vector<GameObject*>::iterator objectIterator = std::find(this->gameObjects.begin(), this->gameObjects.end(), gameObject);
	this->gameObjects.erase(objectIterator);
}

GameObject* Scene::getGameObjectByPosition(Point* point)
{
	for (int i = 0; i < this->gameObjects.size(); ++i)
	{
		GameObject* gameObject = this->gameObjects[i];
		if (gameObject->position->getX() == point->getX() &&
			gameObject->position->getY() == point->getY())
		{
			return gameObject;
		}
	}
	return NULL;
}

void Scene::clear_screen()
{
	CONSOLE_SCREEN_BUFFER_INFO buffer_info;
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
	for (int i = 0; i < 19; i++)
	std::cout << "                                                                 \n";
}