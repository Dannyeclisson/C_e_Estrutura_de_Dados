#include <stdio.h>

int main(){
    double X, Y, consumo;

    scanf("%lf %lf", &X, &Y);
    consumo = (X/Y);

    printf("%.3lf km/l\n", consumo);
    return 0;
}