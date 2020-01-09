#include "Speaker.h"
//聚合,不负责创建和销毁
#include <iostream>


Speaker::Speaker() {
	std::cout << "speaker创建了\n";
}
Speaker::~Speaker() {
	std::cout << "speaker销毁了\n";
}