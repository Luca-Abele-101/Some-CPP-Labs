#ifndef SORT_HPP
#define SORT_HPP

#include <functional>
#include <utility>
#include <iostream>

namespace lutsaj
{
  template<typename T, template<typename> typename AccessStrategie>
  void sort(typename AccessStrategie<T>::Container& container,
    const std::function<bool(const T&, const T&)>& comparator)
  {
    using Strateg = AccessStrategie<T>;
    using Iterator = typename AccessStrategie<T>::Iterator;

    Iterator begin = Strateg::begin(container);
    Iterator end = Strateg::end(container);

    for (Iterator i = begin; i != end; i++)
    {
      T extremum = Strateg::get(container, i);
      Iterator extremumIterator = i;
      for (Iterator j = i; j != end; j++)
      {
        T x = Strateg::get(container, j);
        if (comparator(x, extremum))
        {
          extremum = x;
          extremumIterator = j;
        }
      }
      std::swap(Strateg::get(container, i), Strateg::get(container, extremumIterator));
    }
  }
}
#endif
