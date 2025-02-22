#pragma once

#include "DecoratedItem.h"

class Discounted : public DecolatedItem
{
public:
	Discounted(double discount, std::unique_ptr<Item> item)
		: DecolatedItem(std::move(item)), factor_(1.0 - discount)
	{
		if (!std::_Is_finite(discount) || discount < 0.0 || discount > 1.0)
		{
			throw std::invalid_argument("Invalid discounted");
		}
	}

	Money price() const override
	{
		return item().price() * factor_;
	}

private:
	double factor_;
};