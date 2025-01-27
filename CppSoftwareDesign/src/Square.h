#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Shape.h"
class ShapeVisitor;

class Square : public Shape
{
public:
	explicit Square(double side) : side_(side) { }

	void accept(const ShapeVisitor& v) override;

	double side() const { return side_; }

private:
	double side_;

};

#endif
