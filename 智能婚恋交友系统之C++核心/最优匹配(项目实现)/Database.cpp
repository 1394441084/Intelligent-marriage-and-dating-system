#include "Database.h"

Database::Database()
{
}

void Database::init(){//��֮ǰ�Ѿ�������ļ��ж�ȡ�û���Ϣ,����ʶ���ڲ�����,boys��girls
	initBoysFromFile();//���ļ���ʼ��boys��Ϣ
	initGirlsFromFile();//���ļ���ʼ��girls��Ϣ
}

void Database::autoPair(){
	cout << "\n�Զ���Խ��\n";
	string str(100, '-');//str�ַ�����100���ַ�'-'
	cout << str << endl;

	//��ʿ��ѡ���
	cout << "---------------��ʿƥ�䵽��Ůʿ-------------\n";
	for (int i = 0; i < boys.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		for (int j = 0; j < girls.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//�ж�˫���Ƿ�����
				cout << boys[i].basic_information() << endl;
				cout << girls[j].basic_information() << endl;//�������ӡ��˫��������Ϣ
				cout << str << endl;
			}
		}
	}

	//Ůʿ��ѡ���
	cout << "---------------Ůʿƥ�䵽����ʿ-------------\n";
	for (int i = 0; i < girls.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		for (int j = 0; j < boys.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//�ж�˫���Ƿ�����
				cout << girls[i].basic_information() << endl;
				cout << boys[j].basic_information() << endl;//�������ӡ��˫��������Ϣ
				cout << str << endl;
			}
		}
	}
}

void Database::print() {
	cout << "�мα���Ϣ:\n";for (int i = 0; i < boys.size(); i++) {cout << boys[i].basic_information() << endl;}
	cout << "Ů�α���Ϣ:\n";for (int i = 0; i < girls.size(); i++) { cout << girls[i].basic_information() << endl; }
}

void Database::initBoysFromFile(){//���ļ�,���ļ�����,��ʼ��Boys
	ifstream stream;
	stream.open(BOYS_FILE);
	if(!stream.is_open()){//��ʧ��
	//�ʼû���ļ�!//�����ʼû���ļ�,���û���������û�����
		cout << "===��������û�[�мα�]����===\n";
		Boy::inputBoys(this->boys);
		saveBoys();//����Boys��Ϣ���ļ�
		stream.close();
		return;
	}
	
	//�ļ��򿪳ɹ�
	//while (!stream.eof()) {//��ȡ��eof�������Ž���,������λ��ָ��ָ�����������
	while (1) {
		string line="";
		char name[64] = "";
		int salary = 0;
		//string degree ;//ʹ��string���Ͳ��ܽ���sscanf_s���������ַ�,�����Ľ����������
		char degree[64] = "";
		int age = 0;
		getline(stream, line);//����һ��
		if (stream.eof()) { break; }//��������ȡ����,�˳�
		//����������һ������,
	//������ʽ:ret << "�Ա�:��\t\t����:"<<getname() << "\t\tн��:" << salary << "\t\tѧ��:" << degree << "\t\t����:" <<getage() ;
		unsigned int ret=sscanf_s(line.c_str(),"�Ա�:��   ����:%s   н��:%d   ѧ��:%s  ����:%d",
			name, sizeof(name), &salary,degree,sizeof(degree),&age);//�ո����ƥ�����հ��ַ�,ret�����Ǳ��ڹ۲���û�����ɹ�

		//sscanf_s�ķ���ֵ,����Ҫunsigned int�������������н���,�����ܵ���
		if (ret < 0) {cout << "�мα����ݿ��ʽ����ʧ��!\n"; exit(2);}
		 boys.push_back(Boy(name, salary, degree)); 
		//ʹ�ö����ĵ�������Ϣ,����һ��Boy����,����ӵ�boys��//boys.push_back(Boy(string(name),salary,degree));
	}
	stream.close();
}

