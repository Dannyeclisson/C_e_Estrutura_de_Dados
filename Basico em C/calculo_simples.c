#include <stdio.h>

int main(){

    int c1, c2;
    double n1, n2, v1, v2, total;

    scanf("%f %lf %lf", &c1, &n1, &v1);
    scanf("%f %lf %lf", &c2, &n2, &v2);

    if (n1>1)
    {
        v1 = v1 * n1;
    }
    
    if (n2>1)
    {
        v2 = v2 * n2;
    }
    

    total = v1+v2;

    printf("VALOR A PAGAR: R$ %.2lf\n", total);
    return 0;
}