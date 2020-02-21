#include <iostream>
#include "clockType.h"
#include "extClockType.h"

using namespace std;

int main()
{
	extClockType clock1, clock2;
	int cY = 0, cMo = 0, cD = 0, cH = 0, cMi = 0, cS = 0;
	string tZ = " ";
	clock1.setTime("Eastern", 0, 2, 21, 8, 10, 0);
	clock2.setTime("Mountain", 0, 2, 21, 6, 10, 0);
	clock1.printTime();
	cout << endl << endl;
	clock2.printTime();
	cout << endl << endl;
	if (clock1.equalTime(clock2))
		cout << "The two times are equal." << endl;
	cout << endl;
	clock1.getTime(tZ, cY, cMo, cD, cH, cMi, cS);
	cout << tZ << " Time Zone" << endl;
	cout << cY << " years recorded" << endl;
	cout << cMo << " months recorded" << endl;
	cout << cD << " days recorded" << endl;
	cout << cH << " hours recorded" << endl;
	cout << cMi << " minutes recorded" << endl;
	cout << cS << " seconds recorded" << endl;
	clock1.incrementHours();
	clock1.incrementMinutes();
	cout << endl << endl;
	clock1.getTime(tZ, cY, cMo, cD, cH, cMi, cS);
	cout << tZ << " Time Zone" << endl;
	cout << cY << " years recorded" << endl;
	cout << cMo << " months recorded" << endl;
	cout << cD << " days recorded" << endl;
	cout << cH << " hours recorded" << endl;
	cout << cMi << " minutes recorded" << endl;
	cout << cS << " seconds recorded" << endl;
	return 0;
}