void Database::initGirlsFromFile(){
	//���ļ�,���ļ�����,��ʼ��Girls
	ifstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) {//��ʧ��
	//�ʼû���ļ�!//�����ʼû���ļ�,���û���������û�����
		cout << "===��������û�[Ů�α�]����===\n";
		Girl::inputGirls(this->girls);
		saveGirls();//����Girls��Ϣ���ļ�
		stream.close();
		return;
	}

	//�ļ��򿪳ɹ�
	while (1) {
		string line = "";
		char name[64] = "";
		int faceScore = 0;
		int age = 0;
		getline(stream, line);//����һ��
		if (stream.eof()) { break; }//��������ȡ����,�˳�
		//����������һ������,
		//������ʽ:ret <<"�Ա�:Ů\t\t����:"<< getname() << setw(3) << setiosflags(ios::left) 
		//<<"\t\t����:" << getage()<< "\t\t��ֵ:" << faceScore <<"\t\t��Χ:" << chest << "\n";
		//�ո����ƥ�����հ��ַ�,ret�����Ǳ��ڹ۲���û�����ɹ�
		unsigned int ret=sscanf_s(line.c_str(),"�Ա�:Ů ����:%s ����:%d ��ֵ:%d",
			name,sizeof(name),&age,&faceScore);//��û��
		if (ret <= 0) { cout << "Ů�α����ݿ��ʽ����ʧ��!\n"; exit(3); }else{ girls.push_back(Girl(name, age, faceScore)); }
	}
	stream.close();
}

void Database::addOne(Boy& boy)
{
	boys.push_back(boy);
	cout << "\n�Զ���Խ��\n";
	string str(100, '-');//str�ַ�����100���ַ�'-'
	cout << str << endl;
	
		for (int j = 0; j < girls.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boy.satisfied(girls[j]) && girls[j].satisfied(boy)) {//�ж�˫���Ƿ�����
				cout << boy.basic_information() << endl;
				cout << girls[j].basic_information() << endl;//�������ӡ��˫��������Ϣ
				cout << str << endl;
			}
		}
}

void Database::addOne(Girl& girl)
{
	girls.push_back(girl);
	cout << "\n�Զ���Խ��\n";
	string str(100, '-');//str�ַ�����100���ַ�'-'
	cout << str << endl;

	for (int j = 0; j < boys.size(); j++) {
		//cout << girls[j].getfaceScore() << endl;
		if (girl.satisfied(boys[j]) && boys[j].satisfied(girl)) {//�ж�˫���Ƿ�����
			cout << girl.basic_information() << endl;//�������ӡ��˫��������Ϣ
			cout << boys[j].basic_information() << endl;
			cout << str << endl;
		}
	}
}

void Database::autoBestMate()
{
	cout << "\n�Զ������Ѱ���\n";
	string str(100, '-');//str�ַ�����100���ַ�'-'
	cout << str << endl;

	//��ʿ������Ůʿ
	cout << "---------------��ʿ������Ůʿ-----------\n";
	for (int i = 0; i < boys.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		Girl* girlBest = NULL;
		for (int j = 0; j < girls.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//�ж�˫���Ƿ�����

				if (!girlBest) {
					girlBest = &girls[j];
				}else if (girls[j] > * girlBest) {
						girlBest = &girls[j];
				}
			}
		}
		//��Щ��ʿ�ͱ�����,�Ҳ�������,���������������,�����
		if(girlBest){//���Ű����ҵ��˾ʹ�ӡ����
		//cout << boys[i].basic_information() << endl;
			cout << boys[i] << endl;
		//cout << girlBest->basic_information() << endl;
			cout << *girlBest << endl;
		cout << str << endl;
		}
	}

	//Ůʿ��������ʿ
	cout << "---------------Ůʿ��������ʿ-----------\n";
	for (int i = 0; i < girls.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		Boy* boyBest = NULL;
		for (int j = 0; j < boys.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//�ж�˫���Ƿ�����

				if (!boyBest) {
					boyBest = &boys[j];
				}
				else if (boys[j] > * boyBest) {
					boyBest = &boys[j];
				}
			}
		}
		//��ЩŮʿ�ͱ�����,�Ҳ����Ϲ�,���������������,�����
		if (boyBest) {//���Ű����ҵ��˾ʹ�ӡ����
		//cout << boys[i].basic_information() << endl;
			cout << girls[i] << endl;
			//cout << girlBest->basic_information() << endl;
			cout << *boyBest << endl;
			cout << str << endl;
		}
	}

}

void Database::saveBoys(){//��boys�����е���Ϣд���ļ�
	ofstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {cout << "saveBoys()д���ļ�ʧ��\n"; exit(1);}

	for (int i = 0; i < boys.size(); i++) {
		stream << boys[i].basic_information()<<endl;//�ѵ����еĻ�����Ϣ����stream��
	}
	stream.close();
}

void Database::saveGirls(){//��Girls����Ů����Ϣд���ļ�
	ofstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) { cout << "saveGirls()д���ļ�ʧ��\n"; exit(1); }

	for (int i = 0; i < girls.size(); i++) {
		stream << girls[i].basic_information() << endl;//�ѵ���Ů�Ļ�����Ϣ����stream��
	}
	stream.close();
}
