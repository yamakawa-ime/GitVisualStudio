#pragma once

#include <utility>

template<typename T, typename Tag>
struct StrongType
{
public:
	using value_type = T;
	explicit StrongType(const T& value) : value_{ value } {}

	T& get() { return value_; }
	const T& get() const { return value_; }
	
private:
	T value_;
};

template<typename T, typename Tag>
StrongType<T, Tag> operator+(const StrongType<T, Tag>& a, const StrongType<T, Tag>& b)
{
	return StrongType<T, Tag>(a.get() + b.get());
}
