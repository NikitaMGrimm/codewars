// https://www.codewars.com/kata/5583090cbe83f4fd8c000051/train/cpp

// Convert number to reversed array of digits

// Given a random non-negative number, you have to return the digits of this number within an array in reverse order.
// Example(Input => Output):

// 35231 => [1,3,2,5,3]
// 0 => [0]

#include <vector>
#include <string>

std::vector<int> digitize(unsigned long n) 
{        
  std::string n_str = std::to_string(n);
  std::reverse(n_str.begin(), n_str.end());
  
  std::vector<int> out;
  for (auto&& d : n_str) out.push_back(d - '0');
  return out;
}