#pragma once

#include <stack>
#include <memory>
#include <functional>
#include <tuple>

class Calculator
{
public:
	using ExecuteCommand = std::function<int(int)>;
	using UndoCommand = std::function<int(int)>;
	using CalculatorCommand = std::tuple<ExecuteCommand, UndoCommand>;


	void compute(CalculatorCommand command)
	{
		current_ = std::get<0>(command)(current_);
		stack_.push(std::move(command));
	}

	void undoLast()
	{
		if (stack_.empty())return;

		auto command = std::move(stack_.top());
		stack_.pop();

		current_ = std::get<1>(command)(current_);
	}

	int result() const { return current_; }

	void clear()
	{
		current_ = 0;
		CommandStack{}.swap(stack_);
	}
private:
	using CommandStack = std::stack<CalculatorCommand>;

	int current_{};
	CommandStack stack_;

};