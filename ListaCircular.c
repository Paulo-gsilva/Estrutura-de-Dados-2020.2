#include <stdio.h>
#include <stdlib.h>
#include "No.h"

NO *inicio;
int tam = 0;

//1A - EXPLICAO DA FUNÇÃO ADD:

void add(int id, int sexo, int num_filhotes){
    NO *novo = malloc (sizeof(NO));
    novo -> id           = id;
    novo -> sexo         = sexo;
    novo -> num_filhotes = num_filhotes;

    if(tam == 0){ //ADICIONAR NO INICIO DA LISTA (LISTA SEM ELEMENTOS) - !!CONSTANTE!!
        novo -> prox = novo;   //NOVO ELEMENTO APONTA SEU PROX PARA ELE MESMO
        novo -> ant  = novo;  //NOVO ELEMENTO APONTA SEU ANT PARA ELE MESMO
        inicio       = novo; //INICIO RECEBE O PRIMEIRO ELEMENTO 
    }

    else{ //ADICIONAR SEMPRE NO FIM DA LISTA - !!CONSTANTE!!
        NO *aux = inicio; //PONTEIRO AUX RECEBE O PRIMEIRO ELEMENTO
        novo -> prox = inicio;   //PONTEIRO PROX DO ELEMENTO APONTA PARA O INICIO
        novo -> ant = aux -> ant; //PONTEIRO ANT DO ELEMENTO APONTA PARA O ELEMENTO ANTERIOR
        aux -> ant -> prox = novo; //PONTEIRO ANT RECEBE O PROX DO ELEMENTO ANTERIOR E FAZ ELE APONTAR PARA O ELEMENTO NOVO
        aux -> ant = novo; //ANTERIOR RECEBE NOVO

    }

    tam++;
}


//1C - EXPLICAÇÃO DA FUNÇÃO SOMA:

int soma(NO *inicio){
    NO *aux = inicio; //PONTEIRO AUX RECEBE O PRIMEIRO ELEMENTO
    int somatorio = 0; //FUNÇAO PARA SOMAR OS FILHOTES
    int i;

    for(i = 0 ; i < tam ; i++){
        if(aux -> sexo = 1){ //CONDIÇÃO PARA VERIFICAR SE O CANGURU É FEMEA
            somatorio = somatorio + aux -> num_filhotes; //SOMANDO OS FILHOTES: 0 = 0 + 1... 1 = 1 + 2 ... 3 = 3 + 0 ...
            aux = aux -> prox; //AUX PERCORRE A LISTA
        }
    }
    return somatorio;
    
}


void main(){
    add(1, 1, 2);
    add(2, 1, 1);
    add(3, 0, 0);
    add(4, 1, 2);
    add(5, 0, 0);
    soma(inicio);
}