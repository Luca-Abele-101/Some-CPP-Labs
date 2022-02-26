#include <iostream>
#include <algorithm>

#include "tasks.hpp"
#include "functions.hpp"

int main(int argc, char* argv[])
{
  int code = 0;
  if (argc != 2)
  {
    code = 1;
  }
  int task = 0;
  try
  {
    std::string argument(argv[1]);
    if (argument.length() != 1)
    {
      code = 1;
    }
    task = std::stoi(argument);
  }
  catch(const std::exception& e)
  {
    code = 1;
  }
  if (!code && task == 1)
  {
    lutsaj::task1(std::cin, std::cout);
  }
  else if (!code && task == 2)
  {
    lutsaj::task2(std::cout);
  }
  else
  {
    std::cerr << "Invalid arguments\n";
    code = 1;
  }
  return code;
}
