#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <variant>
#include "Circle.h"
#include "Square.h"

using Shape = std::variant<Circle, Square>;


#endif // !__SHAPE_H__


