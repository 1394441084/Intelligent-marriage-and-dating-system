#include "Car.h"

Car::Car():engine("������Ʒ��", 2.22),
tires{ brand ,brand ,brand ,brand }
{
	brand = "Ʒ��";
	model = "�ͺ�";
	price = 0;
	drivingMileage = 0;
}

Car::Car(const string& carBrand, const string& carModel, int carPrice, 
	const string& engineBrand, float engineModel,
	const string& tiresBrand)
	:engine(engineBrand, engineModel),
	tires{ tiresBrand ,tiresBrand ,tiresBrand ,tiresBrand }
{
	brand = carBrand;
	model = carModel;
	price = carPrice;
	drivingMileage = 0;
}



Car& Car::operator=(const Car& other)
{
	if (this == &other) {
		return *this;//Ϊ�˷�ֹf1=f1;��ֹ������Լ���ֵ
	}
	else {
		brand = other.brand;
		model = other.model;
		price = other.price;
		drivingMileage = other.drivingMileage;
		engine = other.engine;
		for(int i=0;i<4;i++){
		tires[i] = other.tires[i];
		}
	}
	
	//���ض����������,Ϊ�˷�������ʽ������:f1=f2=f3.
	return *this;//���뷵��.Ϊ��ֹf1=f2=f3;�������,ͻȻ���ؿյ����
}

Car::~Car()
{
	cout << "~Car\n";
}

Engine Car::getEngine() const
{
	return engine;
}

const Tires* Car::getTires(int n) const
{
	if (0 <= n&& n <= 3) {
		return &tires[n];
	}
	else {
		return NULL;
	}
}

string Car::getBrand() const
{
	return brand;
}

string Car::getModel() const
{
	return model;
}

int Car::getPrice() const
{
	return price;
}

int Car::getDrivingMileage() const
{
	return drivingMileage;
}

string Car::description() const
{
	stringstream str;

	str << "CarƷ��:" << brand << "_Car�ͺ�:" << model << "_Car�۸�:" << 
		price << "_Car��ʻ���:"<< drivingMileage <<endl
		<< engine.description() << tires->description();
		
	return str.str();
}
