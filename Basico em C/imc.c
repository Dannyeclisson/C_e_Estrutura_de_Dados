#include <stdio.h>

int main(){
    double peso, altura, imc;

    scanf("%lf %lf", &peso, &altura);

    imc = peso/(altura * altura);

    printf("Seu IMC é: %.2lf\n", imc);

    return 0;
}