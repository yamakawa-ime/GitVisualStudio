#pragma once

#include "Observer.h"
#include "Person.h"
#include <iostream>

class NameObserver : public Observer<Person, Person::StateChange>
{
public:
	void update(const Person& person, Person::StateChange property) override
	{
		if (property == Person::forenameChanged || property == Person::surnameChanged)
		{
			std::cout << "NameObserver update" << std::endl;
		}
	}
};