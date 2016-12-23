#pragma once
#include "Updatable.h"
#include "GameObject.h"
#include <vector>
//#include <algorithm>
class Scene : public Updatable
{
private:
	std::vector<GameObject*> gameObjects; // масив обєктів на сцені
	Scene(clock_t period);  //
	static Scene* instance;
public:
	static Scene* getInstance();
	~Scene();
	void update();
	void addGameObject(GameObject* gameObject);
	void removeGameObject(GameObject* gameObject);
	GameObject* getGameObjectByPosition(Point* point);
	void clear_screen();
};

