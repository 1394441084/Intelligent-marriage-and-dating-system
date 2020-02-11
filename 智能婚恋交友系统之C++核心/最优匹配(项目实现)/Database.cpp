#include "Database.h"

Database::Database()
{
}

void Database::init(){//从之前已经保存的文件中读取用户信息,来初识化内部数据,boys和girls
	initBoysFromFile();//从文件初始化boys信息
	initGirlsFromFile();//从文件初始化girls信息
}

void Database::autoPair(){
	cout << "\n自动配对结果\n";
	string str(100, '-');//str字符串有100个字符'-'
	cout << str << endl;

	//男士能选择的
	cout << "---------------男士匹配到的女士-------------\n";
	for (int i = 0; i < boys.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		for (int j = 0; j < girls.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//判断双方是否满意
				cout << boys[i].basic_information() << endl;
				cout << girls[j].basic_information() << endl;//满意则打印出双方各自信息
				cout << str << endl;
			}
		}
	}

	//女士能选择的
	cout << "---------------女士匹配到的男士-------------\n";
	for (int i = 0; i < girls.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		for (int j = 0; j < boys.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//判断双方是否满意
				cout << girls[i].basic_information() << endl;
				cout << boys[j].basic_information() << endl;//满意则打印出双方各自信息
				cout << str << endl;
			}
		}
	}
}

void Database::print() {
	cout << "男嘉宾信息:\n";for (int i = 0; i < boys.size(); i++) {cout << boys[i].basic_information() << endl;}
	cout << "女嘉宾信息:\n";for (int i = 0; i < girls.size(); i++) { cout << girls[i].basic_information() << endl; }
}

void Database::initBoysFromFile(){//打开文件,读文件内容,初始化Boys
	ifstream stream;
	stream.open(BOYS_FILE);
	if(!stream.is_open()){//打开失败
	//最开始没有文件!//假设最开始没有文件,让用户输入基础用户数据
		cout << "===输入基础用户[男嘉宾]数据===\n";
		Boy::inputBoys(this->boys);
		saveBoys();//保存Boys信息到文件
		stream.close();
		return;
	}
	
	//文件打开成功
	//while (!stream.eof()) {//读取到eof结束符才结束,而不是位置指针指向结束符结束
	while (1) {
		string line="";
		char name[64] = "";
		int salary = 0;
		//string degree ;//使用string类型不能接收sscanf_s解析出的字符,后续的解析还会继续
		char degree[64] = "";
		int age = 0;
		getline(stream, line);//读到一行
		if (stream.eof()) { break; }//结束符读取到了,退出
		//解析读到的一行数据,
	//解析格式:ret << "性别:男\t\t姓名:"<<getname() << "\t\t薪资:" << salary << "\t\t学历:" << degree << "\t\t年龄:" <<getage() ;
		unsigned int ret=sscanf_s(line.c_str(),"性别:男   姓名:%s   薪资:%d   学历:%s  年龄:%d",
			name, sizeof(name), &salary,degree,sizeof(degree),&age);//空格可以匹配多个空白字符,ret变量是便于观察有没解析成功

		//sscanf_s的返回值,必须要unsigned int以上类型来进行接收,否则不能调用
		if (ret < 0) {cout << "男嘉宾数据库格式解析失败!\n"; exit(2);}
		 boys.push_back(Boy(name, salary, degree)); 
		//使用读到的单身男信息,构建一个Boy对象,并添加到boys中//boys.push_back(Boy(string(name),salary,degree));
	}
	stream.close();
}

void Database::initGirlsFromFile(){
	//打开文件,读文件内容,初始化Girls
	ifstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) {//打开失败
	//最开始没有文件!//假设最开始没有文件,让用户输入基础用户数据
		cout << "===输入基础用户[女嘉宾]数据===\n";
		Girl::inputGirls(this->girls);
		saveGirls();//保存Girls信息到文件
		stream.close();
		return;
	}

	//文件打开成功
	while (1) {
		string line = "";
		char name[64] = "";
		int faceScore = 0;
		int age = 0;
		getline(stream, line);//读到一行
		if (stream.eof()) { break; }//结束符读取到了,退出
		//解析读到的一行数据,
		//解析格式:ret <<"性别:女\t\t姓名:"<< getname() << setw(3) << setiosflags(ios::left) 
		//<<"\t\t年龄:" << getage()<< "\t\t颜值:" << faceScore <<"\t\t胸围:" << chest << "\n";
		//空格可以匹配多个空白字符,ret变量是便于观察有没解析成功
		unsigned int ret=sscanf_s(line.c_str(),"性别:女 姓名:%s 年龄:%d 颜值:%d",
			name,sizeof(name),&age,&faceScore);//胸没加
		if (ret <= 0) { cout << "女嘉宾数据库格式解析失败!\n"; exit(3); }else{ girls.push_back(Girl(name, age, faceScore)); }
	}
	stream.close();
}

