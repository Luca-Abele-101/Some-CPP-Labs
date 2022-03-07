#include "tasks.hpp"
#include <fstream>
#include <memory>
#include <vector>
#include "functions.hpp"

void lutsaj::task2(const char* fileName)
{
  if (!fileName)
  {
    throw (std::invalid_argument("Incorrect file name"));
  }
  std::ifstream file(fileName);
  if (!file)
  {
    throw (std::runtime_error("File open error"));
  }

  int capacity = 10;
  int size = 0;
  std::unique_ptr< char[] > in = std::make_unique< char[] >(capacity);

  while (!file.eof())
  {
    file.read(in.get() + size, capacity - size);
    size += file.gcount();
    capacity *= 2;
    std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
    for (int i = 0; i < size; i++)
    {
      temp[i] = in[i];
    }
    in = std::move(temp);
  }

  file.close();
  std::vector< char > vec(in.get(), in.get() + size);
  for (int i = 0; i < size; i++)
  {
    std::cout << vec[i];
  }
}
