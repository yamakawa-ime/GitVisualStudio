#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"
#include "Shape.h"
#include <memory>
#include <utility>
#include <functional>

class Circle : public Shape
{
public:
	using DrawStrategy = std::function<void(const Circle&)>;

	explicit Circle(double radius,  DrawStrategy drawer) 
		: radius_(radius), drawer_(std::move(drawer))
	{
		// radiusの値チェック
	}

	double radius() const { return radius_; }
	Point center() const { return center_; }

	void draw() const override
	{
		drawer_(*this);
	}

private:
	double radius_;
	Point center_{};
	DrawStrategy drawer_;
};
#endif
