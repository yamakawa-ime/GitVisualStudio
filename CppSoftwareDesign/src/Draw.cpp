#include "Draw.h"

void Draw::visit(const Circle& c) const
{
	std::cout << "Circle draw" << std::endl;
}

void Draw::visit(const Square& s) const
{
	std::cout << "Square draw" << std::endl;
}
