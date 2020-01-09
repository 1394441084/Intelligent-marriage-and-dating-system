#include <iostream>
#include <stdio.h>
#include <Windows.h>
//牺牲空间换取速度
using namespace std;

#define DSJ 4000000000;//40亿

void init(char *data, int len) {
	//根据实际需求来实现,为了测试后面的算法效果,假设:能被3整除的数,都在这个集合中
	unsigned int n = len * 8;//一共有n个数据
	for (unsigned int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			char* p = data + i / 8;//计算这个位对应哪个字节
			//i%8;取位于字节第几位(一个字节8位:0 0 0 0 0 0 0 0)
			//(1<<(i%8));将1移动到对应的位
			*p = *p | (1 << (i % 8));//使用位或操作使对应的字节变为1
		}
	}

}

//位图算法
bool check(char* data, int len,unsigned int value) {
	char* p = data + value / 8;//定位到指定的字节
	bool ret = *p & (1 << value % 8);//判断这个字节中指定的位是否为1
	return ret;
}

int main(void) {
	//分配一块足够大的内存,用来表示位图
	//char,一个字节能存放8为数据
	//  看看7是否在此集合,有1,在的
	// 0 1 2 3 4 5 6 7 8 9 10 11 12    这是数据集合
	// 0 0 0 0 0 0 1 0 0 0  0  0  0    如果检测到需要的数字那么变为1 
	unsigned int n = DSJ;
	int len = 0;
	
	n >= 8 ? len = n / 8 : len = n / 8 + 1;//if (n>= 8) {len = n / 8;}else {len = n / 8+1;//加多1字节是为防止:n/小于8的数=0了.}
	
	char* data = (char*)malloc(len);//分配空间
	if (data != 0) {
		memset(data, 0, len);//清零,(起始位置,设为0,len个字节)全设置为0;
	}
	cout << "正在加载中.....\n";
	init(data, len);//装载数据集合(只需要装载一次)
	system("cls");
	while (1) {
		
		printf("请输入需要检测的数:[输入-1退出]\n");
		unsigned int value; 
		unsigned int n = DSJ;
		scanf_s("%d", &value);
		if (value == -1) { break; }
		else if (value < n) {
			check(data, len, value) ? printf("%d在数据集合中.\n", value) : printf("%d不在数据集合中.\n", value);
		}
		else {
			printf("哎呀,数据超了,不在此集合中呢\n");
		}
	}
	free(data);
	system("pause");
	return 0;
}