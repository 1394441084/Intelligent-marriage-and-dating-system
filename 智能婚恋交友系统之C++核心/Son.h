#pragma once
#include "Father.h"

//class Son : protected Father{//保护继承方式:Son继承Father的成员内容(public变为protected,其它不变),夫妻继承法(自己内可以用,但不能告诉别人)
//class Son : private Father {//私有继承方式:Son继承Father的成员内容(但访问权限全变为private),私生儿继承法(继承给你(用不了),还不能说)
class Son : public Father {//公有继承方式:Son继承Father的成员内容,public和protected都能直接访问,亲生儿继承法

public:
	Son();
	Son(const char* name, int age, const char* game);
	~Son();
	
	string getgame()const;//打什么游戏
	//调用描述方法,会先调用自己的...
	//如果没有就会去父类继承的方法寻找,如果找到就调用(因为描述方法父类也有,也就是子类有两种)
	string description()const;//描述

private:
	string game;//游戏

};

