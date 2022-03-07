#include "tasks.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>

#include "factorial-container.hpp"

void lutsaj::task2(std::ostream& out)
{
  using valueType = lutsaj::FactorialContainer::valueType;
  using Container = lutsaj::FactorialContainer;

  Container factorial;
  std::copy(factorial.begin(), factorial.end(), std::ostream_iterator< valueType >(out, " "));
  out << "\n";
  std::reverse_copy(factorial.begin(), factorial.end(), std::ostream_iterator< valueType >(out, " "));
  out << "\n";
}
