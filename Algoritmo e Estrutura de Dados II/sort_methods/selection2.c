#include <stdio.h>

#define ELEMENTS 10


int main(void){
  FILE *read_file;

  int minor, aux;
  int vet[ELEMENTS];
  int i, j, k;
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

  // #### Selection sort ####
  for(k = 0; k < ELEMENTS - 1; k++){
    minor = k;
    for(j = k + 1; j < ELEMENTS; j++){
      if(vet[j] < vet[minor]){
        minor = j;
      }
    }
    if(minor != k){
      aux        = vet[minor];
      vet[minor] = vet[k];
      vet[k]     = aux;
    }
  }
  // #### Ending Selection sort ####
  for(j = 0; j < ELEMENTS; j++){
    printf("%d ", vet[j]);
  }

  fclose(read_file);

  return;
}