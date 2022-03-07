#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <cstddef>
#include <iterator>

namespace lutsaj
{
  class FactorialContainer
  {
  public:
    using valueType = size_t;
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, valueType >
    {
    public:
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);
      const valueType& operator*();
      const valueType* operator->();

    private:
      friend class FactorialContainer;
      valueType number;
      valueType value;

      Iterator();
      Iterator(valueType number, valueType value);
    };

    FactorialContainer() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}

#endif
