/*
🧪 Exercício: Verificador de Expressão Balanceada (Parênteses)

Descrição:
Implemente um programa em C que verifica se os parênteses (), colchetes [] e chaves {} de uma expressão matemática estão corretamente balanceados. Use uma pilha para armazenar os símbolos de abertura e verificar se cada símbolo de fechamento corresponde ao topo da pilha.

Exemplos de entrada:

({[]}) → Válida

([)] → Inválida

([]{}{()}) → Válida

{[} → Inválida
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct NO{
    char simbolo;
    struct NO *prox;
}NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void inicializaPilha(PILHA *p){
    p->topo = NULL;
}

void empilha(PILHA *p, char simbolo) {
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        exit(1);
    }
    novo->simbolo = simbolo;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilha(PILHA *p) {
    if (p->topo == NULL) {
        return '\0';  // Pilha vazia
    }
    NO *remover = p->topo;
    char simbolo = remover->simbolo;
    p->topo = remover->prox;
    free(remover);
    return simbolo;
}

int corresponde(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

void imprimePilha(PILHA *p){
    NO *ptr = p->topo;
    if(ptr == NULL){
        printf("Pilha Vazia.\n");
        return;
    } else{
        while(ptr != NULL){
            printf("%s", ptr->simbolo);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}

int verificarExpressao(const char *expr) {
    PILHA p;
    inicializaPilha(&p);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            empilha(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char topo = desempilha(&p);
            if (!corresponde(topo, c)) {
                return 0; // Expressão inválida
            }
        }
    }

    return p.topo == NULL; // Se a pilha estiver vazia, está tudo balanceado
}

int main() {
    const char *testes[] = {
        "({[]})",  // válida
        "([)]",    // inválida
        "([]{}{()}", // inválida
        "{[}",     // inválida
        NULL
    };

    for (int i = 0; testes[i] != NULL; i++) {
        printf("Expressao: %s => %s\n", testes[i],
               verificarExpressao(testes[i]) ? "Válida" : "Inválida");
    }

    return 0;
}