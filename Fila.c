#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int id;
    struct no *prox;
} NO;

NO *inicio  = NULL;
NO *fim     = NULL;
int tam = 0;

void adicionar(int id){
    NO *novo = (NO*) malloc (sizeof(NO));
    novo -> id = id;
    novo -> prox = NULL;

    if(tam == 0){ //fila vazia
        inicio = novo;
        fim = novo;
    }

    else{ //fila com elementos
        fim -> prox = novo; //SEMPRE VAI ADICIONAR NO FIM 
        fim = novo;

    }
    tam++;
}

int remover(){ //nao precisa de parametros, pois sempre remove no inicio
    if(tam > 0){
        NO *lixo = inicio;
        if(tam == 1){ //LISTA COM UM ELEMENTO, VOLTA PARA O ORIGINAL
            inicio = NULL;
            fim    = NULL;
        }
        else{
            inicio = inicio -> prox;
        }
        int aux = inicio -> id;
        free(lixo);
        tam--;
        return aux;

    }
    else{
        printf("Lista Vazia\n");
        return -1;
    }

}

void imprimir(){
    NO *aux = inicio;
    while(aux != NULL){
        printf("%d, ", aux -> id);
        aux = aux -> prox;
    }
}

int main(){
    adicionar(10);
    adicionar(7);
    adicionar(5);
    adicionar(3);
    remover();
    remover();
    adicionar(8);
    remover();
    imprimir();

    return 0;
}