#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"
#include "Shape.h"
#include "DrawStrategy.h"
#include <memory>
#include <utility>

class Circle : public Shape
{
public:
	explicit Circle(double radius, std::unique_ptr<DrawStrategy> drawer) 
		: radius_(radius), drawer_(std::move(drawer))
	{
		// radiusの値チェック
	}

	double radius() const { return radius_; }
	Point center() const { return center_; }

	void draw() const override
	{
		drawer_->draw(*this);
	}

private:
	double radius_;
	Point center_{};
	std::unique_ptr<DrawStrategy> drawer_;
};
#endif
