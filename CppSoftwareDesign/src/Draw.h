#ifndef __DRAW_H__
#define __DRAW_H__

#include "Shape.h"
#include <iostream>

class Draw
{
public:
	void operator()(const Circle& c) const
	{
		std::cout << "Circle variant" << std::endl;
	}
	void operator()(const Square& s) const
	{
		std::cout << "Square variant" << std::endl;
	}
};

#endif // !__DRAW_H__


