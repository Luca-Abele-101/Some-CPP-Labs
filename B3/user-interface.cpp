#include "user-interface.hpp"
#include "note.hpp"
#include "phone-book.hpp"
#include "functions.hpp"


lutsaj::UserInterface::UserInterface(PhoneBook& book):
  book(std::make_unique< PhoneBook >(book))
{
  bookmarks.insert(std::make_pair("current", book.begin()));
}

void lutsaj::UserInterface::add(const note_t& note)
{
  book->pushBack(note);
  if (book->size() == 1)
  {
    bookmarks["current"] = book->begin();
  }
}

void lutsaj::UserInterface::store(const std::string& bookmark, const std::string& newBookmark)
{
  iteratorType iter = bookmarks.find(bookmark);
  bookmarks.insert(std::make_pair(newBookmark, iter->second));
}

void lutsaj::UserInterface::insertBefore(const std::string& bookmark, const note_t& note)
{
  if (book->size() == 0)
  {
    add(note);
  }
  else
  {
    iteratorType iter = bookmarks.find(bookmark);
    book->insertBefore(iter->second, note);
  }
}

void lutsaj::UserInterface::insertAfter(const std::string& bookmark, const note_t& note)
{
  if (book->size() == 0)
  {
    add(note);
  }
  else
  {
    iteratorType iter = bookmarks.find(bookmark);
    book->insertAfter(iter->second, note);
  }
}

void lutsaj::UserInterface::deleteNote(const std::string& bookmark)
{
  iteratorType iter = bookmarks.find(bookmark);
  auto tempIter = iter->second;
  iteratorType current = bookmarks.begin();
  while (current != bookmarks.end())
  {
    if (current->second == tempIter)
    {
      if (std::next(current->second) == book->end())
      {
        current->second = book->begin();
      }
      else
      {
        ++current->second;
      }
    }
    current++;
  }
  book->deleteNote(tempIter);
}

lutsaj::note_t lutsaj::UserInterface::show(const std::string& bookmark) const
{
  if (book->size() == 0)
  {
    throw std::invalid_argument("<EMPTY>");
  }
  constIteratorType iter = bookmarks.find(bookmark);
  return *iter->second;
}

void lutsaj::UserInterface::move(const std::string& bookmark, int steps)
{
  iteratorType iter = bookmarks.find(bookmark);
  int distance = 0;
  if (steps > 0)
  {
    distance = std::distance(iter->second, book->end());
    if (steps >= distance)
    {
      iter->second = std::prev(book->end());
      return;
    }
  }
  else
  {
    distance = std::distance(book->begin(), iter->second);
    if (std::abs(steps) >= distance)
    {
      iter->second = book->begin();
      return;
    }
  }
  std::advance(iter->second, steps);
}

void lutsaj::UserInterface::move(const std::string& bookmark, const std::string& keyWord)
{
  iteratorType iter = bookmarks.find(bookmark);
  if (keyWord == "first")
  {
    iter->second = book->begin();
  }
  else if (keyWord == "last")
  {
    if (book->isEmpty())
    {
      iter->second = book->end();
    }
    else
    {
      iter->second = std::prev(book->end());
    }
  }
}

bool lutsaj::UserInterface::contains(const std::string& bookmark) const
{
  return (bookmarks.find(bookmark) != bookmarks.end());
}

bool lutsaj::UserInterface::empty() const
{
  return (book->isEmpty());
}
