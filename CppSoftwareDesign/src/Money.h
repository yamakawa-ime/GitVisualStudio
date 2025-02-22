#pragma once

class Money {};

Money operator*(Money money, double factor);
Money operator+(Money lhs, Money rhs);