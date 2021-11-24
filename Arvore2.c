#include <stdio.h>
#include <stdlib.h>

//FOLHAS: NAO TEM FILHOS
//GRAFOS: CONEXOS E ACICLICOS. UMM PAI SÓ PODE TER NO MÁXIMO 2 FILHOS

typedef struct no{ //criando struct
    int chave;
    struct no *esquerda; //PONTEIRO ESQUERDA APONTA PARA STRUCT
    struct no *direita; //PONTEIRO DIREITA APONTA PARA STRUCT
    struct no *pai;
} NO;

NO* raiz = NULL;

NO* busca(int x, NO *aux){
    if(aux == NULL){ //ARVORE VAZIA
        return NULL;
    }

    else if(x == aux -> chave){ //VALOR ENCONTRADO
        return aux;
    }

    else if(x < aux -> chave){ //PROCURAR NO LADO ESQUERDO
        if(aux -> esquerda != NULL){
            return busca(x, aux -> esquerda); //RECURSAO PARA CHAMAR A FUNÇAO NOVAMENTE
        }
        else{ //LADO ESQUERDO VAZIO
            return aux; //PAI DO ELEMENTO NAO ENCONTRADO, RETORNA AUX PARA PODER ADICIONAR O ELEMENTO
        }
    }

    else{ //x > aux -> chave
        if(aux -> direita != NULL){ //PROCURAR NO LADO DIREITO
            return busca(x, aux -> direita); //RECURSAO PARA CHAMAR A FUNÇAO NOVAMENTE
        }
        else{ //DIREITA VAZIA
            return aux; //PAI DO ELEMENTO NAO ENCONTRADO, RETORNA AUX PARA PODER ADICIONAR O ELEMENTO
        }
    }

}


void adicionar(int x){
    NO *valor = busca(x, raiz);
    if(valor == NULL || valor -> chave != x){ //VAZIA OU POSSIBILIDADE DE ADICIONAR
        NO* novo = malloc(sizeof(NO));
        novo -> chave = x;
        novo -> pai = valor;
        novo -> esquerda = NULL;
        novo -> direita  = NULL;

        if(valor == NULL){ //ADICIONAR NA RAIZ
            raiz = novo;
        }
        else{
            if(x < valor -> chave){
                valor -> esquerda = novo;
            }
            else{
                valor -> direita = novo;
            }
        }
    }
    else{ //EVITA ADICIONAR  O MESMO VALOR: NAO PODE TER CHAVE DUPLICADA x == valor -> chave
        printf("Adicionar Invalido: Chave Duplicada\n");
    }

}

NO *buscar_arvore(int x){
    NO* valor = busca(raiz, x);

    if(valor == NULL){ //VALOR NAO ENCONTRADO
        return NULL;
    }
    else{ //VALOR ENCONTRADO
        if(valor -> chave == x){
            return valor; //VALOR ENCONTRADO
        }
        else{
            return NULL; //VALOR NAO ENCONTRADO
        }
    }
}


//PERCORRER ESQUERDA
//PROCESSAR NO
//PERCORRER DIREITA
void imprimir(NO* aux){
    if(aux -> esquerda != NULL){
        imprimir(aux -> esquerda); 
    }
    printf("%d, ", aux -> chave);
    if(aux -> direita != NULL){
        imprimir(aux -> direita);
    }


}

int main(){
    adicionar(11);
    adicionar(8);
    adicionar(12);
    adicionar(7);
    adicionar(10);
    adicionar(9);
    imprimir(raiz);
    return 0;

}