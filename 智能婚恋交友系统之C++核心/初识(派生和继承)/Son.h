#pragma once
#include "Father.h"

//class Son : protected Father{//�����̳з�ʽ:Son�̳�Father�ĳ�Ա����(public��Ϊprotected,��������),���޼̳з�(�Լ��ڿ�����,�����ܸ��߱���)
//class Son : private Father {//˽�м̳з�ʽ:Son�̳�Father�ĳ�Ա����(������Ȩ��ȫ��Ϊprivate),˽�����̳з�(�̳и���(�ò���),������˵)
class Son : public Father {//���м̳з�ʽ:Son�̳�Father�ĳ�Ա����,public��protected����ֱ�ӷ���,�������̳з�

public:
	Son();
	Son(const char* name, int age, const char* game);
	~Son();
	
	string getgame()const;//��ʲô��Ϸ
	//������������,���ȵ����Լ���...
	//���û�оͻ�ȥ����̳еķ���Ѱ��,����ҵ��͵���(��Ϊ������������Ҳ��,Ҳ��������������)
	string description()const;//����

private:
	string game;//��Ϸ

};

