#pragma once

#include "Turkey.h"
#include <iostream>

class WildTurkey : public Turkey
{
public:
	void gobble() override
	{
		std::cout << "WildTurkey gobble" << std::endl;
	}

	void fly() override
	{
		std::cout << "WildTurkey fly" << std::endl;
	}
};