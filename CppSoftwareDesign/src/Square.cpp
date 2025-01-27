#include "Square.h"

#include <iostream>

#include "ShapeVisitor.h"

void Square::accept(const ShapeVisitor& v)
{
	v.visit(*this);
}
