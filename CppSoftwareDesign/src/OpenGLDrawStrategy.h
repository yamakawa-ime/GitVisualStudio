#pragma once

#include "Circle.h"
#include "Square.h"
#include <iostream>

class OpenGLDrawStragegy
{
public:
	explicit OpenGLDrawStragegy() {}

	void operator()(const Circle&) const
	{
		std::cout << "OpenGLDraw:Circle" << std::endl;
	}

	void operator()(const Square&) const
	{
		std::cout << "OpenGLDraw:Square" << std::endl;
	}
};