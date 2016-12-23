#pragma once

#include <ctime>
#include <stdexcept>


class Updatable
{

public:

	Updatable( clock_t period );

	clock_t	setPeriod( clock_t period );
	clock_t	getPeriod(); 

	bool	isTimeToAction();	// повертає true, якщо настав час діяти, і визначає момент наступної дії

	///////////////////////////
	virtual void update() = 0;	// чисто віртуальна ф-я для перевизначення у похідних класах -- виконує періодичну дію
	///////////////////////////

private:

	clock_t _clcNextAction;		// момент часу виконання наступної дії
	clock_t _clcPeriod;			// період повтору

	void checkPeriod( clock_t period );

};


