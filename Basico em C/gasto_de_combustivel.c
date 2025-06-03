#include <stdio.h>

int main(){
    double t, vm, consumo;

    scanf("%lf %lf", &t, &vm);

    consumo = (t*vm)/12;

    printf("%.3lf\n", consumo);

    return 0;
}