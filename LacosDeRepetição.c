#include <stdio.h>

int main() {
    printf("\nLaço WHILE\n");

    int a = 0;

    

    while(a<5)
    {
        printf("\nA variavel 'A' é: %d", a);
        a++;
    }

    printf("\nLaço FOR\n");

    //for (Inicializção; teste; incremento)
    for(int i=0 ; i<4 ; i++)
    {
        printf("\nA varivel i é: %d", i);
    }

    return 0;
}