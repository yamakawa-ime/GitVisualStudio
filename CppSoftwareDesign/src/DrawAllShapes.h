#pragma once

#include <memory>
#include <vector>

class Shape;

void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes);