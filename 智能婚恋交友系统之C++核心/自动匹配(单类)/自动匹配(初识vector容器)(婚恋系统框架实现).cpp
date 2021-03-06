#include "Boy.h"

using namespace std;

void autoPair(const vector<Boy>&boys,const vector<Girl>&girls) {//自动匹配函数
	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//判断双方是否满意
				cout << boys[i].basic_information() << "<==>" <<
					girls[j].basic_information() << endl;//满意则打印出双方各自信息
			}
		}
	}
}

int main(void) {
	//初识vector容器
	while (0) {//vector容器示例： 
	vector<int>data;//内容可变的int类型数组
	data.push_back(1);//尾部添加数据
	data.push_back(5);//第二成员是5

	for (int i = 0; i < data.size(); i++) {
		cout << data[i];
		cout << " ";
	}
	cout << endl;
	//cout << data[0] << " " << data[1] << endl;
	vector<Boy>boys;//boys是对象数组般的存在
	vector<Girl>girls;
	Boy boy1("周伟长", 25, 175, "幼儿园毕业", -4000, -100);
	Boy boy2("别人", 18, 185, "富二代学院毕业", 400000, 100);
	boys.push_back(boy1);
	boys.push_back(boy2);

	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].basic_information() << endl;
	}
	break;
	}

	//实现自动匹配
	while (1) { 
		/*测试文本
杨过 15000 985/211 
郭靖 8000 大专
段誉 50000 富二代
0
小龙女 18 95
如花  25 79
秋香  26 90
李莫愁 30 100
0
		*/

	vector<Boy>boys;//空容器
	vector<Girl>girls;
	Boy::inputBoys(boys);//boys是引用参数
	Girl::inputGirls(girls);
	cout << "-----------输出结果--------------\n";
	autoPair(boys,girls);
	break;
	}

	//vector容器的陷阱,vector(英语意思):矢量,向量;
	while (0) { 
		Boy boy1, boy2, boy3;//定义了三个对象
		vector<Boy>boys;//定义了boys[]对象;
		boys.push_back(boy1);//push_back方法:boys[0]=boy1;进行了类似拷贝构造函数,不是调用自定义的
		boys.push_back(boy2);
		boys.push_back(boy3);
		
		boys[0].vectortest();//改的是boys[]数组的值
		cout<<"vector对象:"<<boys[0].getage() << endl;
		cout << "boy1对象:" << boy1.getage() << endl;
		
		break; }


	system("pause");
	return 0;
}