// https://www.codewars.com/kata/55a70521798b14d4750000a4

// Make a function that will return a greeting statement that uses an input; your program should return, "Hello, <name> how are you doing today?".

// [Make sure you type the exact thing I wrote or the program may not execute properly]
// Strings
// Fundamentals

#include <string>

std::string greet(const std::string& n){
  std::string greeting = "Hello, " + n + " how are you doing today?";
  return greeting;
}
