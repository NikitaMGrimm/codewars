// https://www.codewars.com/kata/54da5a58ea159efa38000836/train/cpp

// Given an array of integers, find the one that appears an odd number of times.

// There will always be only one integer that appears an odd number of times.
// Examples

// [7] should return 7, because it occurs 1 time (which is odd).
// [0] should return 0, because it occurs 1 time (which is odd).
// [1,1,2] should return 2, because it occurs 1 time (which is odd).
// [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
// [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).

#include <vector>

int findOdd(const std::vector<int>& numbers){
  std::map<int, int> counts;
  
  for (auto&& num : numbers) {
    auto it = counts.find(num);
    if (it == counts.end()) {
      counts.insert({num, 1});
    } else {
      it->second++;
    }
  }
  
  for (auto&& count : counts) {
    if (count.second % 2 != 0) return count.first;
  }
}

// better solution

#include <vector>

int findOdd2(const std::vector<int>& numbers){
  std::map<int, int> counts;
  
  for (auto&& num : numbers) {
    ++counts[num];
  }
  
  for (auto&& count : counts) {
    if (count.second % 2 != 0) return count.first;
  }
}

// THE BEST SOLUTION

#include <functional>
#include <numeric>
#include <vector>

int findOdd3(const std::vector<int>& numbers) {
  return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}
