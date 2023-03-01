#pragma once

#include "Products.h"
#include <string>

/*Factory method is a class member that acts as a way of creating object. It typically replaces a Constructor*/

class Creator
{
public:
	virtual CarProduct *createCar() = 0; // Factory Method

	std::string someOperation() 
	{
		CarProduct* product = this->createCar();
		
		std::string result = "Product: " + product->operation();

		delete product;
		product = nullptr;

		return result;
	}
};

class FerrariCreator : public Creator
{
	virtual CarProduct *createCar() override
	{
		return new FerrariProduct();
	}
};

class SuzukiCreator : public Creator
{
	virtual CarProduct* createCar() override
	{
		return new SuzukiProduct();
	}
};

