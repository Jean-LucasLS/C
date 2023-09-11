#define ELEMENTS 10
#include <stdio.h>

int main(){
  FILE *read_file;

  int minor, aux;
  int vet[ELEMENTS];
  int i, j, k, l;
  read_file = fopen("vector.txt", "r");
    
  for(i = 0; i < ELEMENTS; i++){
    if(i==0){
      fscanf(read_file,"%d",&vet[0]); 
    }
    else{
      fscanf(read_file," %d",&vet[i]);
    }
  }
  for(j = 0; j < ELEMENTS; j++){
    printf("%d ", vet[j]);
  }
  printf("\n\n");
    
  //selection sort
  for(k = 0; k < ELEMENTS - 1; k++){
    minor = k;
    for(l = k + 1 ; l < ELEMENTS; l++){
      if(vet[l] < vet[minor]){
        minor = l;
      }
    }
    if(minor != k){
      aux = vet[minor];
      vet[minor] = vet[k];
      vet[k] = aux;
    }
  }
  //-------------------------------

  for(j = 0; j < ELEMENTS; j++){
    printf("%d ", vet[j]);
  }

  fclose(read_file);

  return 0;
}