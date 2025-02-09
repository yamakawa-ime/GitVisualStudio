#pragma once

#include <stack>
#include <memory>
#include <functional>
#include <tuple>
#include "CalculatorCommand.h"

class Calculator
{
public:

	void compute(Command command)
	{
		current_ = command.execute(current_);
		stack_.push(std::move(command));
	}

	void undoLast()
	{
		if (stack_.empty())return;

		auto command = std::move(stack_.top());
		stack_.pop();

		current_ = command.undo(current_);
	}

	int result() const { return current_; }

	void clear()
	{
		current_ = 0;
		CommandStack{}.swap(stack_);
	}
private:
	using CommandStack = std::stack<Command>;

	int current_{};
	CommandStack stack_;

};