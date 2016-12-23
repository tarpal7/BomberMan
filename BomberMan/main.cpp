
#include "PlayerMan.h"
#include "MapLoader.h"
#include "Scene.h"
#include <conio.h>
#include <ctype.h>
#include "Enemy.h"


int main()
{

	srand(unsigned(time(0)));

	MapLoader::loadMap("map.txt");
	Scene* scene = Scene::getInstance();

	PlayerMan* man = new PlayerMan(PlayerMan::FIRST);
	man->position = new Point(6, 10);
	
	//PlayerMan* man1 = new PlayerMan(PlayerMan::SECOND);
	//man1->position = new Point(6, 11);

	
		Enemy* enemy = new Enemy;
		Enemy* enemy2 = new Enemy;
		Enemy* enemy3 = new Enemy;
		Enemy* enemy4 = new Enemy;


		enemy->position = new Point(7, 10);
		enemy2->position = new Point(3, 2);
		enemy3->position = new Point(13, 2);
		enemy4->position = new Point(14, 7);

	while (1)
	{
		KL::Listen();
		scene->update();
	}
	return 0;
}