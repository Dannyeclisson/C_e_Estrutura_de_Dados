#include <stdio.h>
#include <math.h>

int main(){

    char nome[20];
    double salario, vendas, comissao;
    double percentual = 15.00;

    scanf("%s %lf %lf", &nome, &salario, &vendas);

    comissao = (vendas * percentual) / 100;
    salario += comissao;

    printf("TOTAL = R$ %.2lf\n", salario);
    return 0;
}