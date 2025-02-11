#pragma once

#include "StrongType.h"

template<typename T>
using Meter = StrongType<T, struct MeterTag>;

template<typename T>
using Kilometer = StrongType<T, struct KilometerTag>;