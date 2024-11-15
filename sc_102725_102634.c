#include <stdio.h>

/* This is all the main variables values the program uses */
/* float movie2D = 12.00; */
/* float movie3D = 15.00; */
/* float iMax = 18.00; */
/**/
/* float before6 = 1; */
/* float after6 = 1.1; */
/* float weekends = 1.15; */
/**/
/* float discChild = 0.5; */
/* float dicsSenior = 0.8; */
/* float discAdult = 1; */
/* float discTuesday = 0.85; */
/**/
/* int age; */

int main() {
  printf("************************\n");
  printf("** Welcome to Cinemax **\n");
  printf("************************\n\n");

  int movieType;

  printf("Please select a movie type: \n");
  printf("1. 2D\n");
  printf("2. 3D\n");
  printf("3. IMAX\n");

  printf("Enter your choice (1-3): ");
  scanf("%d", &movieType);
  return 0;
}
