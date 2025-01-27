#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.h"

class Circle : public Shape
{
public:
	explicit Circle(double radius) : radius_(radius) 
	{
		// radiusの値チェック
	}

	void accept(const ShapeVisitor& v) override;

	double radius() const { return radius_; }

private:
	double radius_;
};
#endif
