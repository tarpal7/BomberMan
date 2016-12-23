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
	fflush(stdin); // �������� ������
	int ch = 0;
	std::string s;
	std::ifstream fin(mapName); // ���� ����� ifstream ��� ������� � �����

	if (!fin.is_open()) // ���� ���� �� ���������
		std::cout << "The file can not be opened!\n";
	else
	{
		std::ifstream in(mapName);     //������� ��� �������
		while ((ch = in.get()) != EOF) {   //������ ������ ������ � ���� in
			if (char(ch) != '\n')
			{
				s =  char(ch);  //������� ������ �� ����� � ����� ���������� ���� �� ������ �������� ����� 
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

		in.close(); //��������� ����
	}
}

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}
