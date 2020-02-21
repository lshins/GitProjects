#include <iostream>
#include "clockType.h"
#include "extClockType.h"
#include <string>

using namespace std;

void extClockType::setTime(string timeZone, int years, int months, int days, int hours, int minutes, int seconds)
{
	clockType::setTime(years, months, days, hours, minutes, seconds);
	if ((timeZone == "Hawaiian") || (timeZone == "Alaskan-Aleutian") || (timeZone == "Pacific") ||
		(timeZone == "Mountain") || (timeZone == "Central") || (timeZone == "Eastern"))
	{
		tz = timeZone;
		if (timeZone == "Hawaiian")
			zoneInt = 0;
		else if (timeZone == "Alaskan-Aleutian")
			zoneInt = 1;
		else if (timeZone == "Pacific")
			zoneInt = 2;
		else if (timeZone == "Mountain")
			zoneInt = 3;
		else if (timeZone == "Central")
			zoneInt = 4;
		else
			zoneInt = 5;
	}
	else
	{
		tz = "Eastern";
		zoneInt = 5;
	}
}

void extClockType::getTime(string& timeZone, int& years, int& months, int& days, int& hours, int& minutes, int& seconds)
{
	clockType::getTime(years, months, days, hours, minutes, seconds);
	getZone(timeZone);
}

void extClockType::printTime() const
{
	cout << tz << " Time ";
	clockType::printTime();
}

void extClockType::incrementYears()
{
	yr++;
	//if (yr > 9)
		//yr = 0;
}

void extClockType::incrementMonths()
{
	mon++;
	if (mon > 11)
	{
		mon = 0;
		incrementYears();
	}
}

void extClockType::incrementDays()
{
	day++;
	if (day > 30)
	{
		day = 0;
		incrementMonths();
	}
	// fix for months with less than 31 days
}

void extClockType::incrementHours()
{
	hr++;
	if (hr > 23)
	{
		hr = 0;
		incrementDays();
	}
}

void extClockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
		min = 0;
		incrementHours();
	}
}

void extClockType::incrementSeconds()
{
	sec++;

	if (sec > 59)
	{
		sec = 0;
		incrementMinutes();
	}
}

bool extClockType::equalTime(const extClockType& otherClock)
{
	int dif, i;
	extClockType checkClock;
	checkClock = otherClock;
	if (zoneInt != checkClock.zoneInt)
		if (zoneInt > checkClock.zoneInt)
		{
			dif = zoneInt - checkClock.zoneInt;
			for (i = 0; i < dif; i++)
				checkClock.incrementHours();
			return (yr == checkClock.yr
				&& mon == checkClock.mon
				&& day == checkClock.day
				&& hr == checkClock.hr
				&& min == checkClock.min
				&& sec == checkClock.sec);
		}
		else
		{
			dif = -(zoneInt - checkClock.zoneInt);
			for (i = 0; i < dif; i++)
			{
				incrementHours();
				tz = checkClock.tz;
			}
			return (yr == checkClock.yr
				&& mon == checkClock.mon
				&& day == checkClock.day
				&& hr == checkClock.hr
				&& min == checkClock.min
				&& sec == checkClock.sec);
		}
}

void extClockType::setZone(string timeZone)
{
	int dif, i;
	extClockType checkClock;
	checkClock.tz = timeZone;
	if (timeZone == "Hawaiian")
		checkClock.zoneInt = 0;
	else if (timeZone == "Alaskan-Aleutian")
		checkClock.zoneInt = 1;
	else if (timeZone == "Pacific")
		checkClock.zoneInt = 2;
	else if (timeZone == "Mountain")
		checkClock.zoneInt = 3;
	else if (timeZone == "Central")
		checkClock.zoneInt = 4;
	else
		checkClock.zoneInt = 5;
	if (zoneInt > checkClock.zoneInt)
	{
		dif = zoneInt - checkClock.zoneInt;
		for (i = 0; i < dif; i++)
			hr--;
	}
	else
	{
		dif = -(zoneInt - checkClock.zoneInt);
		for (i = 0; i < dif; i++)
		{
			incrementHours();
			tz = checkClock.tz;
		}
	}
}

void extClockType::getZone(string& timeZone)
{
	timeZone = tz;
	if (timeZone == "Hawaiian")
		zoneInt = 0;
	else if (timeZone == "Alaskan-Aleutian")
		zoneInt = 1;
	else if (timeZone == "Pacific")
		zoneInt = 2;
	else if (timeZone == "Mountain")
		zoneInt = 3;
	else if (timeZone == "Central")
		zoneInt = 4;
	else
		zoneInt = 5;
}

extClockType::extClockType(string timeZone, int years, int months, int days, int hours, int minutes, int seconds)
{
	clockType(years, months, days, hours, minutes, seconds);
	if ((timeZone == "Hawaiian") || (timeZone == "Alaskan-Aleutian") || (timeZone == "Pacific") ||
		(timeZone == "Mountain") || (timeZone == "Central") || (timeZone == "Eastern"))
	{
		tz = timeZone;
		if (timeZone == "Hawaiian")
			zoneInt = 0;
		else if (timeZone == "Alaskan-Aleutian")
			zoneInt = 1;
		else if (timeZone == "Pacific")
			zoneInt = 2;
		else if (timeZone == "Mountain")
			zoneInt = 3;
		else if (timeZone == "Central")
			zoneInt = 4;
		else
			zoneInt = 5;
	}
	else
	{
		tz = "Eastern";
		zoneInt = 5;
	}
}

extClockType::extClockType()
{
	clockType();
	tz = "Eastern";
	zoneInt = 5;
}

extClockType::~extClockType()
{

}