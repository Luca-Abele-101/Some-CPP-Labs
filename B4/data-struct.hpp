#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <iostream>
#include <string>

namespace lutsaj
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  bool operator<(const DataStruct& d1, const DataStruct& d2);
  std::istream& operator>>(std::istream& in, DataStruct& dataStruct);
  std::ostream& operator<<(std::ostream& out, const DataStruct& dataStruct);
}
#endif
