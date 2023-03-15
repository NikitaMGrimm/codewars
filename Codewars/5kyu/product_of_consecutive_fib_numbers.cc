// https://www.codewars.com/kata/5541f58a944b85ce6d00006a/solutions/cpp

// The Fibonacci numbers are the numbers in the following integer sequence (Fn):

//     0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...

// such as

//     F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

// Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

//     F(n) * F(n+1) = prod.

// Your function productFib takes an integer (prod) and returns an array:

// [F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)

// depending on the language if F(n) * F(n+1) = prod.

// If you don't find two consecutive F(n) verifying F(n) * F(n+1) = prodyou will return

// [F(n), F(n+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)

// F(n) being the smallest one such as F(n) * F(n+1) > prod.
// Some Examples of Return:

// (depend on the language)

// productFib(714) # should return (21, 34, true), 
//                 # since F(8) = 21, F(9) = 34 and 714 = 21 * 34

// productFib(800) # should return (34, 55, false), 
//                 # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55
// -----
// productFib(714) # should return [21, 34, true], 
// productFib(800) # should return [34, 55, false], 
// -----
// productFib(714) # should return {21, 34, 1}, 
// productFib(800) # should return {34, 55, 0},        
// -----
// productFib(714) # should return {21, 34, true}, 
// productFib(800) # should return {34, 55, false}, 

// Note:

//     You can see examples for your language in "Sample Tests".

#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod);
};

std::vector<ull> ProdFib::productFib(ull prod) {
  ull fib0 = 0;
  ull fib1 = 1;
  
  ull helper;
  while (fib0 * fib1 <= prod) {
    helper = fib0;
    fib0 = fib1;
    fib1 = helper + fib0;
  }
  if (fib0 * helper == prod) return {helper, fib0, true};
  return {fib0, fib1, false}; // this would've been better had i not done the while loop with a <= but a < instead
}