#include "DrawAllShapes.h"

#include "Draw.h"
#include "Shape.h"

void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes)
{
	for (const auto& shape : shapes)
	{
		shape->accept(Draw{});
	}
}
