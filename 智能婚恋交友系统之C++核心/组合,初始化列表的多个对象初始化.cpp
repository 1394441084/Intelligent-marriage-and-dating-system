/*
����һ�������࣬��������������
�������ж����̥��һ����������Ʒ�ƣ��ͺ�, �۸� ��ʻ��̡�
��̥����Ʒ�ƣ��ߴ磬��ѹ��
����������Ʒ�ƣ��ͺš�
*/
#include "Car.h"

int main(void) {
	{
	Car car("����Ʒ��0", "�����ͺ�0", 100000,"������Ʒ��0", 6.6,"��̥Ʒ��");
	cout << car.description() << endl;

	Car hh = car;
	cout << hh.description() << endl;
	}

	system("pause");
	return 0;
}