#include <stdio.h>

struct pessoa 
{
    int idade;
    float altura; 
};

typedef struct pessoa Pessoa;

int main()
{
    Pessoa p;
    p.idade = 50;
    p.altura = 1.78;

    printf("A idade da pessoa é: %d anos\n",p.idade);
    printf("A altura de pessoa é: %.2f m \n",p.altura);

    return 0;
}