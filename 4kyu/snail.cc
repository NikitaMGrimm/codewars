// https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/solutions/cpp

// Snail Sort

// Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

// array = [[1,2,3],
//          [4,5,6],
//          [7,8,9]]
// snail(array) #=> [1,2,3,6,9,8,7,4,5]

// For better understanding, please follow the numbers of the next array consecutively:

// array = [[1,2,3],
//          [8,9,4],
//          [7,6,5]]
// snail(array) #=> [1,2,3,4,5,6,7,8,9]

#include <vector>

void stealFirstRow(std::vector<std::vector<int>>& steal_from, std::vector<int>& append_to) {
  for (auto&& e : steal_from[0]) {
    append_to.push_back(e);
  }
  steal_from.erase(steal_from.begin());
}

std::vector<std::vector<int>> transposeMatrix(std::vector<std::vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  if (matrix.empty()) return {};
  std::vector<std::vector<int>> transpose(col, std::vector<int>(row));
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      transpose[j][i] = matrix[i][j];
    }
  }
  return transpose;
}

std::vector<std::vector<int>> flipMatrixHorizontally(std::vector<std::vector<int>>& matrix) {
  std::vector<std::vector<int>> flipped = matrix;
  for (auto&& r : flipped) {
    std::reverse(r.begin(), r.end());
  }
  return flipped;
}

std::vector<std::vector<int>> rotateMatrixAntiClockwise(std::vector<std::vector<int>>& matrix) {
  std::vector<std::vector<int>> rotated = matrix;
  rotated = flipMatrixHorizontally(rotated);
  rotated = transposeMatrix(rotated);
  return rotated;
}

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
  std::vector<int> sorted;
  std::vector<std::vector<int>> to_sort = snail_map;
  while (to_sort.size() != 0) {
    stealFirstRow(to_sort, sorted);
    to_sort = rotateMatrixAntiClockwise(to_sort);
  }
  return sorted;
}


// solution 2 from other user. I like this one better. It's short and sweet.

#include <cstddef>
#include <vector>

std::vector<int> snail2(const std::vector<std::vector<int>>& xs) {
  std::vector<int> res;
  if (xs[0].empty())
    return res;
  const std::size_t ny = xs.size(), nx = xs[0].size();
  res.reserve(ny * nx);
  std::ptrdiff_t x0 = 0, y0 = 0, x1 = nx - 1, y1 = ny - 1, x = 0, y = 0;
  while (y0 <= y1) {
    while (x < x1) res.push_back(xs[y][x++]); y0++;
    while (y < y1) res.push_back(xs[y++][x]); x1--;
    while (x > x0) res.push_back(xs[y][x--]); y1--;
    while (y > y0) res.push_back(xs[y--][x]); x0++;
  }
  res.push_back(xs[y][x]);
  return res;
}
// this works by going along the rows/cols and making the accessible matrix smaller and smaller each time.