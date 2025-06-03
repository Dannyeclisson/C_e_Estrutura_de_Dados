#include <stdio.h>

int main(){
    double saque;
    int cem = 0;
    int cinquenta = 0;
    int vinte = 0;
    int dez = 0;
    int cinco = 0;
    int dois = 0;
    int umreal = 0;
    int cinquentacentavos = 0;
    int vintecincocentavos = 0;
    int dezcentavos = 0;
    int cincocentavos = 0;
    int umcentavo = 0;

    scanf("%lf", &saque);
    printf("NOTAS:\n");

    if (saque != 0.00)
    {
        while (saque >=100.00)
        {
            cem++;
            saque -=100.00;
        }
        while (saque>=50.00)
        {
            cinquenta++;
            saque -=50.00;
        }
        while (saque>=20.00)
        {
            vinte++;
            saque -=20.00;
        }
        while (saque>=10.00)
        {
            dez++;
            saque -=10.00;
        }
        while (saque>=5.00)
        {
            cinco++;
            saque -=5.00;
        }
        while (saque>=2.00)
        {
            dois++;
            saque -=2.00;
        }
        while (saque>=1.00)
        {
            umreal++;
            saque -=1.00;
        }
        while (saque>=0.50)
        {
            cinquentacentavos ++;
            saque -=0.50;
        }
        while (saque>=0.25)
        {
            vintecincocentavos ++;
            saque -=0.25;
        }
        while (saque>=0.10)
        {
            dezcentavos ++;
            saque -=0.10;
        }
        while (saque>=0.05)
        {
            cincocentavos ++;
            saque -= 0.05;
        }
        while (saque>=0.01)
        {
            umcentavo ++;
            saque -=0.01;
        }
    }
    
    printf("%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\nMOEDAS:\n%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n", cem, cinquenta, vinte, dez, cinco, dois, umreal, cinquentacentavos, vintecincocentavos, dezcentavos, cincocentavos, umcentavo);

    return 0;
}