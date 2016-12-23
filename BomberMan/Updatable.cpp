#include "Updatable.h"

Updatable::Updatable( clock_t period )
{
	setPeriod( period );
}


clock_t	Updatable::setPeriod( clock_t period )
{
	clock_t oldPeriod = this->_clcPeriod;

	checkPeriod( period );
	this->_clcPeriod = period;
	this->_clcNextAction = clock() + period;

	return oldPeriod;
}


clock_t	Updatable::getPeriod()
{
	return this->_clcPeriod;
}


// повертає true, якщо настав час діяти, і визначає момент наступної дії
bool Updatable::isTimeToAction()
{

	if( clock() >= this->_clcNextAction )
	{
		this->_clcNextAction += this->_clcPeriod;
		return true;
	}

	return false;
}


void Updatable::checkPeriod( clock_t period )
{
	if( period < 2 )
	{
		char speriod [22];
		_itoa_s( period, speriod, 10 );
		std::string what( "ERROR: Period must be more than 2 -- Updatable( " );
		what += speriod;
		what += ")";
		throw std::invalid_argument( what );
	}
}

