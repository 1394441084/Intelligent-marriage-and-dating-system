#include "computer.h"
#include "Speaker.h"

void test(Speaker *box) {
	computer mycomputer("intel","i9",1000,16);//computer��cpuͬ������,��Ϲ�ϵ
	mycomputer.addSpeaker(box);//computer��Speaker�ǾۺϹ�ϵ
}

int main(void) {
	Speaker box;
	test(&box);
	system("pause");
	return 0;
}