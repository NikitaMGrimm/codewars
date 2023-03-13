// https://www.codewars.com/kata/57a0556c7cb1f31ab3000ad7

// Write a function which converts the input string to uppercase.

#include <string>

std::string makeUpperCase(const std::string& input_str) {
  std::string str = input_str; // copy the string
  for(auto&& ele: str) { // for each character in the string
    if(97 <= ele && ele <= 122) { // if the character is lowercase
      ele -= 32; // subtract 32 to make it uppercase. ASCII table
    }
  }
  return str;
}
