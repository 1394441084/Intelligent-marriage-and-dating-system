#include "Son.h"

//û����ʽ���ø���Ĺ��캯��,���Զ����ø����Ĭ�Ϲ��캯��
Son::Son()//:Father("Son",0)
{
	//name = "";
	//age = 0;
	game = "��Ϸ";
}

//����Son����ʱ�����Ĭ�Ϲ��캯��
//���ȵ��ø���Ĺ��캯��,������ʶ���Ӹ���̳�����������
//�ٵ����Լ��Ĺ��캯��,������ʼ���Լ����������
//(��Ϊ��Щ�����ǴӸ����Ǽ̳�������,�������಻֪����ι���)
Son::Son(const char* name, int age, const char* game):Father(name,age){//��������ʽ���ø��๹�캯��,�Զ����ö�Ӧ�汾�Ĺ��캯��
	//û�����ָ���Ĺ��캯��,�Ǿͻ��Զ����ø����Ĭ�Ϲ��캯��,
	this->game = game;
}

Son::~Son()
{
}

string Son::getgame() const
{
	return game;
}

string Son::description()const {
	//public���м̳з�ʽ:����ĳ�Ա�������޷�ֱ�ӷ��ʴӸ���̳е�private��Ա
	stringstream str;
	str << "  ����:" << getname() << "  ����:" << age <<"  ��Ϸ:"<< game << endl;
	return str.str();
}