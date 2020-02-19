#include <iostream>
#include "clockType.h"

using namespace std;

void clockType::setTime(int years, int months, int days, int hours, int minutes, int seconds)
{
	if (0 <= years && years < 10)
		yr = years;
	else
		yr = 0;

	if (0 <= months && months < 12)
		mon = months;
	else
		mon = 0;

	if (0 <= days && days < 31)
		day = days;
	else
		day = 0;

	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;

	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}

void clockType::getTime(int& years, int& months, int& days, int& hours, int& minutes, int& seconds) const
{
	years = yr;
	months = mon;
	days = day;
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::incrementYears()
{
	yr++;
	//if (yr > 9)
		//yr = 0;
}

void clockType::incrementMonths()
{
	mon++;
	if (mon > 11)
	{
		mon = 0;
		incrementYears();
	}
}

void clockType::incrementDays()
{
	day++;
	if (day > 30)
	{
		day = 0;
		incrementMonths();
	}
	// fix for months with less than 31 days
}

void clockType::incrementHours()
{
	hr++;
	if (hr > 23)
	{
		hr = 0;
		incrementDays();
	}
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
		min = 0;
		incrementHours();
	}
}

void clockType::incrementSeconds()
{
	sec++;

	if (sec > 59)
	{
		sec = 0;
		incrementMinutes();
	}
}

void clockType::printTime() const
{
	if (mon < 10)
		cout << "0";
	cout << mon << "/";

	if (day < 10)
		cout << "0";
	cout << day << "/";

	if (yr < 10)
		cout << "0";
	cout << yr << " ";

	if (hr < 10)
		cout << "0";
	cout << hr << ":";

	if (min < 10)
		cout << "0";
	cout << min << ":";

	if (sec < 10)
		cout << "0";
	cout << sec;
}

bool clockType::equalTime(const clockType& otherClock) const
{
	return (yr == otherClock.yr
		&& mon == otherClock.mon
		&& day == otherClock.day
		&& hr == otherClock.hr
		&& min == otherClock.min
		&& sec == otherClock.sec);
}

clockType::clockType(int years, int months, int days, int hours, int minutes, int seconds)
{
	if (0 <= years && years < 10)
		yr = years;
	else
		yr = 0;

	if (0 <= months && months < 12)
		mon = months;
	else
		mon = 0;

	if (0 <= days && days < 31)
		day = days;
	else
		day = 0;

	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;

	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}

clockType::clockType()  //default constructor
{
	yr = 0;
	mon = 0;
	day = 0;
	hr = 0;
	min = 0;
	sec = 0;
}