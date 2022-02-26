#include "note.hpp"

std::ostream& lutsaj::operator<<(std::ostream& out, const lutsaj::note_t& note)
{
  out << note.number << " " << note.name << "\n";
  return out;
}
