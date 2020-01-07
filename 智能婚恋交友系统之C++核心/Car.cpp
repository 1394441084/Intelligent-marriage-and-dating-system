#include "Car.h"

Car::Car():engine("发动机品牌", 2.22),
tires{ brand ,brand ,brand ,brand }
{
	brand = "品牌";
	model = "型号";
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
		return *this;//为了防止f1=f1;防止对象给自己赋值
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
	
	//返回对象本身的引用,为了方便能链式处理如:f1=f2=f3.
	return *this;//必须返回.为防止f1=f2=f3;这种情况,突然返回空的情况
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

	str << "Car品牌:" << brand << "_Car型号:" << model << "_Car价格:" << 
		price << "_Car行驶里程:"<< drivingMileage <<endl
		<< engine.description() << tires->description();
		
	return str.str();
}
