#include <stdio.h>

void var_test(int x){
  ++x;
}

void pointer_test(int *pX){
  ++*pX;
}

int main(){
  int test = 1;
  int *ptest = &test;

  var_test(test);
  printf("test -> %d | ptest -> %d\n", test, *ptest);

  pointer_test(ptest);
  printf("test -> %d | ptest -> %d", test, *ptest);

  return;
}