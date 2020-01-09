#include "Home.h"

/*
定义一个或多个类，来描述以下需求：

定义一个类，来表示某模拟养成游戏中人物：
每个人物， 有昵称，年龄，性别， 配偶， 朋友,
支持的活动有：结婚，离婚, 交友，断交，询问昵称，询问性别，询问年龄, 简介等。
*/

int main(void) {
	Home hwx("何宛夏", 24, women);
	Home zsf("张三疯", 106, man);
	Home ym("杨幂", 33, women);
	Home dlrb("迪丽热巴", 28, women);
	Home zwc("周伟长", 24, man);
	
	cout << "-----------------结婚-----------------\n";
	zwc.Marriage(hwx);
	Home* who = zwc.getspouse();
	cout << zwc.getnickname() << "的老婆是:" << who->Brief_introduction()<< endl;
	cout << who->getnickname() << "的老公是:" << who->getspouse()->Brief_introduction() << endl;
	cout << "\n-----------------离婚-----------------\n";
	//hwx.divorce();
	if (hwx.getspouse() == NULL) {
		cout << hwx.getnickname() << "单身了\n";
	}
	else {
		cout << hwx.getnickname()<<"没离,和"<<hwx.getspouse()->getnickname()<<"恩爱呢\n";
	}
	cout << "\n-----------------交友-----------------\n";
	zwc.MakeFriends(ym);
	zwc.MakeFriends(zsf);
	zwc.MakeFriends(dlrb);
	//auto friends = zwc.getfriends();和下面一样
	vector<Home*>friends = zwc.getfriends();
	for (int i = 0; i < friends.size(); i++) {//所有朋友的信息打印
		cout << friends[i]->Brief_introduction() << endl;
	}
	cout << "\n-----------------断交-----------------\n";
	zwc.Break_Off_Friendship(zsf);
	cout << zwc.getnickname() << "和" << zsf.getnickname() << "断交了.\n";
	friends = zwc.getfriends();//获取好友列表
	for (int i = 0; i < friends.size(); i++) {//所有朋友的信息打印
		cout << friends[i]->Brief_introduction() << endl;
	}



	system("pause");
	return 0;
}