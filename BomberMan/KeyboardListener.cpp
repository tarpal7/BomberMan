#include "KeyboardListener.h"

#include <conio.h>
#include <iostream>

KeyboardListener KeyboardListener::instance ;	// �������� ���'��� ��� ������� ���������� (��������� ��������� �����������)

void KeyboardListener::addKey( char code0, char code1, void ( *handler ) () )
{
	if( ( code0 == 0 && code1 == 0 ) || handler == nullptr )
	{
		return;		// ����� �� ������ !
	}

	getInctance().keys.emplace_back( code0, code1, handler );		// ������� ����������� WantedKey � ����� � ����� �������
}

void KeyboardListener::addKey(char code0, char code1, void(*handler) (void* obj),void* id)
{
	if ((code0 == 0 && code1 == 0) || handler == nullptr)
	{
		return;		// ����� �� ������ !
	}

	getInctance().keys.emplace_back(code0, code1, handler,id);		// ������� ����������� WantedKey � ����� � ����� �������
}
// ����� ��������� � ������� �-�, ���� �������� ������� ������
void KeyboardListener::Listen()
{
	if( ! _kbhit() )	// ���� �� ��������� ����� ������
	{
		return;
	}

	char codes [2] = {0};

	// ������ ��� ���� � ���������
	codes[0] = _getch();
	if( _kbhit() )
	{
		codes[1] = _getch();
	}

	//cout <<"\t\t" <<codes[0] <<"  " <<codes[1] <<endl;

	// ������ ������
	for( vector<WantedKey>::iterator it = getInctance().keys.begin() ; it != getInctance().keys.end() ; it++ )
	{
		// ���� ������� ���� ��������� ������
		if( codes[0] == (*it).keycode[0] && codes[1] == (*it).keycode[1] )
		{
			if ((*it).id != nullptr)
			{
				(*it).handlerWithArgument((*it).id);
			}
			else
			{
				(*it).handler();	// ��������� ��������
			}
			
		}
	}
}



KeyboardListener & KeyboardListener::getInctance()
{
	return KeyboardListener::instance;
}

KeyboardListener::KeyboardListener()
{

}
