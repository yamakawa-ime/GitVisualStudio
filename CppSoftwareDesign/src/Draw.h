#ifndef __DRAW_H__
#define __DRAW_H__

#include "ShapeVisitor.h"
#include <iostream>

class Draw : public ShapeVisitor
{
public:
	void visit(const Circle& c) const override;
	void visit(const Square& s) const override;
};

#endif // !__DRAW_H__


