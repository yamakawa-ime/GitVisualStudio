#pragma once

#include "Animal.h"
#include <string>
#include <iostream>

class Sheep : public Animal
{
public:
	explicit Sheep(std::string name) : name_{ std::move(name) } {}

	void makeSound() const override
	{
		std::cout << "baa\n";
	}

	std::unique_ptr<Animal> clone() const override
	{
		return std::make_unique<Sheep>(*this);
	}

private:
	std::string name_;
};