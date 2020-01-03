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
	vector<Boy>boys;//空容器
	vector<Girl>girls;
	Boy::inputBoys(boys);//boys是引用参数
	Girl::inputGirls(girls);
	cout << "-----------输出结果--------------\n";
	autoPair(boys,girls);

	break;
	}

	system("pause");
	return 0;
}