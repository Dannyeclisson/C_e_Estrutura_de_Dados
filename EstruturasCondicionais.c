#include <stdio.h>

int main() {

    int a;
    printf("Digite um numero: ");
    scanf("%d", &a);

    // == igualdade
    // > maior
    // < menor
    // >= maior ou igual
    // <= menor ou igual
    // != diferente

    if(a==0){
        printf("\nA varivel 'a' é = 0.");
    }
    else {
        printf("\nA variavel não é igual a 0.");
    }
    
    return 0;
}