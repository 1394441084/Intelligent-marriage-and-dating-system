#include "Boy.h"
#include "Database.h"

/*�ع�����:
��ȡ��ͬ��Ա������һ��Single(δ��,�����)��,�Ӷ���Single��(����)�м̳�
������Ӧ���޸�
*/
/*
void autoPair(const vector<Boy>& boys, const vector<Girl>& girls) {//�Զ�ƥ�亯��
	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//�ж�˫���Ƿ�����
				cout << boys[i].basic_information() << "<==>" <<
					girls[j].basic_information() << endl;//�������ӡ��˫��������Ϣ
			}
		}
	}
}*/

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
	while (0) { 
	vector<Boy>boys;//������
	vector<Girl>girls;
	Boy::inputBoys(boys);//boys�����ò���
	Girl::inputGirls(girls);
	cout << "-----------������--------------\n";
	//autoPair(boys,girls);
	break;
	}

	//vector����������,vector(Ӣ����˼):ʸ��,����;
	while (0) { 
		Boy boy1, boy2, boy3;//��������������
		vector<Boy>boys;//������boys[]����;
		boys.push_back(boy1);//push_back����:boys[0]=boy1;���������ƿ������캯��,���ǵ����Զ����
		boys.push_back(boy2);
		boys.push_back(boy3);
		
		boys[0].vectortest();//�ĵ���boys[]�����ֵ,������boy1��ֵ,�൱���Ǹ���
		cout<<"vector����:"<<boys[0].getage() << endl;
		cout << "boy1����:" << boy1.getage() << endl;
		
		break; }
	//Girl girl("������", 24, 161, "38B", 45, 3000);

	//���˺�֧��-�����Զ�ƥ��ϵͳ
	while (0) {
		Database data;
		data.init();
		data.print();
		data.autoPair();
		break;
	}

	//���ӵ����û����빦��
	while (1) { 
		Database data;
		data.init();
		Boy boy;
		Boy::inputBoy(boy);
		data.addOne(boy);
		
		Girl girl;
		Girl::inputGirl(girl);
		data.addOne(girl);
		break; }

	system("pause");
	return 0;
}
/*�����ı�
��� 15000 985/211
���� 8000 ��ר
���� 50000 ������
0
С��Ů 1888 95
�绨  25 79
����  26 90
��Ī�� 30 100
0
		*/