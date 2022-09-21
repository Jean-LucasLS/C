#include <stdio.h>
#include <stdlib.h>

int main(Void){
    char *nome; 
    int num, i;
    scanf("%d", &num);
    nome = (char *)malloc(num*sizeof(char));
    for (i = 0; i <= num; i++){
        scanf("%c", &nome[i]);
    }
    for (i = num; i >= 0; i--){
        printf("%c", nome[i]);
    }
    printf("%c", nome[0]);
    free(nome);
    return 0;
}

