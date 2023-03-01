#pragma once

#include <iostream>
#include <string>

class CarProduct
{
public:
	virtual void createCar() = 0;
	virtual std::string operation() const = 0;
};

class FerrariProduct : public CarProduct
{
public:
	virtual void createCar() override
	{
		std::cout << "Ferrari Car Product is created.." << std::endl;
	}

	std::string operation() const override
	{
		return std::string("Ferrrari Product Operation..");
	}
};

class SuzukiProduct : public CarProduct
{
public:
	virtual void createCar() override
	{
		std::cout << "Suzuki Car Product is created.." << std::endl;
	}

	std::string operation() const override
	{
		return std::string("Suzuki Product Operation..");
	}

};
