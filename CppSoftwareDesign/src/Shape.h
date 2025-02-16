#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <functional>
#include <stdexcept>
#include <utility>

class ShapeConcept
{
public:
	virtual ~ShapeConcept() = default;

	virtual void draw() const = 0;
};

template<typename ShapeT, typename DrawStrategy>
class ShapeModel : public ShapeConcept
{
public:

	explicit ShapeModel(ShapeT shape, DrawStrategy drawer)
		: shape_(std::move(shape)), drawer_(std::move(drawer))
	{

	}

	void draw() const override { drawer_(shape_); }

private:
	ShapeT shape_;
	DrawStrategy drawer_;

};


#endif // !__SHAPE_H__


