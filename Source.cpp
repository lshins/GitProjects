#include <iostream>
#include "clockType.h"

using namespace std;

int main()
{
	clockType clock1;
	int cY = 0, cMo = 0, cD = 0, cH = 0, cMi = 0, cS = 0;
	clock1.setTime(0, 1, 30, 8, 59, 0);
	clock1.printTime();
	cout << endl << endl;
	clock1.incrementDays();
	clock1.incrementMinutes();
	clock1.getTime(cY, cMo, cD, cH, cMi, cS);
	cout << cY << " years recorded" << endl;
	cout << cMo << " months recorded" << endl;
	cout << cD << " days recorded" << endl;
	cout << cH << " hours recorded" << endl;
	cout << cMi << " minutes recorded" << endl;
	cout << cS << " seconds recorded" << endl;
	return 0;
}