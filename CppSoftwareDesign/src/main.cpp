#include "Calculator.h"
#include "Add.h"
#include "Subtract.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Circle.h"
#include "OpenGLCircleStrategy.h"
#include "OpenGLSquareStrategy.h"
#include "Square.h"

using namespace std;

int main()
{
	Calculator calculator{};

	Add addCommand{ 3 };
	calculator.compute(std::make_tuple(addCommand.execute, addCommand.undo));
	calculator.compute(std::make_tuple(Add{ 7 }.execute, Add{ 7 }.undo));
	calculator.compute(std::make_tuple(Subtract{ 4 }.execute, Subtract{ 4 }.undo));
	calculator.compute(std::make_tuple(Subtract{ 2 }.execute, Subtract{ 2 }.undo));

	cout << calculator.result() << endl;

	calculator.undoLast();

	cout << calculator.result() << endl;

	cout << "--end--" << endl;

	using Shapes = std::vector<std::unique_ptr<Shape>>;
	Shapes shapes{};

	shapes.emplace_back(std::make_unique<Circle>(1.0, OpenGLCircleStrategy{}));
	shapes.emplace_back(std::make_unique<Square>(2.0, OpenGLSquareStrategy{}));
	shapes.emplace_back(std::make_unique<Circle>(3.0, OpenGLCircleStrategy{}));
	shapes.emplace_back(std::make_unique<Square>(4.0, [&](const Square& s) { cout << "aaa" << endl; }));

	for (const auto& shape : shapes)
	{
		shape->draw();
	}

	cout << "--end--" << endl;
}

