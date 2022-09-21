#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

/* Nota-se que toda vez que se chama a função "t"
o valor da Variável Local Estática vai aumentando,
por que não "reseta" toda vez que a função é chamada,
então as operações se acumulam. Na Variável Automática,
o valor é resetado sempre que se chama a função. */

int main(Void){
    t();
    t();
    return 0;
}

void t(void){
    int VariavelLocalAUTOMATICA = 2;
    VariavelLocalAUTOMATICA *= 2;
    static int VariavelLocalESTATICA = 2;
    VariavelLocalESTATICA *= 2;
    printf("Automatica = %d\nEstatica = %d\n", VariavelLocalAUTOMATICA, VariavelLocalESTATICA);
}