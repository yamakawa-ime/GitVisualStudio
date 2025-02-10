#pragma once

#include "Duck.h"
#include <iostream>

class MallardDuck : public Duck
{
public:
	void quack() override 
	{
		std::cout << "Mallard quack" << std::endl;
	}

	void fly() override
	{
		std::cout << "Mallard fly" << std::endl;
	}
};