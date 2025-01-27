#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
	explicit Circle(double radius) : radius_(radius) 
	{
		// radius�̒l�`�F�b�N
	}

	void accept(const ShapeVisitor& v) override;

	double radius() const { return radius_; }
	Point center() const { return center_; }

private:
	double radius_;
	Point center_{};
};
#endif
