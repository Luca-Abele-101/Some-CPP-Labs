#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iterator>
#include <set>

int lutsaj::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > beginIter(in);
  std::istream_iterator< std::string > endIter;
  std::set< std::string > wordSet(beginIter, endIter);
  if (in.fail() && !in.eof())
  {
    std::cerr << "Input error\n";
    return 1;
  }
  else
  {
    std::copy(wordSet.begin(), wordSet.end(), std::ostream_iterator< std::string >(out, "\n"));
  }
  return 0;
}
