#include "DrawAllShapes.h"
#include "Circle.h"
#include "Square.h"
#include "DrawCircle.h"
#include "DrawSquare.h"

void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes)
{
	for (const auto& shape : shapes)
	{
		switch (shape->getType())
		{
		case circle:
			draw(static_cast<const Circle&>(*shape));
			break;
		case square:
			draw(static_cast<const Square&>(*shape));
			break;
		case triangle:
			//draw(static_cast<const Triangle&>(*shape));
			break;
		}
	}
}
