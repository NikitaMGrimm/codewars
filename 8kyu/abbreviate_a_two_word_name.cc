// https://www.codewars.com/kata/57eadb7ecd143f4c9c0000a3

// Write a function to convert a name into initials. This kata strictly takes two words with one space in between them.

// The output should be two capital letters with a dot separating them.

// It should look like this:

// Sam Harris => S.H

// patrick feeney => P.F

#include <string>
#include 

std::string makeUpperCase(const std::string& input_str) { // reused from previous kata https://www.codewars.com/kata/57a0556c7cb1f31ab3000ad7

  std::string str = input_str; // copy the string
  for(auto&& ele: str) { // for each character in the string
    if(97 <= ele && ele <= 122) { // if the character is lowercase
      ele -= 32; // subtract 32 to make it uppercase. ASCII table
    }
  }
  return str;
}

std::string abbrevName(std::string name)
{
  std::string abbrev = "";
  unsigned i = 0;
  for(auto&& ele: name) {
    ++i;
    if(ele == ' ') {
      return makeUpperCase(name[0] + abbrev + '.' + name[i]);
    }
  }
  return "";
}
