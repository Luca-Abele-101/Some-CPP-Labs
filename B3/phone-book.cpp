#include "phone-book.hpp"
#include "note.hpp"

lutsaj::PhoneBook::const_iterator lutsaj::PhoneBook::begin()
{
  return book.cbegin();
}

lutsaj::PhoneBook::const_iterator lutsaj::PhoneBook::end()
{
  return book.cend();
}

void lutsaj::PhoneBook::insertAfter(lutsaj::PhoneBook::const_iterator iter, const lutsaj::note_t& note)
{
  const_iterator tempIter(iter);
  ++tempIter;
  lutsaj::note_t tempNote{note.number, note.name};
  if (tempIter == book.end())
  {
    book.push_back(tempNote);
    return;
  }
  book.insert(tempIter, tempNote);
}

void lutsaj::PhoneBook::insertBefore(lutsaj::PhoneBook::const_iterator iter, const lutsaj::note_t& note)
{
  book.insert(iter, note);
}

void lutsaj::PhoneBook::pushBack(const lutsaj::note_t& note)
{
  book.push_back(note);
}

void lutsaj::PhoneBook::deleteNote(PhoneBook::const_iterator iter)
{
  book.erase(iter);
}

size_t lutsaj::PhoneBook::size() const
{
  return book.size();
}

bool lutsaj::PhoneBook::isEmpty() const
{
  return book.empty();
}
