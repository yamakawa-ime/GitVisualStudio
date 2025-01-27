#include "Circle.h"

#include <iostream>

#include "ShapeVisitor.h"

void Circle::accept(const ShapeVisitor& v)
{
	v.visit(*this);
}
