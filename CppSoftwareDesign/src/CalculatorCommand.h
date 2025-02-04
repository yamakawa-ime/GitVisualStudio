#pragma once

class CalculatorCommand
{
public:
	virtual ~CalculatorCommand() = default;

	virtual int execute(int i) const = 0;
	virtual int undo(int i) const = 0;
};
