/*
定义一个或多个类，来描述以下需求：
汽车，有多个轮胎，一个发动机，品牌，型号, 价格， 行驶里程。
轮胎，有品牌，尺寸，气压。
发动机，有品牌，型号。
*/
#include "Car.h"

int main(void) {
	{
	Car car("汽车品牌0", "汽车型号0", 100000,"发动机品牌0", 6.6,"轮胎品牌");
	cout << car.description() << endl;

	Car hh = car;
	cout << hh.description() << endl;
	}

	system("pause");
	return 0;
}