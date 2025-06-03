#include <stdlib.h>
#include <stdio.h>

//Declarando o Nó
typedef struct node {
    int data;
    struct node* next;
} Node;

//Declarando a fila
typedef struct {
    Node* inicio;
    Node* fim;
} Fila;

/*
void incializarFila(Fila* f){
    f->inicio = NULL;
    f->fim = NULL;
}
*/

Fila* criarFila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL){
        printf("Erro ao alocar memoria para a fila\n");
        exit(1);
    }
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enqueue(Fila* f, int valor){
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->next = novo;
        f->fim = novo;
    } 
}

int dequeue(Fila* f) {
    if (f->inicio == NULL){
        printf("Fila vazia!\n");
        return -1;
    }

    Node* temp = f->inicio;
    int valor = temp->data;
    f->inicio = f->inicio->next;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    return valor;
}

void liberarFila(Fila* f) {
        while (f->inicio != NULL) {
            dequeue(f);
        }
        free(f);
    }

int main() {
    int opcao = 1;
    int aux;
    int tamanho = 0;
    printf("Instrucoes de uso: digite 1 para inserir um numero na fila ou 0 para não inserir");
    printf("Digite uma opcao: ");
    scanf("%d", &opcao);

    Fila* f = criarFila();
    while (opcao == 1)
    {
        printf("Digite um número para ser inserido na fila: ");
        scanf("%d", &aux);
        enqueue(f, aux);
        printf("%d inserido na fila \n", aux);
        tamanho ++;
        printf("Deseja continua com a insercao? se sim digite 1 se não digite 0 e vera os numeros sendo removidos da fila: ");
        scanf("%d", &opcao);
    }
    
    while (tamanho != 0 ){
        tamanho --;
        printf("Removido: %d\n", dequeue(f));
    }

    liberarFila(f);
    return 0;
}