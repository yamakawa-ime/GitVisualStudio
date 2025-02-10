#pragma once

#include "Observer.h"
#include <string>
#include <set>

class Person
{
public:
	enum StateChange
	{
		forenameChanged,
		surnameChanged,
		addressChanged
	};

	using PersonObserver = Observer<Person, StateChange>;

	explicit Person(std::string forename, std::string surname)
		: forename_{ std::move(forename) }, surname_{ std::move(surname) }
	{
	}

	bool attach(PersonObserver* observer)
	{
		auto [pos, success] = observers_.insert(observer);
		return success;
	}
	bool detach(PersonObserver* observer)
	{
		return (observers_.erase(observer) > 0U);
	}
	void notify(StateChange property)
	{
		for (auto iter = begin(observers_); iter != end(observers_);)
		{
			const auto pos = iter++;
			(*pos)->update(*this, property);
		}
	}

	void forename(std::string newForename)
	{
		forename_ = std::move(newForename);
		notify(forenameChanged);
	}
	void surname(std::string newSurname)
	{
		surname_ = std::move(newSurname);
		notify(surnameChanged);
	}
	void address(std::string newAddress)
	{
		address_ = std::move(newAddress);
		notify(addressChanged);
	}

	const std::string& forename() const { return forename_; }
	const std::string& surname() const { return surname_; }
	const std::string& address() const { return address_; }
private:
	std::string forename_;
	std::string surname_;
	std::string address_;

	std::set<PersonObserver*> observers_;
	
};
