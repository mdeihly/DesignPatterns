
#include "Creators.h"

int main()
{
	auto suzuki = new SuzukiCreator();
	std::cout << suzuki->someOperation();

	std::cout << std::endl;

	auto ferrari = new FerrariCreator();
	std::cout << ferrari->someOperation();

	delete suzuki;
	suzuki = nullptr;
	delete ferrari;
	ferrari = nullptr;

	return 0;
}