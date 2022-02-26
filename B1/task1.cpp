#include "tasks.hpp"
#include <forward_list>
#include "sort.hpp"
#include "strategies.hpp"
#include "functions.hpp"

void lutsaj::task1(const std::string& order)
{
  std::vector<int> vec1;
  int digit;
  while (std::cin >> digit)
  {
    vec1.push_back(digit);
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::exception(std::runtime_error("Incorrect digital input in task1\n"));
  }
  if (order != "ascending")
  {
      if (order != "descending")
      {
        throw std::exception(std::runtime_error("Incorrect sorting direction in task1\n"));
      }
  }
  std::function<bool(const int&, const int&)> cmp = lutsaj::comparator<int>(order);
  std::vector<int> vec2 = vec1;
  std::forward_list<int> list(vec1.begin(), vec1.end());
  lutsaj::sort<int, lutsaj::indexStrateg>(vec1, cmp);
  lutsaj::sort<int, lutsaj::atStrateg>(vec2, cmp);
  lutsaj::sort<int, lutsaj::iteratorStrateg>(list, cmp);
  lutsaj::print(vec1.begin(), vec1.end(), std::cout);
  lutsaj::print(vec2.begin(), vec2.end(), std::cout);
  lutsaj::print(list.begin(), list.end(), std::cout);
}
