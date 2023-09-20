#include <stdio.h>

int main(){
  int x;
  x = 10;

  int *y;
  y = &x;

  printf("*y = %d\n", *y); // Acesses the value of the variable it's pointing to
  printf(" y = %d\n",  y); // Acesses the memory adress of the variable that it's pointing to
  printf("&y = %d\n", &y);
  printf("&x = %d\n", &x);
  //getchar();

  return 0;
}