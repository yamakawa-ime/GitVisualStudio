#pragma once

#include "Observer.h"
#include "Person.h"
#include <iostream>

class AddressObserver : public Observer<Person, Person::StateChange>
{
public:
	void update(const Person& person, Person::StateChange property) override
	{
		if (property == Person::addressChanged)
		{
			std::cout << "AddressObserver" << std::endl;
		}
	}
};