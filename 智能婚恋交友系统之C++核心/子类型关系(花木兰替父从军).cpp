#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;
//子类关系(一)
class HmlFq {
public:
	HmlFq(){}
	~HmlFq(){}
	void kill() { cout << "花木兰父亲.kill\n"; }

private:

};

class Hml : public HmlFq {
public:
	Hml(){}
	~Hml(){}
	void kill() { cout << "花木兰.kill\n"; }
private:

};

void tifucongjun(HmlFq HmlFq) {
	//形参作为基类对象时,实参可以是派生类对象(子类对象)
	//只有public继承方式才能代替,其它继承方式不能这样搞 
	HmlFq.kill();//调用的式HmlFq.kill()方法,子类完全可以代替父类
}

//子类关系(二)
class Father {
public:
	void play() {
		cout << "今天吃肉\n";
	}
};
class Son : public Father {
public:
	void play() {
		cout << "今天吃土\n";
	}
	void ccc() {
		cout << "neng?\n";
	}
};

void party(Father* a,Father* b) {
	a->play();
	b->play();
}

int main(void) {
	while (0) { //子类型关系(一),子类型作用
	HmlFq HmlFq;
	Hml hml;
	tifucongjun(hml);
	hml.kill();
	break;
	}

	while (0) { //子类型关系(二)
		Father a;
		Son b;
		party(&a, &b);
		break;
	}

	while (1) {//父类对象指针可以指向子类对象
		Son son;
		Father *father = &son;
		father->play();//只能调用父类的成员

		//Father f;
		//Son *s = &f;//子类对象指针不能指向父类对象

		Father& f1 = son;//公有派生类的对象可以初始化基类的引用
		f1.play();//和上面的父类指针一样

		Father B = son;//父类对象可以直接被赋值为子类对象

		//以上反过来就会编译错误
		break;
	}


	system("pause");
	return 0;
}