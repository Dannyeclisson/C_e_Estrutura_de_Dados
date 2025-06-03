#include <stdio.h>
#include <math.h>

int main () {
    int n;
    double h, v, salario;

    scanf("%d\n%lf\n%lf\n", &n, &h, &v);
    salario = (v*h);

    printf("NUMBER = %d\nSALARY = U$ %.2f\n", n, salario);

    return 0;
}