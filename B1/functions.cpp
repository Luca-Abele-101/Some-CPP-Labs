#include "functions.hpp"
#include <ctime>
#include <cstring>

bool lutsaj::isNumber(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

void lutsaj::fillRand(double* arr, size_t size)
{
  if (size <= 0)
  {
    throw(std::invalid_argument("Array size less than zero in fillRand"));
  }
  for (size_t i = 0; i < size; i++)
  {
    arr[i] = (static_cast<double>(rand()) / RAND_MAX) * 2 - 1;
  }
}
