#include <stdio.h>
#include <stdlib.h>

int main(){

    char ch;
    printf("Digite um Simbolo de pontuação: ");
    ch = getchar();

    switch (ch)
    {
    case '.': printf("Ponto. \n"); break;
    case ',': printf("Virgula. \n"); break;
    case ':': printf("Dois pontos\n"); break;
    }

    return 0;
}