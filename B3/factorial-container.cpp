#include "factorial-container.hpp"

#include <cstddef>
#include <cassert>

#include "functions.hpp"

constexpr size_t MAX_INDEX = 11;

lutsaj::FactorialContainer::Iterator::Iterator():
  number(0),
  value(1)
{
}

lutsaj::FactorialContainer::Iterator::Iterator(const valueType num, const valueType val):
  number(num),
  value(val)
{
}

bool lutsaj::FactorialContainer::Iterator::operator==(const Iterator& other) const
{
  return (value == other.value);
}

bool lutsaj::FactorialContainer::Iterator::operator!=(const Iterator& rhs) const
{
  return !(value == rhs.value);
}

lutsaj::FactorialContainer::Iterator& lutsaj::FactorialContainer::Iterator::operator++()
{
  assert(number < MAX_INDEX && "Out of valueType range\n");
  number++;
  value *= number;
  return *this;
}

lutsaj::FactorialContainer::Iterator lutsaj::FactorialContainer::Iterator::operator++(int)
{
  Iterator tempIt = *this;
  ++(*this);
  return tempIt;
}

lutsaj::FactorialContainer::Iterator& lutsaj::FactorialContainer::Iterator::operator--()
{
  assert (number != 1 && "Out of valueType range\n");
  value /= number;
  number--;
  return *this;
}

lutsaj::FactorialContainer::Iterator lutsaj::FactorialContainer::Iterator::operator--(int)
{
  Iterator tempIt = *this;
  --(*this);
  return tempIt;
}

const lutsaj::FactorialContainer::valueType& lutsaj::FactorialContainer::Iterator::operator*()
{
  return value;
}

const lutsaj::FactorialContainer::valueType* lutsaj::FactorialContainer::Iterator::operator->()
{
  return std::addressof(value);
}

lutsaj::FactorialContainer::Iterator lutsaj::FactorialContainer::begin() const noexcept
{
  return {1, getFactorial(1)};
}

lutsaj::FactorialContainer::Iterator lutsaj::FactorialContainer::end() const noexcept
{
  return {11, getFactorial(MAX_INDEX)};
}
