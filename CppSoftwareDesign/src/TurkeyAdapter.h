#pragma once

#include "Duck.h"
#include "Turkey.h"
#include <memory>


class TurkeyAdapter : public Duck
{
public:
	explicit TurkeyAdapter(std::unique_ptr<Turkey> turkey)
		: turkey_{std::move(turkey)}
	{

	}

	void quack() override
	{
		turkey_->gobble();
	}

	void fly() override
	{
		turkey_->fly();
	}


private:
	std::unique_ptr<Turkey> turkey_;
};