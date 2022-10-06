/* NOME: Jean-Lucas Luquetti Silva | RA: 120443 | AED I - Turma: IC */
#include <stdio.h> 
#include <stdlib.h>
#define N 10

typedef struct{ // Declaração da estrutura que será utilizada para a lista.
    int size;
    int list[N];
}Jujuba; 

/* Nos métodos utilizados, "*listaux" é um ponteiro utilizado para receber e trabalhar com a "list" (tipo estrutura)
declarada na função principal, fazendo com que suas alterações, através de passagem por referência, sejam passadas
do método para a função "main".
 A seta "->" significa acesso ao campo de uma estrutura passada
por referência, similar a "listaux.last = 0" que é por parâmetro.*/

void Start(Jujuba *listaux){ // Função que inicia a lista, igualando o tamanho da lista a "zero" e os valores do vetor todos a "zero".
    int i=0; 
    listaux->size=0; 
    for(i=0; i<N; i++){
        listaux->list[i]=0;
    }
}

void InsertOnEnd(Jujuba *listaux, int book){ // Método de inserção do livro no último local vazio da lista.
    listaux->list[listaux->size] = book;
    listaux->size++;
}

void Remotion(Jujuba *listaux, int num, int j){
    int i;
    for(i=j; i<N-1; i++){
        listaux->list[i] = listaux->list[i+1];
    }
}

void ListPrint(Jujuba listaux){
    int i=0;
    printf("List printing:\n");
    for(i=0; i<(listaux.size); i++){
        printf("%d\n", listaux.list[i]);
    }
}

int main(){
    Jujuba list; // Declaração da "list" (variável) do tipo "Jujuba" (estrutura).
    int L, op, book, i, j, res=0, ret=0, test=0;
    //printf("Indique quantas reservas e retiradas deseja fazer:\n");
    scanf("%d", &L);
    Start(&list); // "&list" significa que há passagem do endereço da variável "list" do tipo estrutura "Jujuba" para trabalhar com o ponteiro "*listaux".
    for(i=0; i<L; i++){
        scanf("%d %d", &op, &book); // Leitura da operação (op: reserva ou retirada) e número do livro (book).
        if(op == 1){
            if(list.size < N){ // Caso o tamanho da lista seja menor que 10, continua inserindo.
                InsertOnEnd(&list, book);
                printf("Sua reserva foi realizada\n");
                res++;
            }
            else{ // Caso a lista esteja cheia, a condição "else" é acionada.
                printf("Lista de reserva cheia\n");
            }
        }
        else{
            test = ret;
            for(j=0; j<list.size; j++){
                if(book == list.list[j]){
                    Remotion(&list, list.list[j], j);
                    printf("O livro foi retirado com sucesso\n");
                    ret++; // Variável que indicará se foi feito a retirada do livro.
                    list.size--;
                }
            }
            if(test == ret){ // Caso o contador de retirada "ret" não seja acrescido, não houve remoção do livro, pois ele não foi encontrado.
                printf("Voce nao possui reserva desse livro\n");
            }
        }
    }
    printf("Voce realizou %d reservas e %d retiradas\n", res, ret);
    return 0;
}