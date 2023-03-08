// Variation on https://www.codewars.com/kata/5503013e34137eeeaa001648
// should give this output https://exercism.org/tracks/java/exercises/diamond

/*
to make this...

..A..
.B.B.
C...C
.B.B.
..A.. 

make this first...

{{A..}
 {.B.}
 {..C}} (upper right)

and then reverse inner lists / outer list and stitch together into diamond
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<char>> upperRightDiamondPiece(char max_letter, char fill_char='.') {
  char abc_begin = 'A';
  if ('a' <= max_letter < 'A') abs_begin = 'a'; 
  int size = max_letter - abc_begin + 1;

  std::vector<std::vector<char>> out_vec(size + 1, std::vector<char>(size + 1, fill_char));
  for (int i = 0; i < size; ++i) {
    out_vec[i][i] = abs_begin + i;
  }
}

int main() {
  std::vector<std::vector<char>> ur_dia = upperRightDiamondPiece('G');
  for (auto&& row : ur_dia) {
    for (auto&& l : row) {
      std::cout << l;
    }
    std::cout << std::endl;
  }
}