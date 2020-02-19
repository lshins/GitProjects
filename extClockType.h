#ifndef H_extClockType
#define H_extClockType
#include "clockType.h"
#include <string>

using namespace std;

class extClockType : protected clockType
{
	string tz;

public:
	void setTime(string timeZone, int years, int months, int days, int hours, int minutes, int seconds);
	//Function to set the time
	//The time is set according to the parameters
	//Postcondition: hr = hours; min = minutes; sec = seconds
	//    The function checks whether the values of hours,
	//    minutes, and seconds are valid. If a value is invalid,
	//    the default value 0 is assigned.

	void getTime(string& timeZone, int& years, int& months, int& days, int& hours, int& minutes, int& seconds) const;
	//Function to return the time
	//Postcondition: hours = hr; minutes = min; seconds = sec

	void printTime() const;
	//Function to print the time
	//Postcondition: Time is printed in the form hh:mm:ss.

	bool equalTime(const clockType& otherClock) const;
	//Function to compare the two times
	//Postcondition: Returns true if this time is equal to
	//    otherClock; otherwise, returns false

	void compareZones(const clockType otherClock) const;

	void setZone(string timeZone);

	void getZone(string& timeZone);
};

#endif