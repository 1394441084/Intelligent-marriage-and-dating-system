#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//ս������
#define POWER_XXZ		1000		 //������ս��������ϵ��
#define POWER_LINGSHI	0.1			 //��ʯս������ϵ��
#define POWER_BEAST		0.1			 //����ս������ϵ��

//�����߼���
enum class FairyGrade {
	LIANQI,		//������
	ZHUJI,		//������
	JIEDAN,		//�ᵤ��
	YUANYING,	//ԪӤ��
	HUASHEN,	//������
	LIANXU,		//������
	HETI,		//������
	DACHENG,	//�����
	DUJIE,		//�ɽ���
	//ZONGJIBIE	//�ܵȼ�
};

class LingShi;
class MonsterBeast;

//��������
class CultivateImmortality
{
public:
	//Ĭ�Ϲ��캯��
	CultivateImmortality(const char* name="����", const char* united="��", FairyGrade grade= FairyGrade::LIANQI);

	//�ڿ�
	void dig();
	//ȥ�г�����������
	bool trading();
	//ȥ�г���ָ��������*
	bool trading(const MonsterBeast& beast);
	//���Լ���ʯ������������ָ������(�Լ�,��������)
	bool trading(CultivateImmortality& Immortality,const MonsterBeast& beast);
	//���Լ�ָ�������޺����˽���ָ������(�Լ�����,����,��������)
	bool trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality,const MonsterBeast& otherbeast);
	//���Լ�ָ����������������,�Ի�ȡ��ʯ(�Լ�����,����)
	bool trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality);
	//�Լ���ս����
	int OneselfPower()const;
	//��������
	bool CatchMonsterBeast(const MonsterBeast& beast);
	//���<<���������
	friend ostream& operator<<(ostream& os, const FairyGrade& grade);
	friend ostream& operator<<(ostream& os,const CultivateImmortality& Immortality);
	
	//����Ƿ���ָ��������
	bool IsThereSuchAMonster(const MonsterBeast& beast)const;
	//�Ƴ�ָ������
	bool RemovedFromTheMonster(const MonsterBeast& beast);
private:
	string name;				//����
	string united;				//����
	FairyGrade grade;			//�����߼���
	vector<LingShi>shi;			//��ʯ�ʲ�
	vector<MonsterBeast>beast;	//�����ʲ�
	bool raw;					//��;��Ϊ��,��Ϊ��

	
	//��������������
	void DeathOfYogi();
};

	//ostream& operator<<(ostream& os, const CultivateImmortality& Immortality);

