#pragma once
class Circle;
class Square;

class DrawStrategy
{
public:
	virtual ~DrawStrategy() = default;

	virtual void draw(const Circle&) const = 0;
	virtual void draw(const Square&) const = 0;
};