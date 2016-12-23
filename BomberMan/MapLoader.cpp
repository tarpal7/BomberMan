#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>  
#include <conio.h>
#include "Point.h"
#include "Wall.h"
#include "FakeWall.h"
void MapLoader::loadMap(std::string mapName)
{
	Point* positionInFile = new Point(0, 0);
	fflush(stdin); // очищення потоку
	int ch = 0;
	std::string s;
	std::ifstream fin(mapName); // обєкт класу ifstream для читання з файлу

	if (!fin.is_open()) // якщо файл не відкртитий
		std::cout << "The file can not be opened!\n";
	else
	{
		std::ifstream in(mapName);     //відкрили для читання
		while ((ch = in.get()) != EOF) {   //читати кожний символ в потік in
			if (char(ch) != '\n')
			{
				s =  char(ch);  //зчитуємо символ із файлу и зразу перевіряємо його на ознаку переносу рядка 
				if (s == "1")
				{
					Wall* wall = new Wall();
					wall->position = new Point(*positionInFile);
				}
				else if (s == "2")
				{
					FakeWall* fakeWall = new FakeWall();
					fakeWall->position = new Point(*positionInFile);
				}
				positionInFile->setX(positionInFile->getX() + 1);
				
			}
			else {
				positionInFile->setX(0);
				positionInFile->setY(positionInFile->getY() + 1);
			}
		}    

		in.close(); //закриваємо файл
	}
}

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}
