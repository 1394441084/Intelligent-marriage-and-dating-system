#pragma once
class Goat //����
{
public:
	Goat(int weight = 0);

	int getweight()const;
	//��ϵ���������
	bool operator>(Goat& goat);
	bool operator<(Goat& goat);
	bool operator==(Goat& goat);

private:
	int weight = 0;//����

};

