#include "ComputerService.h"
#include "Computer.h"

void ComputerService::upgrade1(Computer* computer)
{
	computer->cpu = "i9";
}

void ComputerService::clean(Computer* computer)
{
	cout << "正在对[cpu:" << computer->cpu << "]清理.\n";
}

void ComputerService::kill(Computer* computer)
{
	cout << "正在对[cpu:" << computer->cpu << "]杀毒.\n";
}
