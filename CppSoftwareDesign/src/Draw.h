#ifndef __DRAW_H__
#define __DRAW_H__

#include "ShapeVisitor.h"
#include <iostream>

class Draw : public ShapeVisitor
{
public:
	void visit(const Circle& c) const override
	{
		std::cout << "Circle draw visitor" << std::endl;
	}
	void visit(const Square& s) const override
	{
		std::cout << "Square draw visitor" << std::endl;
	}
};

#endif // !__DRAW_H__


