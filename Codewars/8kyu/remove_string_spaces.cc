// https://www.codewars.com/kata/57eae20f5500ad98e50002c5

// Simple, remove the spaces from the string, then return the resultant string.

#include <string>
#include <algorithm>

std::string no_space(const std::string& str)
{
  std::string out = str;
  std::string::iterator end_pos = std::remove(out.begin(), out.end(), ' ');
  out.erase(end_pos, out.end());
  return out;
}
