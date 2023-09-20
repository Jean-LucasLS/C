#include <stdio.h>

int main(){
  int x = 10;
  int *pointer;

  pointer = &x; // 'pointer' is pointing to 'x' memory adress

  int y = 20;

  *pointer = y; // '*pointer' is receiving a value and storing it inside the 'x' memory adress

  printf("x -> %d\ny -> %d", x, y);

  return;
}