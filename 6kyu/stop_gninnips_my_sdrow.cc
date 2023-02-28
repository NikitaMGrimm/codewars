// https://www.codewars.com/kata/5264d2b162488dc400000001/solutions/cpp

// Write a function that takes in a string of one or more words, and returns the same string, but with all five or more letter words reversed (Just like the name of this Kata). Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

// Examples:

// spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw" 
// spinWords( "This is a test") => returns "This is a test" 
// spinWords( "This is another test" )=> returns "This is rehtona test"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string reverseWord(std::string& word) {
  std::string reversed(word.rbegin(), word.rend());
  return reversed;
}

std::string spinWords(const std::string& str)
{
  std::vector<std::string> word_vector;
  std::string word;

  std::istringstream iss(str);
  while (std::getline(iss, word, ' ')) {
    if (word.length() >= 5) word_vector.push_back(reverseWord(word));
    else word_vector.push_back(word);
  }
                                                 
  std::ostringstream oss;
  for (auto&& w : word_vector) {
    oss << w << ' ';
  }
  return oss.str().substr(0, oss.str().length() - 1);
}

