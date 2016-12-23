#include "KeyboardListener.h"

#include <conio.h>
#include <iostream>

KeyboardListener KeyboardListener::instance ;	// виділяємо пам'ять для єдиного екземпляра (приватний дефолтний конструктор)

void KeyboardListener::addKey( char code0, char code1, void ( *handler ) () )
{
	if( ( code0 == 0 && code1 == 0 ) || handler == nullptr )
	{
		return;		// сміття не додаємо !
	}

	getInctance().keys.emplace_back( code0, code1, handler );		// викликає конструктор WantedKey і поміщає в кінець вектора
}

void KeyboardListener::addKey(char code0, char code1, void(*handler) (void* obj),void* id)
{
	if ((code0 == 0 && code1 == 0) || handler == nullptr)
	{
		return;		// сміття не додаємо !
	}

	getInctance().keys.emplace_back(code0, code1, handler,id);		// викликає конструктор WantedKey і поміщає в кінець вектора
}
// слухає клавіатуру і викликає ф-ю, якщо натиснені відповідні клавіші
void KeyboardListener::Listen()
{
	if( ! _kbhit() )	// якщо не натиснена жодна клавіша
	{
		return;
	}

	char codes [2] = {0};

	// читаємо два коди з клавіатури
	codes[0] = _getch();
	if( _kbhit() )
	{
		codes[1] = _getch();
	}

	//cout <<"\t\t" <<codes[0] <<"  " <<codes[1] <<endl;

	// шукаємо клавіші
	for( vector<WantedKey>::iterator it = getInctance().keys.begin() ; it != getInctance().keys.end() ; it++ )
	{
		// якщо знайшли коди натисненої клавіші
		if( codes[0] == (*it).keycode[0] && codes[1] == (*it).keycode[1] )
		{
			if ((*it).id != nullptr)
			{
				(*it).handlerWithArgument((*it).id);
			}
			else
			{
				(*it).handler();	// викликаємо обробник
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
