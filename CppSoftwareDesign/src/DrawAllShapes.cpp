#include "DrawAllShapes.h"
#include "Circle.h"
#include "Square.h"

void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes)
{
	for (const auto& shape : shapes)
	{
		shape->draw();
	}
}
