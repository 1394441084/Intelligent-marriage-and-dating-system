#include "Computer.h"
#include "ComputerService.h"

void upgrade(Computer *computer) {computer->cpu = "i7";}//ȫ�ֺ�����Ϊ��Ԫ����

int main(void) {

	while (0) { //ȫ�ֺ�����Ϊ��Ԫ����ʾ��:
	Computer dn;
	cout << "cpu:" << dn.getcpu() << endl;
	cout << "---------------����--------------\n";
	upgrade(&dn);
	cout << "cpu:" << dn.getcpu() << endl; break;}

	while (1) { //�����Ԫʾ��:
		Computer dn;
		ComputerService sj;
		cout << "cpu:" << dn.getcpu() << endl;
		cout << "---------------����--------------\n";
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
ΪʲôҪʹ����Ԫ��
һ����������ѯʦ�� ��������ҵ������ʱ�������ѯʦ��Ϊ��ҵ�ġ���Ԫ���������ɡ�

һ�����͵���ѯ����˾������IBM��IT����, �ջ�������������񣩣���������ҵ������ʱ��ʹ����Ԫ�����Ͳ��Ǻܷ����ˣ���Ϊ��Ҫ��ƺܶ���Ԫ�����������㡣

���������ʹ�á���Ԫ�ࡱ
*/