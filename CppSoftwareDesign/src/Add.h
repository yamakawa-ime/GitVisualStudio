#pragma once

#include "CalculatorCommand.h"

class Add : public CalculatorCommand
{
public:
	explicit Add(int operand) : operand_{ operand } {}

	int execute(int i) const override
	{
		return i + operand_;
	}

	int undo(int i) const override
	{
		return i - operand_;
	}

private:
	int operand_{};
};
