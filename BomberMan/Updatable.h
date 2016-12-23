#pragma once

#include <ctime>
#include <stdexcept>


class Updatable
{

public:

	Updatable( clock_t period );

	clock_t	setPeriod( clock_t period );
	clock_t	getPeriod(); 

	bool	isTimeToAction();	// ������� true, ���� ������ ��� ����, � ������� ������ �������� 䳿

	///////////////////////////
	virtual void update() = 0;	// ����� ��������� �-� ��� �������������� � �������� ������ -- ������ ��������� ��
	///////////////////////////

private:

	clock_t _clcNextAction;		// ������ ���� ��������� �������� 䳿
	clock_t _clcPeriod;			// ����� �������

	void checkPeriod( clock_t period );

};


