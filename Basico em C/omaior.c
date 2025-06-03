#include <stdio.h>
#include <math.h>
int main(){
    double a, b, c, maiorABC;

    scanf("%lf %lf %lf", &a, &b, &c);

    maiorABC = fmax(a, fmax(b, c));
  
    printf("%.0lf eh o maior", maiorABC);

    return 0;
}