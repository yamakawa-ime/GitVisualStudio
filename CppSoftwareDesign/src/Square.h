#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Point.h"
#include "Shape.h"
#include "DrawStrategy.h"
#include <memory>
#include <utility>

class Square : public Shape
{
public:
	explicit Square(double side, std::unique_ptr<DrawStrategy<Square>> drawer) 
		: side_(side), drawer_(std::move(drawer)) { }

	double side() const { return side_; }
	Point center() const { return center_; }

	void draw() const override
	{
		drawer_->draw(*this);
	}

private:
	double side_;
	Point center_{};
	std::unique_ptr<DrawStrategy<Square>> drawer_;
};

#endif
