#pragma once

#include "Money.h"

class Item
{
public:
	virtual ~Item() = default;

	virtual Money price() const = 0;

protected:
	double taxRate_;
};