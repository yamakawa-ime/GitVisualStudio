#pragma once

#include <functional>
#include "CalculatorCommand.h"

class Add
{
public:
	explicit Add(int operand) : operand_{ operand } {}

	std::function<int(int)> execute = [this](int i) { return i + operand_; };
	std::function<int(int)> undo = [this](int i) { return i - operand_; };

private:
	int operand_{};
};

class AddCommand
{
public:
	explicit AddCommand() {}

	Command operator()(int operand) const
	{
		return Command{
			[&](int x) { return x + operand; },
			[&](int x) { return x - operand; }
		};
	}

};
