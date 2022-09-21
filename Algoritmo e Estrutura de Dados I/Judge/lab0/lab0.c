#include <stdio.h>
#include <stdlib.h>

/* O ponteiro receberá tipo "(float *)" e alocará (L*sizeof(float)),
sendo o float da esquerda o tipo de variável, e o float da direita
a quantidade de bits reservadas para o dado recebido*/

int main(){
    float *pointer, *M, *F, a;
    int resto, convert, L, i, j, G, contF = 0, contM = 0, qm = 1, qf = 1;
    scanf("%d", &L);
    pointer = (float *)malloc(L*sizeof(float));
    M = (float *)malloc(L*sizeof(float));
    F = (float *)malloc(L*sizeof(float));
    for (i = 0; i < L; i++){
        scanf("%f", &pointer[i]);
        scanf("%d", &G);
        if (G == 0){ // Caso seja masculino.
            pointer[i] = (((pointer[i]*6.67+19)/25.4*3)-24);
            convert = pointer[i] * 10; // o convert é um auxiliar para posteriormente converter o pointer[i] em um inteiro
            resto = convert % 10; // Utiliza-se o convert para ter-se o resto e fazer o critério de arredondamento
            if (resto < 4){
                pointer[i] = convert / 10;
            }
            else if (resto >= 4 && resto < 8){
                pointer[i] = convert / 10;
                pointer[i] += 0.5;
            }
            else{
                pointer[i] = convert / 10;
                pointer[i] += 1;
            }
            M[contM] = pointer[i];
            contM++;
        }
        else if (G == 1){ // Caso seja feminino
            pointer[i] = (((pointer[i]*6.67+19)/25.4*3)-23);
            convert = pointer[i] * 10;
            resto = convert % 10;
            if (resto < 4){
                pointer[i] = convert / 10;
            }
            else if (resto >= 4 && resto < 8){
                pointer[i] = convert / 10;
                pointer[i] += 0.5;
            }
            else{
                pointer[i] = convert / 10;
                pointer[i] += 1;
            }
            F[contF] = pointer[i];
            contF++;
        }
    }
    for (i = 0; i < contM; ++i){ // Laço para colocar em ordem crescente os números masculinos
        for (j = i + 1; j < contM; ++j){
            if (M[i] > M[j]){
                a =  M[i]; // O "a" é um auxiliar para por em troca crescente
                M[i] = M[j];
                M[j] = a;
            }
        }
    }
    for (i = 0; i < contF; ++i){ // Laço para colocar em ordem crescente os números femininos.
        for (j = i + 1; j < contF; ++j){
            if (F[i] > F[j]){
                a =  F[i];
                F[i] = F[j];
                F[j] = a;
            }
        }
    }
    if (contF > 0){
        printf("F ");
        for (j = 0; j < contF;){
            printf("%.1f", F[j]);
            for (i = j + 1; F[i] == F[j]; i++){
                qf++;  
            }
            printf("-(%d) ", qf);
            qf = 1;
            j = i;
        }
        printf("\n");
    }
    if (contM > 0){
        printf("M ");
        for (j = 0; j < contM;){
            printf("%.1f", M[j]);
            for (i = j + 1; M[i] == M[j]; i++){
                qm++;  
            }
            printf("-(%d) ", qm);
            qm = 1;
            j = i;
        }  
    }
    free(M);
    free(F);
    free(pointer); // Liberação de toda memória utilizada e não utilizada.
    return 0;
}