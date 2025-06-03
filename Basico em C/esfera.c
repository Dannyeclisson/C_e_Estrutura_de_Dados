#include <stdio.h>
#include <math.h>

int main(){
    double pi, r, volume;
    pi = 3.14159;

    scanf("%lf", &r);

    r = pow(r,3);

    volume = (4.0/3.0)*(pi*r);

    printf ("VOLUME = %.3lf\n", volume);
    return 0;
}