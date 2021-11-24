#include<stdlib.h>
#include<stdio.h>

typedef struct no{
    int valor;
    struct no *prox;
    struct no *ant;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void adicionar(int valor, int pos){
    
    if(pos>= 0 && pos<=tam){ //- LISTA - posicao valida
        
        NO *novo = malloc(sizeof(NO));
        novo -> valor = valor;
        novo -> prox  = NULL;
        novo -> ant   = NULL;
        
        if(tam == 0){ //lista vazia
            inicio = novo;
            fim    = novo;
            
        }else if(pos == 0){//inicio da lista quando a lista tem elementos
            novo   -> prox = inicio; //novo inicio aponta para o antigo inicio
            inicio -> ant  = novo; //ant do inicio aponta para o novo
            inicio = novo; //inicio aponta para o novo valor
         
        }
        else if(pos == tam){ //fim da lista
            fim  -> prox = novo; //fim aponta para o novo elemento
            novo -> ant  = fim;
            fim = novo;
        }   
        
        else {//meio da lista quando a lista tem elementos (linear)
            NO *aux = inicio;
            int i;
                       
            for( i= 0 ; i < pos-1 ; i++){
                aux = aux -> prox;
            }
            novo -> prox = aux;
            aux  -> ant -> prox = novo;
            novo -> ant = aux -> ant;
            aux  -> ant = novo;
        }
        
        tam++;
        
        
    }else{
        printf("Posicao INVÁLIDA :/!\n");
    }
}

void remover(int pos){
 
    if(pos>=0 && pos<tam){ // posição válida para ser removida
        
        if(tam == 1){ //unico elemento na lista (constante)
            NO *lixo = inicio;
            inicio = NULL;
            fim = NULL;
            free(lixo);
            
        }else if(pos == 0){//o primeiro elemento da lista e ela tem mais de um elemento (constante)
            NO *lixo = inicio;
            inicio = inicio->prox;
            inicio -> ant = NULL;
            free(lixo);
        }
        
        else if(pos == tam - 1){
            NO *lixo = inicio;
            fim = fim -> ant;
            fim -> prox = NULL;
            free(lixo);
            
        }
        
        else{//no meio e a lista tem mais de um elemento
            NO *aux = inicio;
            int i;
            for(i=0; i<pos-1; i++){
                aux = aux->prox;
            }
            
            NO *lixo = aux;
            //aux->prox = NULL;
            aux-> ant ->prox = aux->prox;
            aux -> prox -> ant = aux -> prox -> ant -> ant;
            free(aux);
        }
        tam--;
    }else{
        printf("Posicao INVÁLIDA :/!\n");
    }
    
    
    
}

void imprimir(){
    NO* aux = inicio;
    int i;
    for(i=0; i<tam; i++){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}




int main(){
    adicionar(8,0); //vazia
    adicionar(10,0); //no inicio
    adicionar(7,2);  //no fim
    adicionar(5,2);  //no meio
    adicionar(3,1);  //no meio
    printf("\n Teste lista add completo.\n");
    imprimir();
    printf("\n Teste remocao do meio.\n");
    remover(2);
    imprimir();

}
