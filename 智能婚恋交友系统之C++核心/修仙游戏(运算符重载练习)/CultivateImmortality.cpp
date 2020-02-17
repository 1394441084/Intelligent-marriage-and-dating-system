#include "CultivateImmortality.h"
#include "LingShi.h"
#include "MonsterBeast.h"

CultivateImmortality::CultivateImmortality(const char* name, const char* united, FairyGrade grade)
{
	this->name = name;
	this->united = united;
	this->grade = grade;
	this->raw = true;
}

void CultivateImmortality::dig()
{
	//�õ�100�������ʯ(+100)
	shi.push_back(LingShi(100, LingShiGrade::PRIMARY));
}

bool CultivateImmortality::trading()
{
	//�ж��Լ�����
	if (!raw) { cout << "������,���׸�ëѽ!\n"; return false; }

	//�����������޵õ���ʯ
	LingShi lingshi;
	for (int i = 0; i < beast.size(); i++) {
		lingshi = lingshi+ beast[i].MuchValue();
	}
	shi.push_back(lingshi);//�Ž���ʯ�ֿ�

	//����û����,���;//���(��ʼλ,����λ);
	beast.erase(beast.begin(), beast.end());

	return false;
}

bool CultivateImmortality::trading(const MonsterBeast& beast)
{
	//�ж��Լ�����
	if (!raw) {cout << "������,���׸�ëѽ!\n";return false;}

	//����Ƿ���ָ��������
	if (!IsThereSuchAMonster(beast)) {
		cout << name << "û��" << beast << endl;
		return false;
	}

	//�������޼�ֵ����������ʯ������ʯ��
	LingShi lingshi = beast.MuchValue();
	shi.push_back(lingshi);

	//��ָ�����޴����޿��Ƴ�
	RemovedFromTheMonster(beast);

	return true;
}

bool CultivateImmortality::trading(CultivateImmortality& Immortality, const MonsterBeast& beast)
{
	//�ж�˫���Ƿ񶼴��
	if (!(raw && Immortality.raw)) {
		cout << "����˫������������״̬,�����޷�����!\n";
		return false;
	}
	//�ж϶Է��Ƿ��д�����
	if (!Immortality.IsThereSuchAMonster(beast)) {
		cout << Immortality.name << "û��" << beast << endl;
		return false;
	}
	//�����Լ�����ʯ��(��λ:����)
	LingShi lingshi;
	for (int i = 0; i < shi.size(); i++) {
		lingshi = lingshi + shi[i];
	}
	//�ж��Ƿ���Ǯ��������
	if (lingshi >= beast.MuchValue()) {
		//LingShi beastvalue = beast.MuchValue();//���޼�ֵ���ٿ������ʯ
		lingshi = lingshi - beast.MuchValue();//�Լ�����ʯ-���޼�ֵ=ʣ����ʯ
		shi.clear();//�����ʯ��
		shi.push_back(lingshi);//��ʣ������ʯ���������Լ���ʯ��
		this->beast.push_back(beast);//�����������Լ����޿�

		//Immortality.trading(beast);//����ֱ�������,��������Ĵ�����ʱ����
		Immortality.RemovedFromTheMonster(beast);//�����޴��������޿��Ƴ�
		Immortality.shi.push_back(beast.MuchValue());//����������ͬ�ȼ�ֵ����ʯ
		return true;
	}
	else {
		cout << "��Ǹ!" << name << "����ʯ������" << beast << endl;
		return false;
	}
}

bool CultivateImmortality::trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality, const MonsterBeast& otherbeast)
{
	//�ж�˫���Ƿ񶼴��
	if (!(raw && otherImmortality.raw)) {
		cout << "����˫������������״̬,�����޷�����!\n";
		return false;
	}
	//�ж��Ƿ�ͬ�⽻������;���޵ȼ�,�����Ƿ����||���޿���û��||���޼�ֵ�Ƿ����
	if(beast == otherbeast ||
		!IsThereSuchAMonster(beast)||
		!otherImmortality.IsThereSuchAMonster(otherbeast)||
		!(beast.MuchValue()>=otherbeast.MuchValue())
		) {
		return false;
	}

	//�����ǽ�����
	//�Ƴ�˫������
	RemovedFromTheMonster(beast);
	RemovedFromTheMonster(otherbeast);
	//��������������ӵ��������޿�
	this->beast.push_back(otherbeast);
	otherImmortality.beast.push_back(beast);

	return true;
}

