#pragma once

#include <functional>

class CalculatorCommand
{
public:
	virtual ~CalculatorCommand() = default;

	virtual int execute(int i) const = 0;
	virtual int undo(int i) const = 0;
};

struct Command
{
	std::function<int(int)> execute;
	std::function<int(int)> undo;
};
