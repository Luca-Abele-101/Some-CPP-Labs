#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <random>

namespace lutsaj
{
  template<typename T>
  std::function<bool(const T&, const T&)> comparator(const std::string& str)
  {
    if (str == "ascending")
      return std::less<T>();
    else if (str == "descending")
      return std::greater<T>();
    else
      throw std::invalid_argument("Incorrect arguments for comparator");
  }

  template<typename T>
  void print(T begin, T end, std::ostream & ostr)
  {
    while (begin != end)
    {
      ostr << *begin << " ";
      begin++;
    }
    ostr << std::endl;
  }

  bool isNumber(const char* str);
  void fillRand(double* arr, size_t size);
}
#endif
