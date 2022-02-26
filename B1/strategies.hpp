#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#include <forward_list>

namespace lutsaj
{
  template<typename T>
  struct indexStrateg
  {
    using Container = std::vector<T>;
    using Iterator = size_t;

    static Iterator begin(Container&)
    {
      return 0;
    }

    static Iterator end(Container& container)
    {
      return container.size();
    }

    static T& get(Container& container, Iterator iterator)
    {
      return container[iterator];
    }
  };

  template<typename T>
  struct atStrateg
  {
    using Container = std::vector<T>;
    using Iterator = size_t;

    static Iterator begin(Container&)
    {
      return 0;
    }

    static Iterator end(Container& container)
    {
      return container.size();
    }

    static T& get(Container& container, Iterator iterator)
    {
      return container.at(iterator);
    }
  };

  template<typename T>
  struct iteratorStrateg
  {
    using Container = std::forward_list<T>;
    using Iterator = typename Container::iterator;

    static Iterator begin(Container& container)
    {
      return container.begin();
    }

    static Iterator end(Container& container)
    {
      return container.end();
    }

    static T& get(Container&, Iterator& iterator)
    {
      return *iterator;
    }
  };
}
#endif
