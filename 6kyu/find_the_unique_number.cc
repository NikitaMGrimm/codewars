// https://www.codewars.com/kata/585d7d5adb20cf33cb000235/train/cpp

// There is an array with some numbers. All numbers are equal except for one. Try to find it!

// find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1});  // --> 2
// find_uniq(std::vector<float>{0, 0, 0.55, 0, 0});  // --> 0.55

// It’s guaranteed that array contains at least 3 numbers.

// The tests contain some very huge arrays, so think about performance.

// This is the first kata in series:

//     Find the unique number (this kata)
//     Find the unique string
//     Find The Unique

float find_uniq(const std::vector<float> &v) {
  std::map<float, int> count;
  for (auto&& num : v) {
    ++count[num];
  }
  auto it = count.begin();
  return it->second == 1 ? it->first : std::next(it)->first;
}

// This is a better solution: 

float find_uniq2(const std::vector<float> &arr)
{
  float n = arr[0];
  if (n != arr[1] && n != arr[2]) return n;
  for(auto w: arr) {
    if (w != n) return w; 
  }
} 