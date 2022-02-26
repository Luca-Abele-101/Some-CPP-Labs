#include "tasks.hpp"
#include "functions.hpp"

#include <stdexcept>
#include <vector>

void lutsaj::task3()
{
  std::vector< int > vec;
  int x = 0;

  while (std::cin >> x && x != 0)
  {
    vec.push_back(x);
  }

  if ((x != 0) || (!std::cin.eof() && std::cin.fail()) || std::cin.bad())//std::cin.fail()
  {
    throw(std::runtime_error("Incorrect input in task3\n"));
  }
  if (!vec.empty())
  {
    if (vec.back() == 1)
    {
      auto iter = vec.begin();
      while (iter != vec.end())
      {
        if (*iter % 2 == 0)
        {
          iter = vec.erase(iter);
        }
        else
        {
          ++iter;
        }
      }
    }
    else if (vec.back() == 2)
    {
      auto iter = vec.begin();
      while (iter != vec.end())
      {
        if (*iter % 3 == 0)
        {
          iter = vec.insert(iter + 1, { 1,1,1 });
        }
        else
        {
          ++iter;
        }
      }
    }

    lutsaj::print(vec.begin(), vec.end(), std::cout);
  }
}
