#define ELEMENTS 10
#include <stdio.h>

void print_vector(int vector[]){
  int a;
  for(a = 0; a < ELEMENTS; a++){
    printf("%d ",vector[a]);
  }
}

int main(){
  FILE *read_file;

  int aux;
  int vet[ELEMENTS];
  int i,k,l;

  read_file = fopen("vector.txt","r");
    
  for(i = 0; i < ELEMENTS; i++){
    if(i==0){
      fscanf(read_file, "%d", &vet[0]);
    }
    else{
      fscanf(read_file, " %d", &vet[i]);
    }
  }

  print_vector(vet);

  // #### Bubble sort ####
  for(k = ELEMENTS - 1; k > 0; k--){
    for(l = 0; l < k; l++){
      if(vet[l] > vet[l+1]){
        aux      = vet[l+1];
        vet[l+1] = vet[l];
        vet[l]   = aux;
      }
    }
  }
  // #### Ending Bubble sort ####

  printf("\n\n");
  print_vector(vet);

  fclose(read_file);
  return 0;
}