#pragma once
#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
public:
	explicit Circle(double radius) : Shape(circle), radius_(radius) 
	{
		// radius�̒l�`�F�b�N
	}

	double radius() const { return radius_; }
	Point center() const { return center_; }

private:
	double radius_;
	Point center_{};
};
