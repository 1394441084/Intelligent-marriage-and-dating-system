#include "Boy.h"

using namespace std;

void autoPair(const vector<Boy>&boys,const vector<Girl>&girls) {//�Զ�ƥ�亯��
	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//�ж�˫���Ƿ�����
				cout << boys[i].basic_information() << "<==>" <<
					girls[j].basic_information() << endl;//�������ӡ��˫��������Ϣ
			}
		}
	}
}

int main(void) {
	//��ʶvector����
	while (0) {//vector����ʾ���� 
	vector<int>data;//���ݿɱ��int��������
	data.push_back(1);//β���������
	data.push_back(5);//�ڶ���Ա��5

	for (int i = 0; i < data.size(); i++) {
		cout << data[i];
		cout << " ";
	}
	cout << endl;
	//cout << data[0] << " " << data[1] << endl;
	vector<Boy>boys;//boys�Ƕ��������Ĵ���
	vector<Girl>girls;
	Boy boy1("��ΰ��", 25, 175, "�׶�԰��ҵ", -4000, -100);
	Boy boy2("����", 18, 185, "������ѧԺ��ҵ", 400000, 100);
	boys.push_back(boy1);
	boys.push_back(boy2);

	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].basic_information() << endl;
	}
	break;
	}

	//ʵ���Զ�ƥ��
	while (1) { 
	vector<Boy>boys;//������
	vector<Girl>girls;
	Boy::inputBoys(boys);//boys�����ò���
	Girl::inputGirls(girls);
	cout << "-----------������--------------\n";
	autoPair(boys,girls);

	break;
	}

	system("pause");
	return 0;
}