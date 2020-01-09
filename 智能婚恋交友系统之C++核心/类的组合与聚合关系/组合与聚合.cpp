#include "computer.h"
#include "Speaker.h"

void test(Speaker *box) {
	computer mycomputer("intel","i9",1000,16);//computer和cpu同生共死,组合关系
	mycomputer.addSpeaker(box);//computer和Speaker是聚合关系
}

int main(void) {
	Speaker box;
	test(&box);
	system("pause");
	return 0;
}