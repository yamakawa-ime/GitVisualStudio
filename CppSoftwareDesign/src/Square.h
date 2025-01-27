#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Point.h"
#include "Shape.h"

class Square : public Shape
{
public:
	explicit Square(double side) : side_(side) { }

	void accept(const ShapeVisitor& v) override;

	double side() const { return side_; }
	Point center() const { return center_; }

private:
	double side_;
	Point center_{};
};

#endif
