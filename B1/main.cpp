#include <iostream>
#include <vector>
#include "functions.hpp"
#include "tasks.hpp"

int main(int argc, char** argv)
{
  try
  {
    if ((argc < 2) || (argc > 4))
    {
      throw(std::invalid_argument("Incorrect count of arguments"));
    }
    else if (lutsaj::isNumber(argv[1]))
    {
      int task = atoi(argv[1]);
      if (task == 1 && argc == 3)
      {
        lutsaj::task1(argv[2]);
      }
      else if (task == 2 && argc == 3)
      {
        lutsaj::task2(argv[2]);
      }
      else if (task == 3 && argc == 2)
      {
        lutsaj::task3();
      }
      else if (task == 4 && argc == 4)
      {
        if (lutsaj::isNumber(argv[3]))
        {
          int n = atoi(argv[3]);
          lutsaj::task4(argv[2], n);
        }
        else
        {
          std::cout << "Incorrect argument";
          return 1;
        }
      }
      else
      {
          std::cout << "Incorrect arguments";
          return 1;
      }
    }
    else
    {
      std::cout << "Incorrect argument";
      return 1;
    }
  }
  catch (const std::exception & e)
  {
    std::cout << e.what();
    return 1;
  }
  return 0;
}
