#pragma once
#include "DrawStrategy.h"
#include "Circle.h"
#include <iostream>

class OpenGLCircleStrategy : public DrawStrategy<Circle>
{
public:
	virtual void draw(const Circle& c) const override
	{
		std::cout << "openGL Circle " << std::endl;
	}

};