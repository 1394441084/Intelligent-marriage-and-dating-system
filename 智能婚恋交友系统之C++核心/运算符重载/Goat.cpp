#include "Goat.h"

Goat::Goat(int weight)
{
	this->weight = weight;
}

int Goat::getweight()const
{
	return weight;
}

bool Goat::operator>(Goat& goat)
{
	if (weight > goat.weight) { return true; }else{ return false; }
}

bool Goat::operator<(Goat& goat)
{
	if (weight < goat.weight) { return true; }
	else { return false; }
}

bool Goat::operator==(Goat& goat)
{
	if (weight == goat.weight) { return true; }
	else { return false; }
}
