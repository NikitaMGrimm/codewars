// https://www.codewars.com/kata/57eae65a4321032ce000002d/train/cpp

// Given a string of digits, you should replace any digit below 5 with '0' and any digit 5 and above with '1'. Return the resulting string.

// Note: input will never be an empty string

std::string fakeBin(std::string digits_str) {
  std::string out;
  for (auto&& digit : digits_str) {
    if (digit < '5') {
      out.push_back('0');
    } else {
      out.push_back('1');
    }
  }
  return out;
}

// We might as well mutate the input string and not make a new one.
// (because we already made a copy anyway...)