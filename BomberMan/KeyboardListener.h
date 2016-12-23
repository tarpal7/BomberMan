#pragma once

#include <vector>
using namespace std;

class KeyboardListener
{

public:

	static void addKey( char code0, char code1, void ( *handler ) () );
	static void addKey(char code0, char code1, void(*handler) (void* obj), void* id);	// ���� ������ ��� ��������������� ( ��� ���� � �������-�������� )
	static void removeKey( char code0, char code1 );						// ������ ������ � ���������������
	static void Listen();												// ����� ��������� � ������� �-�, ���� �������� ������� ������

private:

	struct WantedKey
	{
		int		keycode [2];		// ��� ������
		void ( *handler ) ();		// �������� ������
		void ( *handlerWithArgument) (void* obj);
		void* id;

		// ����������� �������� -- � ���� ���� � C++ ;)
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

	vector<WantedKey>	keys;		// ������ ��� �������������� -- ����������� ����


	KeyboardListener();							// ��������� ����������� -- ��������� ��������� ��'����

	static  KeyboardListener instance;			// ������ ��������� KeyboardListener'�
	static  KeyboardListener& getInctance();	// ������� ������ ��������� KeyboardListener'�

};

typedef KeyboardListener KL;