bool CultivateImmortality::trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality)
{
	//�ж�˫���Ƿ񶼴��
	if (!(raw && otherImmortality.raw)) {
		cout << "����˫������������״̬,�����޷�����!\n";
		return false;
	}

	//�ж������Ƿ�ӵ�кͶԷ��Ƿ��й�����
	LingShi lingshi;
	for (int i = 0; i < otherImmortality.shi.size(); i = i + 1) {
		lingshi = lingshi + otherImmortality.shi[i];
	}
	if (IsThereSuchAMonster(beast) && (lingshi >= beast.MuchValue())) {
		RemovedFromTheMonster(beast);//�Ƴ��Լ�����
		otherImmortality.beast.push_back(beast);//�����������
		otherImmortality.shi.clear();//���������ʯ��
		lingshi = lingshi - beast.MuchValue();//ʣ����ʯ
		otherImmortality.shi.push_back(lingshi);//������ʣ����ʯ����������ʯ��
		this->shi.push_back(beast.MuchValue());//������������ʯ�����Լ���ʯ��
		return true;
	}
	else {//�������
		cout << "û�й����˻����Լ�û������\n";
		return false;
	}

	//�������
	return false;
}

int CultivateImmortality::OneselfPower() const
{
	//���������߼���ս����
	int power = ((int)grade + 1) * POWER_XXZ;

	//������ʯ����ս����
	LingShi lingshi;
	for (int i = 0; i < shi.size(); i++) {
		lingshi = lingshi + shi[i];
	}
	power += lingshi.getNumber() * POWER_LINGSHI;

	//������������ս����
	for (int i = 0; i < this->beast.size(); i++) {
		power += this->beast[i].getMonster() * POWER_BEAST;
	}

	return power;
}

bool CultivateImmortality::CatchMonsterBeast(const MonsterBeast& beast)
{
	if (OneselfPower() > beast.getMonster()) {
		//Ӯ�˵õ�����
		this->beast.push_back(beast);
		return true;
	}
	else {
		//����:��!!!
		DeathOfYogi();
		return false;
	}
}

bool CultivateImmortality::IsThereSuchAMonster(const MonsterBeast& beast)const
{
	//�������޿⿴�Ƿ���ָ������
	for (int i = 0; i < this->beast.size(); i++) {
		if (this->beast[i] == beast) {
			return true;
		}
	}

	//���޿ⶼû����,����false
	return false;
}

bool CultivateImmortality::RemovedFromTheMonster(const MonsterBeast& beast)
{
	//����һ��������(����ָ��),it=this->beast.begin();//ָ�����޿�ĵ�һ����Ա
	vector<MonsterBeast>::iterator it = this->beast.begin();
	//.end();����Ա����һ��λ��
	while (it != this->beast.end()) {
		if (*it == beast) {
			it=this->beast.erase(it);
			return true;
		}
		else {
			it++;
		}
	}

	return false;
}

void CultivateImmortality::DeathOfYogi()
{
	raw = false;//����״̬��Ϊ��
	shi.erase(shi.begin(), shi.end());//��ʯ�����
	beast.erase(beast.begin(), beast.end());//���޿����
}

ostream& operator<<(ostream& os, const FairyGrade& grade)
{
	switch (grade) {
	case FairyGrade::LIANQI:
		os << "������";
		break;
	case FairyGrade::ZHUJI:
		os << "������";
		break;
	case FairyGrade::JIEDAN:
		os << "�ᵤ��";
		break;
	case FairyGrade::YUANYING:
		os << "ԪӤ��";
		break;
	case FairyGrade::HUASHEN:
		os << "������";
		break;
	case FairyGrade::LIANXU:
		os << "������";
		break;
	case FairyGrade::HETI:
		os << "������";
		break;
	case FairyGrade::DACHENG:
		os << "�����";
		break;
	case FairyGrade::DUJIE:
		os << "�ɽ���";
		break;
	default:
		os << "��Ѿ��ͻ������˶�!!!";
		break;
	}
	return os;
}

ostream& operator<<(ostream& os, const CultivateImmortality& Immortality)
{
	os << "[������]" << Immortality.name << (Immortality.raw ? "����" : "����")
		<< "\t����:" << Immortality.united << "\t����:" << Immortality.grade;

	LingShi lingshi;
	for (int i = 0; i < Immortality.shi.size(); i++) {
		lingshi = lingshi + Immortality.shi[i];
	}

	os << "\t��ʯ:" << lingshi << "\t����:";

	if (!Immortality.beast.size()) {
		os << "��";
	}
	else {
		for (int i = 0; i < Immortality.beast.size(); i++) {
			os << Immortality.beast[i] << " ";
		}
	}

	return os;
}

