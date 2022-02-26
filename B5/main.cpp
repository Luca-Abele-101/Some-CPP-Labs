#include <iostream>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  int task = 0;
  if (argc != 2)
  {
    return 1;
  }
  try
  {
    std::string argStr(argv[1]);
    if (argStr.length() != 1)
    {
      return 1;
    }
    task = std::stoi(argStr);
  }
  catch(const std::exception& e)
  {
    return 1;
  }
  if (task == 1)
  {
    return lutsaj::task1(std::cin, std::cout);
  }
  else if (task == 2)
  {
    return lutsaj::task2(std::cin, std::cout);
  }
  else
  {
    std::cerr << "Incorrect task number (1 or 2 needed)\n";
    return 1;
  }
  return 0;
}
