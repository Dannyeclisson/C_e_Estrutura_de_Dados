#include <stdio.h>
#include <stdlib.h>

//definindo o Nó
typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

//definindo a pilha
typedef struct PILHA{
    NO *topo;
}PILHA;

//Função que inicliza a pilha
void inicializaPilha(PILHA *P){
    P->topo = NULL;
}

//Função que adiciona item na pilha
void empilha(int dado, PILHA *p){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de alocacao de novo no.\n");
        return;
    } else{
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

//função que remove item da pilha
int desempilha(PILHA *p){
    NO* ptr = p->topo;
    int dado;
    if(ptr == NULL){
        printf("Pilha vazia.\n");
        return;
    } else{
        p->topo = p->topo->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

//função que imprime a pilha
void imprimePilha(PILHA *p){
    NO *ptr = p->topo;
    if(ptr == NULL){
        printf("Pilha vazia\n");
        return;
    } else{
        while(ptr != NULL){
            printf("%d", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}


int main(){
    PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));
    if(p1 == NULL){
        printf("Erro de alocacao da pilha .\n");
        exit(0);
    } else {
        inicializaPilha(p1);

        empilha(10, p1);
        empilha(20, p1);
        empilha(30, p1);

        imprimePilha(p1);

        printf("Tentando desempilhar resultado %d\n", desempilha(p1));
        imprimePilha(p1);
        rintf("Tentando desempilhar resultado %d\n", desempilha(p1));
        imprimePilha(p1);
        rintf("Tentando desempilhar resultado %d\n", desempilha(p1));
        imprimePilha(p1);
    }

}