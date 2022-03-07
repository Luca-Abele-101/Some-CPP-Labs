#include "tasks.hpp"
#include "functions.hpp"
#include "sort.hpp"
#include "strategies.hpp"

void lutsaj::task4(const std::string& order, int n)
{
  std::function<bool(const double&, const double&)> cmp = lutsaj::comparator<double>(order);

  std::vector<double> vec(n);
  lutsaj::fillRand(vec.data(), n);
  lutsaj::print(vec.begin(), vec.end(), std::cout);
  lutsaj::sort<double, lutsaj::indexStrateg>(vec, cmp);
  lutsaj::print(vec.begin(), vec.end(), std::cout);
}
