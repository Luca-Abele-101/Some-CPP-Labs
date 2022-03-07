#include "data-struct.hpp"

#include <sstream>

bool lutsaj::operator<(const DataStruct& d1, const DataStruct& d2)
{
  if (d1.key1 == d2.key1)
  {
    if (d1.key2 == d2.key2)
    {
      return (d1.str.size() < d2.str.size());
    }
    else
    {
      return (d1.key2 < d2.key2);
    }
  }
  else
  {
    return (d1.key1 < d2.key1);
  }
}

std::ostream& lutsaj::operator<<(std::ostream& out, const DataStruct& dataStruct)
{
    out << dataStruct.key1 << ", " << dataStruct.key2 << ", " << dataStruct.str;
    return out;
}

std::istream& lutsaj::operator>>(std::istream& in, DataStruct& dataStruct)
{
  int key1 = 0;
  int key2 = 0;
  std::string str;
  std::string line;
  if (!getline(in, line))
  {
    return in;
  }
  std::istringstream stream(line);

  char commaChecker = ',';
  if (stream >> std::ws >> key1)
  {
    if (stream.get() != commaChecker)
    {
      std::cerr << "Missing comma after first integer\n";
      in.setstate(std::ios_base::failbit);
      return in;
    }
  }
  else
  {
    std::cerr << "Did not find first integer\n";
    in.setstate(std::ios_base::failbit);
    return in;
  }

  commaChecker = ',';
  if (stream >> std::ws >> key2)
  {
    if (stream.get() != commaChecker)
    {
      std::cerr << "Missing comma after second integer\n";
      in.setstate(std::ios_base::failbit);
      return in;
    }
  }
  else
  {
    std::cerr << "Did not find second integer\n";
    in.setstate(std::ios_base::failbit);
    return in;
  }
  
  stream >> std::ws;
  getline(stream, str, '\n');
  if (str == "")
  {
    std::cerr << "Empty string\n";
    in.setstate(std::ios_base::failbit);
    return in;
  }

  dataStruct.str = str;

  if (in && std::abs(key1) <= 5 && std::abs(key2) <= 5)
  {
    dataStruct.key1 = key1;
    dataStruct.key2 = key2;
    //dataStruct = DataStruct{ key1, key2, str };
  }
  else
  {
    std::cerr << "Keys out of range\n";
    in.setstate(std::ios_base::failbit);
    return in;
  }
  return in;
}
