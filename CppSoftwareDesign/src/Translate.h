#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__
#include "ShapeVisitor.h"
#include <iostream>

class Translate : public ShapeVisitor
{
public:
	void visit(const Circle& c) const override
	{
		std::cout << "Circle translate" << std::endl;
	}
	void visit(const Square& s) const override
	{
		std::cout << "Square Translate" << std::endl;
	}
};

#endif // !__TRANSLATE_H__