void Database::addOne(Boy& boy)
{
	boys.push_back(boy);
	cout << "\n自动配对结果\n";
	string str(100, '-');//str字符串有100个字符'-'
	cout << str << endl;
	
		for (int j = 0; j < girls.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boy.satisfied(girls[j]) && girls[j].satisfied(boy)) {//判断双方是否满意
				cout << boy.basic_information() << endl;
				cout << girls[j].basic_information() << endl;//满意则打印出双方各自信息
				cout << str << endl;
			}
		}
}

void Database::addOne(Girl& girl)
{
	girls.push_back(girl);
	cout << "\n自动配对结果\n";
	string str(100, '-');//str字符串有100个字符'-'
	cout << str << endl;

	for (int j = 0; j < boys.size(); j++) {
		//cout << girls[j].getfaceScore() << endl;
		if (girl.satisfied(boys[j]) && boys[j].satisfied(girl)) {//判断双方是否满意
			cout << girl.basic_information() << endl;//满意则打印出双方各自信息
			cout << boys[j].basic_information() << endl;
			cout << str << endl;
		}
	}
}

void Database::autoBestMate()
{
	cout << "\n自动配对最佳伴侣\n";
	string str(100, '-');//str字符串有100个字符'-'
	cout << str << endl;

	//男士找最优女士
	cout << "---------------男士找最优女士-----------\n";
	for (int i = 0; i < boys.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		Girl* girlBest = NULL;
		for (int j = 0; j < girls.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//判断双方是否满意

				if (!girlBest) {
					girlBest = &girls[j];
				}else if (girls[j] > * girlBest) {
						girlBest = &girls[j];
				}
			}
		}
		//有些男士就悲催了,找不到老婆,连我这软件都嫌弃,不理会
		if(girlBest){//最优伴侣找到了就打印出来
		//cout << boys[i].basic_information() << endl;
			cout << boys[i] << endl;
		//cout << girlBest->basic_information() << endl;
			cout << *girlBest << endl;
		cout << str << endl;
		}
	}

	//女士找最优男士
	cout << "---------------女士找最优男士-----------\n";
	for (int i = 0; i < girls.size(); i++) {
		//cout << boys[i].getsalary() << endl;
		Boy* boyBest = NULL;
		for (int j = 0; j < boys.size(); j++) {
			//cout << girls[j].getfaceScore() << endl;
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {//判断双方是否满意

				if (!boyBest) {
					boyBest = &boys[j];
				}
				else if (boys[j] > * boyBest) {
					boyBest = &boys[j];
				}
			}
		}
		//有些女士就悲催了,找不到老公,连我这软件都嫌弃,不理会
		if (boyBest) {//最优伴侣找到了就打印出来
		//cout << boys[i].basic_information() << endl;
			cout << girls[i] << endl;
			//cout << girlBest->basic_information() << endl;
			cout << *boyBest << endl;
			cout << str << endl;
		}
	}

}

void Database::saveBoys(){//把boys单身男的信息写入文件
	ofstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {cout << "saveBoys()写入文件失败\n"; exit(1);}

	for (int i = 0; i < boys.size(); i++) {
		stream << boys[i].basic_information()<<endl;//把单身男的基础信息塞进stream中
	}
	stream.close();
}

void Database::saveGirls(){//把Girls单身女的信息写入文件
	ofstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) { cout << "saveGirls()写入文件失败\n"; exit(1); }

	for (int i = 0; i < girls.size(); i++) {
		stream << girls[i].basic_information() << endl;//把单身女的基础信息塞进stream中
	}
	stream.close();
}
