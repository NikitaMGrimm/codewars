// https://www.codewars.com/kata/54da539698b8a2ad76000228/solutions/cpp

// You live in the city of Cartesia where all roads are laid out in a perfect grid. You arrived ten minutes too early to an appointment, so you decided to take the opportunity to go for a short walk. The city provides its citizens with a Walk Generating App on their phones -- everytime you press the button it sends you an array of one-letter strings representing directions to walk (eg. ['n', 's', 'w', 'e']). You always walk only a single block for each letter (direction) and you know it takes you one minute to traverse one city block, so create a function that will return true if the walk the app gives you will take you exactly ten minutes (you don't want to be early or late!) and will, of course, return you to your starting point. Return false otherwise.

//     Note: you will always receive a valid array containing a random assortment of direction letters ('n', 's', 'e', or 'w' only). It will never give you an empty array (that's not a walk, that's standing still!).

#include<vector>

bool isValidWalk(std::vector<char> walk) {
  int count_north = 0;
  int count_south = 0;
  int count_east = 0;
  int count_west = 0;
  
  if (walk.size() != 10) return false;
  for (auto&& drctn : walk) {
    if (drctn == 'n') ++count_north;
    if (drctn == 's') ++count_south;
    if (drctn == 'e') ++count_east;
    if (drctn == 'w') ++count_west;
  }
  if (count_north != count_south) return false;
  if (count_east != count_west) return false;
  return true;
}