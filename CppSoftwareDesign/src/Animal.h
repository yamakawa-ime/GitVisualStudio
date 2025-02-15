#pragma once

class Animal
{
public:
	virtual ~Animal() = default;
	virtual void makeSound() const = 0;
	virtual std::unique_ptr<Animal> clone() const = 0;
};
