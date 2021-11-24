#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;

}NO;

NO *topo = NULL;
int tam = 0;

void adicionar(int valor){
    NO *novo = (NO*) malloc (sizeof(NO));
    novo -> valor = valor;
    novo -> prox = NULL;

    novo -> prox = topo;
    topo = novo;
    tam++;

}

int size(){
    return tam;
}

int remover(){

    if (tam > 0 ){
        NO *lixo = topo;
        topo = topo -> prox;
        int valor_removido = topo -> valor;
        free(lixo);
        return valor_removido;
    }

    else    
        printf("LISTA VAZIA\n");
        return -1;

}

void imprimir(){
    NO *aux = topo;
    int i;
    
    for(i = 0 ; i < tam ; i++){
        printf("%d\n", aux -> valor);
        aux = aux -> prox;
    }

}

int main(){
    adicionar(1);
    adicionar(3);
    adicionar(5);
    adicionar(3);
    remover();
    adicionar(8);
    remover();
    remover();
    adicionar(7);
    imprimir();

    return 0;
}