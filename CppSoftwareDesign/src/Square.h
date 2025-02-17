#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Point.h"

class Square
{
public:

	explicit Square(double side) 
		: side_(side) { }

	double side() const { return side_; }
	Point center() const { return center_; }


private:
	double side_;
	Point center_{};
};

bool operator==(Square const& lhs, Square const& rhs)
{
	return lhs.side() == rhs.side();
}

#endif
