#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>
#include "note.hpp"

namespace lutsaj
{
  class PhoneBook
  {
  public:
    using iterator = std::list< lutsaj::note_t >::iterator;
    using const_iterator = std::list< lutsaj::note_t >::const_iterator;

    const_iterator begin();
    const_iterator end();

    void insertAfter(const_iterator it, const lutsaj::note_t& note);
    void insertBefore(const_iterator it, const lutsaj::note_t& note);
    void pushBack(const lutsaj::note_t& note);
    void deleteNote(const_iterator it);
    size_t size() const;
    bool isEmpty() const;

  private:
    std::list< lutsaj::note_t > book;
  };
}

#endif
