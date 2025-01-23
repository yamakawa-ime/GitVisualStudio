#pragma once
class Shape
{
protected:
	Shape() = default;

public:
	virtual ~Shape() = default;
	
	virtual void draw() const = 0;
};