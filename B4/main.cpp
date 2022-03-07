#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

#include "data-struct.hpp"

int main()
{
  std::istream_iterator< lutsaj::DataStruct > beginIter(std::cin);
  std::istream_iterator< lutsaj::DataStruct > endIter;
  std::vector< lutsaj::DataStruct > vec(beginIter, endIter);
  if (std::cin.fail() && !std::cin.eof())
  {
    return 2;
  }
  std::sort(vec.begin(), vec.end());
  std::ostream_iterator< lutsaj::DataStruct > out(std::cout, "\n");
  std::copy(vec.begin(), vec.end(), out);
}
