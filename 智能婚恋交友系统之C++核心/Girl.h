#pragma once
#include <string>
#include <sstream> //stringstream,����������ζ������ܱ�Ϊ�ַ���

using namespace std;
#define FACE_COEFFICIENT 100  //��ֵϵ��

class Boy;

class Girl
{
public:
	Girl();
	Girl(string name, int age, int faceScore);
	Girl(string name,int age,int height,string chest,int faceScore,int salary);
	~Girl();

	string getname()const;//get����
	int getage()const;//get����
	int getheight()const;//get���
	string getchest()const;//get��
	int getfaceScore()const;//get��ֵ
	int getsalary()const;//getн��
	string basic_information()const;//������Ϣ
	bool satisfied(const Boy& boy)const;//�Ƿ�����
	static void inputGirls(vector<Girl>&girls);//������girl����ķ����ӿ�
private:
	string name="û��name��";//����
	int age=0;//����,��λ��
	int height=0;//���,��λcm
	string chest="û��chest��";//��Χ
	int faceScore=0;//��ֵ,����100��
	int salary=0;//н��
};

