#pragma once

#include "CalculatorCommand.h"
#include <stack>
#include <memory>

class Calculator
{
public:
	void compute(std::unique_ptr<CalculatorCommand> command)
	{
		current_ = command->execute(current_);
		stack_.push(std::move(command));
	}

	void undoLast()
	{
		if (stack_.empty())return;

		auto command = std::move(stack_.top());
		stack_.pop();

		current_ = command->undo(current_);
	}

	int result() const { return current_; }

	void clear()
	{
		current_ = 0;
		CommandStack{}.swap(stack_);
	}
private:
	using CommandStack = std::stack<std::unique_ptr<CalculatorCommand>>;

	int current_{};
	CommandStack stack_;

};