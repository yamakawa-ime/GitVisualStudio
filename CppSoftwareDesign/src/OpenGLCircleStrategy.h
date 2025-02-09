#pragma once
#include "Circle.h"
#include <iostream>

class OpenGLCircleStrategy 
{
public:
	explicit OpenGLCircleStrategy() = default;

	void operator()(const Circle& circle) const
	{
		std::cout << "OpenGLCircleStrategy: draw circle with radius " << circle.radius() << std::endl;
	}	

};