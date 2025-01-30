#pragma once

#include "DrawStrategy.h"
#include "Square.h"
#include <iostream>

class OpenGLSquareStrategy : public DrawStrategy<Square>
{
public:
	virtual void draw(const Square& s) const override
	{
		std::cout << "OpenGL Square" << std::endl;
	}
};
