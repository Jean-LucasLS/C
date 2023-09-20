#include <stdio.h>

int main(){
  int x = 10;
  double y = 20.50;
  char z = 'a';

  int *pX;
  pX  = &x;

  double *pY;
  pY = &y;

  char *pZ;
  pZ = &z;

  printf("x Adress -> %i | x Value -> %i\n", pX, *pX);
  printf("y Adress -> %i | y Value -> %f\n", pY, *pY);
  printf("z Adress -> %i | z Value -> %c\n", pZ, *pZ);

  double sum = *pX + *pY;
  printf("*pX + *pY -> %f", sum);

  return;
}