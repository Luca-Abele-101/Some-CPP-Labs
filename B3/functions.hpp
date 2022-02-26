#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

namespace lutsaj
{
  constexpr size_t getFactorial(const size_t n)
    {
    if (n < 2)
      {
        return 1;
      }
    return n * getFactorial(n - 1);
    }
  std::istream& readName(std::istream& in, std::string& name);
  void empty(std::ostream& out);
  void invalidCommand(std::ostream& out);
  void invalidStep(std::ostream& out);
  void invalidBookmark(std::ostream& out);
}
#endif
