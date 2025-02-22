#include "Calculator.h"
#include "Add.h"
#include "Subtract.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Circle.h"
#include "Shape.h"
#include "OpenGLCircleStrategy.h"
#include "OpenGLSquareStrategy.h"
#include "OpenGLDrawStrategy.h"
#include "Square.h"
#include "MallardDuck.h"
#include "WildTurkey.h"
#include "TurkeyAdapter.h"
#include "AddressObserver.h"
#include "NameObserver.h"
#include "Person.h"
#include "Distance.h"
#include "Sheep.h"
#include <any>


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

	Circle circle{ 3.14 };
	auto drawer = [](const Circle& c) {std::cout << "derawer" << std::endl; };
	Shape shape1(circle, drawer);
	draw(shape1);

	Shape shape2(shape1);
	draw(shape2);


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

	NameObserver nameObserver;
	AddressObserver addressObserver;

	Person takuya{ "yamakawa", "takuya" };

	takuya.attach(&nameObserver);
	takuya.attach(&addressObserver);

	takuya.forename("aaaaaaaa");
	takuya.address("afffffffff");
	takuya.forename("aaaaaaaaaa");


	cout << "--end--" << endl;

	const auto m1 = Meter<long>{ 120L };
	const auto m2 = Meter<long>{ 122L };
	const auto km = Kilometer<long>{ 30L };

	auto m3 = m1 + m2;

	cout << m3.get() << endl;

	cout << "--end--" << endl;

	const std::unique_ptr<Animal> dolly = std::make_unique<Sheep>("Dolly");
	auto dollyClone = dolly->clone();

	dolly->makeSound();
	dollyClone->makeSound();


	cout << "--end--" << endl;






	cout << "--end--" << endl;


}

