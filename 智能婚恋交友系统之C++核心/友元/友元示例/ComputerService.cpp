#include "ComputerService.h"
#include "Computer.h"

void ComputerService::upgrade1(Computer* computer)
{
	computer->cpu = "i9";
}

void ComputerService::clean(Computer* computer)
{
	cout << "���ڶ�[cpu:" << computer->cpu << "]����.\n";
}

void ComputerService::kill(Computer* computer)
{
	cout << "���ڶ�[cpu:" << computer->cpu << "]ɱ��.\n";
}
