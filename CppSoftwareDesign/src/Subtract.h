#pragma once

#include <functional>
#include "CalculatorCommand.h"

class Subtract 
{
public:
	explicit Subtract(int operand) : operand_{ operand } {}

	std::function<int(int)> execute = [this](int i) { return i - operand_; };
	std::function<int(int)> undo = [this](int i) { return i + operand_; };

private:
	int operand_{};
};

class SubtractCommand
{
public:
	explicit SubtractCommand(int operand) : operand_{ operand } {}
	Command operator()() const
	{
		return Command{
			[this](int x) { return x - operand_; },
			[this](int x) { return x + operand_; }
		};
	}
private:
	int operand_{};
};
