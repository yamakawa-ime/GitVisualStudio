#ifndef __DRAWALLSHAPES_H__
#define __DRAWALLSHAPES_H__

#include <memory>
#include <vector>

class Shape;

void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes);
#endif