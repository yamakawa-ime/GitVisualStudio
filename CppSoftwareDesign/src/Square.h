#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Point.h"
#include "Shape.h"
#include <memory>
#include <utility>
#include <functional>

class Square : public Shape
{
public:
	using DrawStrategy = std::function<void(const Square&)>;

	explicit Square(double side, DrawStrategy drawer) 
		: side_(side), drawer_(std::move(drawer)) { }

	double side() const { return side_; }
	Point center() const { return center_; }

	void draw() const override
	{
		drawer_(*this);
	}

private:
	double side_;
	Point center_{};
	DrawStrategy drawer_;
};

#endif
