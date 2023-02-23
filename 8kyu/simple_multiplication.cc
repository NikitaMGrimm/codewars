// https://www.codewars.com/kata/583710ccaa6717322c000105

// This kata is about multiplying a given number by eight if it is an even number and by nine otherwise.

int simpleMultiplication(int a){
  if (a % 2) return 9*a;
  else return 8*a;  
}