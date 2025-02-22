#pragma once

#include "Item.h"
#include "Money.h"
#include <stdexcept>
#include <utility>
#include <memory>

class DecolatedItem : public Item
{
public:
	explicit DecolatedItem(std::unique_ptr<Item> item)
		: item_(std::move(item))
	{
		if (!item_)
		{
			throw std::invalid_argument("invalid item");
		}
	}

protected:
	Item& item() { return *item_; }
	const Item& item() const { return *item_; }

private:
	std::unique_ptr<Item> item_;
};
