#include "Computer.h"
#include "ComputerService.h"

void upgrade(Computer *computer) {computer->cpu = "i7";}//全局函数做为友元函数

int main(void) {

	while (0) { //全局函数做为友元函数示例:
	Computer dn;
	cout << "cpu:" << dn.getcpu() << endl;
	cout << "---------------升级--------------\n";
	upgrade(&dn);
	cout << "cpu:" << dn.getcpu() << endl; break;}

	while (1) { //类的友元示例:
		Computer dn;
		ComputerService sj;
		cout << "cpu:" << dn.getcpu() << endl;
		cout << "---------------升级--------------\n";
		sj.upgrade1(&dn);
		cout <<"cpu:"<<dn.getcpu() << endl; 
		sj.clean(&dn);
		sj.kill(&dn);
		break;
	}


	system("pause");
	return 0;
}
/*
为什么要使用友元类
一个独立的咨询师， 给其他企业做服务时，这个咨询师作为企业的“友元函数”即可。

一个大型的咨询服务公司，比如IBM（IT事务）, 普华永道（会计事务），给其他企业做服务时，使用友元函数就不是很方便了，因为需要设计很多友元函数，不方便。

解决方案：使用“友元类”
*/