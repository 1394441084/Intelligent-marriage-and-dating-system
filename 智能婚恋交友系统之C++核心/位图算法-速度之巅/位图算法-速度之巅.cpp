#include <iostream>
#include <stdio.h>
#include <Windows.h>
//�����ռ任ȡ�ٶ�
using namespace std;

#define DSJ 4000000000;//40��

void init(char *data, int len) {
	//����ʵ��������ʵ��,Ϊ�˲��Ժ�����㷨Ч��,����:�ܱ�3��������,�������������
	unsigned int n = len * 8;//һ����n������
	for (unsigned int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			char* p = data + i / 8;//�������λ��Ӧ�ĸ��ֽ�
			//i%8;ȡλ���ֽڵڼ�λ(һ���ֽ�8λ:0 0 0 0 0 0 0 0)
			//(1<<(i%8));��1�ƶ�����Ӧ��λ
			*p = *p | (1 << (i % 8));//ʹ��λ�����ʹ��Ӧ���ֽڱ�Ϊ1
		}
	}

}

//λͼ�㷨
bool check(char* data, int len,unsigned int value) {
	char* p = data + value / 8;//��λ��ָ�����ֽ�
	bool ret = *p & (1 << value % 8);//�ж�����ֽ���ָ����λ�Ƿ�Ϊ1
	return ret;
}

int main(void) {
	//����һ���㹻����ڴ�,������ʾλͼ
	//char,һ���ֽ��ܴ��8Ϊ����
	//  ����7�Ƿ��ڴ˼���,��1,�ڵ�
	// 0 1 2 3 4 5 6 7 8 9 10 11 12    �������ݼ���
	// 0 0 0 0 0 0 1 0 0 0  0  0  0    �����⵽��Ҫ��������ô��Ϊ1 
	unsigned int n = DSJ;
	int len = 0;
	
	n >= 8 ? len = n / 8 : len = n / 8 + 1;//if (n>= 8) {len = n / 8;}else {len = n / 8+1;//�Ӷ�1�ֽ���Ϊ��ֹ:n/С��8����=0��.}
	
	char* data = (char*)malloc(len);//����ռ�
	if (data != 0) {
		memset(data, 0, len);//����,(��ʼλ��,��Ϊ0,len���ֽ�)ȫ����Ϊ0;
	}
	cout << "���ڼ�����.....\n";
	init(data, len);//װ�����ݼ���(ֻ��Ҫװ��һ��)
	system("cls");
	while (1) {
		
		printf("��������Ҫ������:[����-1�˳�]\n");
		unsigned int value; 
		unsigned int n = DSJ;
		scanf_s("%d", &value);
		if (value == -1) { break; }
		else if (value < n) {
			check(data, len, value) ? printf("%d�����ݼ�����.\n", value) : printf("%d�������ݼ�����.\n", value);
		}
		else {
			printf("��ѽ,���ݳ���,���ڴ˼�������\n");
		}
	}
	free(data);
	system("pause");
	return 0;
}