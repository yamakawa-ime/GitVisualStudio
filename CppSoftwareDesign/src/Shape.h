#ifndef __SHAPE_H__
#define __SHAPE_H__

class ShapeVisitor;

class Shape
{
protected:
	Shape() = default;

public:
	virtual ~Shape() = default;
	virtual void accept(const ShapeVisitor& v) = 0;
};

#endif // !__SHAPE_H__


