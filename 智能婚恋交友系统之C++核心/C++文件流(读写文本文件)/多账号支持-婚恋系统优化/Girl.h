#pragma once
#include "Single.h"

#define FACE_COEFFICIENT 100  //��ֵϵ��

class Boy;
//class(Ӣ����˼):��(����ָ"�༶")
class Girl : public Single
{
public://���е�
	Girl();
	Girl(const char* name, int age, int faceScore);
	Girl(const char* name,int age,int height,const char* chest,int faceScore,int salary);
	~Girl();

	/*
	string getname()const;//get����
	int getage()const;//get����
	int getheight()const;//get���
	int getfaceScore()const;//get��ֵ
	int getsalary()const;//getн��*/
	string basic_information()const;//������Ϣ
	
	string getchest()const;//get��
	bool satisfied(const Boy& boy)const;//�Ƿ�����
	static void inputGirls(vector<Girl>&girls);//������girl����ķ����ӿ�
	static void inputGirl(Girl& girl);//���뵥��girl����ķ����ӿ�
	//static(Ӣ����˼):��̬
protected://˽�е�
	string chest="û��chest��";//��Χ
};

