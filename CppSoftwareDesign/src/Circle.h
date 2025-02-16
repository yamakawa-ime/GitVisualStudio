#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"

class Circle 
{
public:
	explicit Circle(double radius) 
		: radius_(radius)
	{
		// radiusの値チェック
	}

	double radius() const { return radius_; }
	Point center() const { return center_; }


private:
	double radius_;
	Point center_{};
};
#endif
