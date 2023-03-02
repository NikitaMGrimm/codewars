// https://www.codewars.com/kata/55e7280b40e1c4a06d0000aa/train/cpp

// John and Mary want to travel between a few towns A, B, C ... Mary has on a sheet of paper a list of distances between these towns. ls = [50, 55, 57, 58, 60]. John is tired of driving and he says to Mary that he doesn't want to drive more than t = 174 miles and he will visit only 3 towns.

// Which distances, hence which towns, they will choose so that the sum of the distances is the biggest possible to please Mary and John?
// Example:

// With list ls and 3 towns to visit they can make a choice between: [50,55,57],[50,55,58],[50,55,60],[50,57,58],[50,57,60],[50,58,60],[55,57,58],[55,57,60],[55,58,60],[57,58,60].

// The sums of distances are then: 162, 163, 165, 165, 167, 168, 170, 172, 173, 175.

// The biggest possible sum taking a limit of 174 into account is then 173 and the distances of the 3 corresponding towns is [55, 58, 60].

// The function chooseBestSum (or choose_best_sum or ... depending on the language) will take as parameters t (maximum sum of distances, integer >= 0), k (number of towns to visit, k >= 1) and ls (list of distances, all distances are positive or zero integers and this list has at least one element). The function returns the "best" sum ie the biggest possible sum of k distances less than or equal to the given limit t, if that sum exists, or otherwise nil, null, None, Nothing, depending on the language. In that case with C, C++, D, Dart, Fortran, F#, Go, Julia, Kotlin, Nim, OCaml, Pascal, Perl, PowerShell, Reason, Rust, Scala, Shell, Swift return -1.
// Examples:

// ts = [50, 55, 56, 57, 58] choose_best_sum(163, 3, ts) -> 163

// xs = [50] choose_best_sum(163, 3, xs) -> nil (or null or ... or -1 (C++, C, D, Rust, Swift, Go, ...)

// ys = [91, 74, 73, 85, 73, 81, 87] choose_best_sum(230, 3, ys) -> 228
// Notes:

//     try not to modify the input list of distances ls
//     in some languages this "list" is in fact a string (see the Sample Tests).

class BestTravel {
public:
  static int chooseBestSum(int t, int k, std::vector<int>& ls);
private:
  static std::vector<int> removeFromList(const std::vector<int>& ls, int index) {
    std::vector<int> new_list(ls.size() - 1); // allocate space 
    auto it = std::copy_n(ls.begin(), index, new_list.begin()); // copy elements up to index into new_list, pointer after last copied element
    std::copy(ls.begin() + index + 1, ls.end(), it); // insert elements after index'th element
    return new_list;
  }
};

int BestTravel::chooseBestSum(int time, int dest, std::vector<int>& ls) {
  int best_sum = 0;
  if (dest > ls.size()) return -1; // base cases
  if (dest == 1) {
    for (auto&& e : ls) {
      if (e <= time && e > best_sum) best_sum = e;
    }
  }
  for (auto&& e : ls) {
    std::ptrdiff_t i = &e - &ls[0]; // index of the current element
    std::vector<int> shortened_list = removeFromList(ls, i); // remove current element for recursion
    int n = chooseBestSum(time - e, dest - 1, shortened_list); // recursion on the new smaller set
    if (n != -1 && e + n > best_sum && e + n <= time) best_sum = e + n; // check if new solution is the best
  }
  if (best_sum == 0) return -1; // solution of 0 is no solution
  return best_sum;
}

// this solution times out for large lists

// this solution is much faster:
class BestTravel2 {
public:
  static int chooseBestSum(int t, int k, std::vector<int>& ls);
private:
  static void chooseBestSumHelper(int t, int k, std::vector<int>& ls, int start, int curr_sum, int& max_sum);
};

void BestTravel2::chooseBestSumHelper(int t, int k, std::vector<int>& ls, int start, int curr_sum, int& max_sum) {
  if (k == 0) {
    if (curr_sum <= t && curr_sum > max_sum) {
      max_sum = curr_sum;
    }
    return;
  }
  for (int i = start; i < ls.size(); i++) {
    chooseBestSumHelper(t, k-1, ls, i+1, curr_sum+ls[i], max_sum);
  }
}

int BestTravel2::chooseBestSum(int t, int k, std::vector<int>& ls) {
  int max_sum = -1;
  chooseBestSumHelper(t, k, ls, 0, 0, max_sum);
  return max_sum;
}