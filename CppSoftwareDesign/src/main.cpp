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
#include "MallardDuck.h"
#include "WildTurkey.h"
#include "TurkeyAdapter.h"

using namespace std;

int main()
{
	Calculator calculator{};

	calculator.compute(AddCommand{}(3));
	calculator.compute(AddCommand{}(7));
	calculator.compute(SubtractCommand(4)());
	calculator.compute(SubtractCommand(2)());

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
	
	using DuckChoir = std::vector<std::unique_ptr<Duck>>;

	DuckChoir duck_choir{};

	duck_choir.push_back(std::make_unique<MallardDuck>());

	auto turkey = std::make_unique<WildTurkey>();
	auto turkey_in_disguise = std::make_unique<TurkeyAdapter>(std::move(turkey));
	duck_choir.push_back(std::move(turkey_in_disguise));

	duck_choir.push_back(std::make_unique<TurkeyAdapter>(std::make_unique<WildTurkey>()));

	for (const auto& duck : duck_choir)
	{
		duck->quack();
	}



	cout << "--end--" << endl;
}

