#include <stdio.h>
#include <stdlib.h>

struct no {
    int num;
    struct no *prox;    
};

typedef struct no No;

No *fila;

void add(int num){
    No *n = (No*) malloc(sizeof(No));
    n->num = num;
    u->prox = NULL;

    if (fila==NULL){

        fila = u;
    }else{
        No *filaAux = fila;
        while(filaAux->prox!=NULL){
            filaAux = filaAux->prox;
        }
        fila->prox = u;
    }
}

void rem(){
    if(fila==NULL){
        printf("A lista esta Vazia!");
    }else{
        fila = fila->prox;
    }
}

void imprime(No *f){
    if(f!=NULL){
        printf("A operacao e: %d\n", f->num);
        imprime(f->prox);
    }
}

int main(void){
    int inteiro;
    char op[1];
    int quant = 9;
    while(quant!=0){
        scanf("%c %d", &op, &inteiro);
        if(op == "I"){
            add(inteiro);
            No *filaAux = fila;
        }
        if(op == "F"){
            add(inteiro);
            No *filaAux = fila;
        }
        if(op == "P"){
            rem();
            filaAux = fila;
            imprime(filaAux);
            printf("\n");
        }
        if(op == "D"){
            
        }
        if(op == "X"){
            
        }
        quant --;
    }

}