#include "GameObject.h"
#include "Scene.h"

GameObject::GameObject()
{
	this->consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	this->isRigidBody = false;
	Scene::getInstance()->addGameObject(this);
}

GameObject::GameObject(Point* point)
{
	this->consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	this->position = point;
	this->isRigidBody = false;
	Scene::getInstance()->addGameObject(this);
}

void GameObject::update()
{
	
}

bool GameObject::getIsRigidBody()
{
	return this->isRigidBody;
}

void GameObject::removeGameObject(GameObject* gameObject)
{
	Scene::getInstance()->removeGameObject(gameObject);
}

GameObject::~GameObject()
{
}


