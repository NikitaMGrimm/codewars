// https://www.codewars.com/kata/5168bb5dfe9a00b126000018/train/cpp

// Complete the solution so that it reverses the string passed into it.

// 'world'  =>  'dlrow'
// 'word'   =>  'drow'

std::string reverseString(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

// this is better: (? looks cleaner)

std::string reverseString2(const std::string& str) {
  return std::string(str.rbegin(), str.rend());
}
