#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <functional>
#include <stdexcept>
#include <utility>
#include <memory>

namespace detail
{
	class ShapeConcept
	{
	public:
		virtual ~ShapeConcept() = default;
		virtual void draw() const = 0;
		virtual std::unique_ptr<ShapeConcept> clone() const = 0;
		virtual bool isEqual(const ShapeConcept* c) const = 0;
	};

	template<typename ShapeT, typename DrawStrategy>
	class OwingShapeModel : public ShapeConcept
	{
	public:

		explicit OwingShapeModel(ShapeT shape, DrawStrategy drawer)
			: shape_(std::move(shape)), drawer_(std::move(drawer))
		{

		}

		void draw() const override { drawer_(shape_); }

		std::unique_ptr<ShapeConcept> clone() const override
		{
			return std::make_unique<OwingShapeModel>(*this);
		}

		bool isEqual(const ShapeConcept* c) const override
		{
			using Model = OwingShapeModel<ShapeT, DrawStrategy>;
			auto const* model = dynamic_cast<Model const*>(c);
			return (model && shape_ == model->shape_);
		}

	private:
		ShapeT shape_;
		DrawStrategy drawer_;

	};
}

class Shape
{
public:
	template<typename ShapeT, typename DrawStrategy>
	Shape(ShapeT shape, DrawStrategy drawer)
	{
		using Model = detail::OwingShapeModel<ShapeT, DrawStrategy>;
		pimpl_ = std::make_unique<Model>(std::move(shape), std::move(drawer));
	}

	Shape(const Shape& other) : pimpl_(other.pimpl_->clone()) {}

	Shape& operator=(const Shape& other)
	{
		Shape copy(other);
		pimpl_.swap(copy.pimpl_);
		return *this;
	}

	~Shape() = default;
	Shape(Shape&&) = default;
	Shape& operator=(Shape&&) = default;

private:
	std::unique_ptr<detail::ShapeConcept> pimpl_;

	friend void draw(const Shape& shape)
	{
		shape.pimpl_->draw();
	}

	friend bool operator==(Shape const& lhs, Shape const& rhs)
	{
		return lhs.pimpl_->isEqual(rhs.pimpl_.get());
	}

	friend bool operator!=(Shape const& lhs, Shape const& rhs)
	{
		return !(lhs == rhs);
	}

};




#endif // !__SHAPE_H__


