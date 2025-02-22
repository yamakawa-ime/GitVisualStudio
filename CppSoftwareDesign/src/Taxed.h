#pragma once

#include "DecoratedItem.h"

class Taxed : public DecolatedItem
{
public:
	Taxed(double taxRate, std::unique_ptr<Item> item)
		: DecolatedItem(std::move(item)), factor_(1.0 * taxRate)
	{
	}

	Money price() const override
	{
		return item().price() * factor_;
	}
private:
	double factor_;
};