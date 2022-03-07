#include "tasks.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

#include "phone-book.hpp"
#include "user-interface.hpp"
#include "functions.hpp"

void lutsaj::task1(std::istream& in, std::ostream& out)
{
  lutsaj::PhoneBook book;
  lutsaj::UserInterface userInterface(book);
  std::string line;
  while (std::getline(in, line) && !line.empty())
  {
    std::istringstream in(line);
    std::string command;
    in >> command;
    if (command == "add")
    {
      std::string number;
      in >> number;
      if (!std::all_of(number.begin(), number.end(), ::isdigit))
      {
        lutsaj::invalidCommand(out);
        continue;
      }
      std::string name;
      lutsaj::readName(in, name);
      if (in)
      {
        userInterface.add({number, name});
      }
      else
      {
        lutsaj::invalidCommand(out);
      }
    }
    else if (command == "store")
    {
      std::string bookmark;
      std::string newBookmark;
      in >> bookmark >> newBookmark;
      if (userInterface.contains(bookmark))
      {
        userInterface.store(bookmark, newBookmark);
      }
      else
      {
        lutsaj::invalidBookmark(out);
      }
    }
    else if (command == "insert")
    {
      std::string place;
      std::string mark;
      std::string number;
      std::string name;
      in >> place >> mark >> number;
      if (!std::all_of(number.begin(), number.end(), ::isdigit))
      {
        lutsaj::invalidCommand(out);
        continue;
      }
      if (place != "before" && place != "after")
      {
        lutsaj::invalidCommand(out);
        continue;
      }
      lutsaj::readName(in, name);
      if (in && userInterface.contains(mark))
      {
        if (place == "before")
        {
          userInterface.insertBefore(mark, {number, name});
        }
        else if (place == "after")
        {
          userInterface.insertAfter(mark, {number, name});
        }
      }
      else
      {
        lutsaj::invalidCommand(out);
      }
    }
    else if (command == "delete")
    {
      std::string mark;
      in >> mark;
      if (userInterface.contains(mark))
      {
        userInterface.deleteNote(mark);
      }
      else
      {
        lutsaj::invalidBookmark(out);
      }
    }
    else if (command == "show")
    {
      std::string mark;
      in >> mark;
      if (userInterface.contains(mark))
      {
        if (!userInterface.empty())
        {
          out << userInterface.show(mark);
        }
        else
        {
          lutsaj::empty(out);
        }
      }
      else
      {
        lutsaj::invalidBookmark(out);
      }
    }
    else if (command == "move")
    {
      std::string mark;
      std::string steps;
      in >> mark >> steps;
      if (userInterface.contains(mark))
      {
        try
        {
          int stepsNum = std::stoi(steps);
          userInterface.move(mark, stepsNum);
        }
        catch(const std::invalid_argument&)
        {
          if (steps == "first")
          {
            userInterface.move(mark, steps);
          }
          else if (steps == "last")
          {
            userInterface.move(mark, steps);
          }
          else
          {
            lutsaj::invalidStep(out);
          }
        }
      }
      else
      {
        lutsaj::invalidBookmark(out);
      }

    }
    else
    {
      lutsaj::invalidCommand(out);
    }
  }
}
