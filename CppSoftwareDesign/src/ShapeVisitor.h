#ifndef __SHAPEVISITOR_H__
#define __SHAPEVISITOR_H__

class Circle;
class Square;

class ShapeVisitor
{
public:
	virtual ~ShapeVisitor() = default;

	virtual void visit(const Circle& c) const = 0;
	virtual void visit(const Square& s) const = 0;
};

#endif // !__SHAPEVISITOR_H__


