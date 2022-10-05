#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct{
    int size;
    int list[N];
}Jujuba;

void Start(Jujuba *listaux){
    int i=0; 
    listaux->size=0; // A seta "->" significa acesso ao campo de uma estrutura passada por referência, similar a "listaux.last = 0" que é por parâmetro.
    for(i=0; i<N; i++){
        listaux->list[i]=0;
    }
}

Jujuba InsertOnEnd(Jujuba *listaux, int a){
    listaux->size++;
    listaux->list[listaux->size-1]=a;
    return *listaux;
}

void Remotion(Jujuba *listaux, int num, int j){
    int i;
    for(i=j; i<N-1; i++){
        listaux->list[i] = listaux->list[i+1];
    }
    listaux->size--;
}

void ListPrint(Jujuba listaux){
    int i=0;
    printf("List printing:\n");
    for(i=0; i<(listaux.size); i++){
        printf("%d\n", listaux.list[i]);
    }
}

void main(void){
    Jujuba list;
    int L, op, book, i, j, res=0, ret=0, test=0;
    printf("Indique quantas reservas e retiradas deseja fazer:\n");
    scanf("%d", &L);
    Start(&list);
    for(i=0; i<L; i++){
        scanf("%d %d", &op, &book); // Leitura da operação (op: reserva ou retirada) e número do livro (book).
        if(op == 1){
            if(list.size <= N){ // Caso o tamanho da lista seja menor que 10, continua inserindo.
                InsertOnEnd(&list, book);
                printf("Sua reserva foi realizada\n");
                res++;
            }
            else{
                printf("Lista de reserva cheia\n");
            }
        }
        else{
            test = ret;
            for(j=0; j<list.size; j++){
                if(book == list.list[j]){
                    Remotion(&list, list.list[j], j);
                    printf("O livro foi retirado com sucesso\n");
                    ret++;
                }
            }
            if(test == ret){ // Caso o contador de retirada "ret" não seja acrescido, não houve remoção do livro.
                printf("Voce nao possui reserva desse livro\n");
            }
        }
    }
    printf("Voce realizou %d reservas e %d retiradas\n", res, ret);
}