#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//电话类
class Tall {//子类成继承后,此时共同的基类就成为"虚基类"
public:
	Tall(const char* number="基基类") {
		this->number = number;
	}

protected:
	string number;//电话号码
};

//座机类
class Landline :virtual public Tall {};//变为虚继承

//手机类
class Phone :virtual public Tall{};//虚继承

//无线座机类
class WirelessTel :public Landline, public Phone {
public:
	void setnumber(const char* number) {
		this->number = number;//调用不明确,加了virtual就明确了直接访问number
		//this->Landline::number = number;
	}

	string getnumber() {
		//return this->Phone::number;
		return number;//直接访问number
	}
};

int main(void) {
	while (1) { 
	WirelessTel phone;
	phone.setnumber("123456");
	cout << phone.getnumber() << endl;
	//多重继承在菱型继承中的重大缺陷:浪费空间,访问权限不明确(很不方便)
	//虚继承和虚基类就没有上面的缺陷了
	//虚继承共同的成员只备份一份,这样就不会浪费空间和访问权限不明确了
	break;
	}

	system("pause");
	return 0;
}