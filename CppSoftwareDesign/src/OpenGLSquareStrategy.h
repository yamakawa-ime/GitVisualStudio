#pragma once

#include "Square.h"
#include <iostream>

class OpenGLSquareStrategy 
{
public:
	explicit OpenGLSquareStrategy() = default;

	void operator()(const Square& square) const
	{
		std::cout << "OpenGLSquareStrategy: draw square with side " << square.side() << std::endl;
	}
};
