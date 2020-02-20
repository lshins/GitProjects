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
	{
		tz = "Eastern";
		zoneInt = 5;
	}
}

void extClockType::getTime(string& timeZone, int& years, int& months, int& days, int& hours, int& minutes, int& seconds) const
{
	clockType::getTime(years, months, days, hours, minutes, seconds);
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

void extClockType::printTime() const
{
	cout << tz << " Time ";
	clockType::printTime();
}

bool extClockType::equalTime(const clockType& otherClock) const
{
	if (zoneInt != otherClock.zoneInt)

}