#include <iostream>
#include <vector>
#include "Circle.h"
#include "Square.h"
#include "OpenGLCircleStrategy.h"
#include "OpenGLSquareStrategy.h"

using namespace std;

int main()
{
	using Shapes = std::vector<std::unique_ptr<Shape>>;

	Shapes shapes{};
	shapes.emplace_back(std::make_unique<Circle>(2.3, std::make_unique<OpenGLCircleStrategy>()));
	shapes.emplace_back(std::make_unique<Circle>(2.3, std::make_unique<OpenGLCircleStrategy>()));
	shapes.emplace_back(std::make_unique<Square>(2.3, std::make_unique<OpenGLSquareStrategy>()));

	for (const auto& shape : shapes)
	{
		shape->draw();
	}


	cout << "--end--" << endl;
}

