#include <stdlib.h>
#include <stdio.h>

struct usuario
{
    int senha;
    struct usuario *prox;
};

typedef struct usuario Usuario;

Usuario *fila;

void add(int senha){
    Usuario *u = (Usuario*) malloc(sizeof(Usuario));
    u->senha = senha;
    u->prox = NULL;

    if (fila==NULL){

        fila = u;
    }else{
        Usuario *filaAux = fila;
        while(filaAux->prox!=NULL){
            filaAux = filaAux->prox;
        }
        filaAux->prox = u;
    }
}

void rem(){
    if(fila==NULL){
        printf("A fila esta vazia!");
    }else{
        fila = fila->prox;
    }
}

void imprime(Usuario *f){
    if(f!=NULL){
        printf("Senha da pessoa: %d\n", f->senha);
        imprime(f->prox);
    }
}

int main(void){
    add(5);
    add(6);
    add(7);
    add(8);

    Usuario *filaAux = fila;
    imprime(filaAux);

    printf("\n");

    rem();
    
    filaAux = fila;
    imprime(filaAux);
    printf("\n");
    
    rem();
    
    filaAux = fila;
    imprime(filaAux);

    return 0;
}