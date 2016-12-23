#pragma once

#include <vector>
using namespace std;

class KeyboardListener
{

public:

	static void addKey( char code0, char code1, void ( *handler ) () );
	static void addKey(char code0, char code1, void(*handler) (void* obj), void* id);	// додаЇ клав≥шу дл€ прослуховуванн€ ( два коди ≥ функц≥€-обробник )
	static void removeKey( char code0, char code1 );						// вилучаЇ клав≥шу з прослуховуванн€
	static void Listen();												// слухаЇ клав≥атуру ≥ викликаЇ ф-ю, €кщо натиснен≥ в≥дпов≥дн≥ клав≥ш≥

private:

	struct WantedKey
	{
		int		keycode [2];		// код клав≥ш≥
		void ( *handler ) ();		// обробник клав≥ш≥
		void ( *handlerWithArgument) (void* obj);
		void* id;

		// конструктор струтури -- ≥ таке буваЇ в C++ ;)
		WantedKey( int code0, int code1, void ( *handler ) (void* obj), void* id)
		{
			this->keycode[0] = code0;
			this->keycode[1] = code1;
			this->handlerWithArgument = handler;
			this->id = id;
		}
		WantedKey(int code0, int code1, void(*handler) ())
		{
			this->keycode[0] = code0;
			this->keycode[1] = code1;
			this->handler = handler;
			this->handlerWithArgument = NULL;
			this->id = NULL;
		}

	};

	vector<WantedKey>	keys;		// клав≥ш≥ дл€ просуховуванн€ -- екземпл€рне поле


	KeyboardListener();							// приватний конструктор -- заборорна створенн€ об'Їкт≥в

	static  KeyboardListener instance;			// Їдиний екземпл€р KeyboardListener'а
	static  KeyboardListener& getInctance();	// повертаЇ Їдиний екземпл€р KeyboardListener'а

};

typedef KeyboardListener KL;
