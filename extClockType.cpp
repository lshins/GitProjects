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
		tz = timeZone;
	else
		tz = "Eastern";
}

void extClockType::getTime(string& timeZone, int& years, int& months, int& days, int& hours, int& minutes, int& seconds) const
{
	clockType::getTime(years, months, days, hours, minutes, seconds);
	timeZone = tz;
}

void extClockType::printTime() const
{
	cout << tz << " Time ";
	clockType::printTime();
}

bool extClockType::equalTime(const clockType& otherClock) const
{
	extClockType::compareZones(otherClock);
}