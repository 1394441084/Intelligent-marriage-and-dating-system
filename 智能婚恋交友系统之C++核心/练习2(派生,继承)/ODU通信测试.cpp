#include "ODU330.h"
#include <iostream>
#include <Windows.h>

int main(void) {
	ODU odu;
	odu.setBandwidth(500);
	odu.setFrequency(114000);
	odu.setPower(45);
	cout << odu.description() << endl<<endl;

	ODU330 odu330;
	odu330.setBandwidth(600);
	odu330.setFrequency(119000);
	odu330.setPower(50);
	odu330.setAlarmThreshold(0.0001);
	cout << odu330.description() << endl;

	system("pause");
	return 0;
}