#pragma once

template<typename T>
class DrawStrategy
{
public:
	virtual ~DrawStrategy() = default;

	virtual void draw(const T&) const = 0;
};