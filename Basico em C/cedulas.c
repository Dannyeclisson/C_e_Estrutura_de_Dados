#include <stdio.h>

int main(){
    int saque;
    int cem = 0;
    int cinquenta = 0;
    int vinte = 0;
    int dez = 0;
    int cinco = 0;
    int dois = 0;
    int um = 0;

    scanf("%d", &saque);
    printf("%d\n", saque);

    if (saque != 0)
    {
        while (saque >=100)
        {
            cem++;
            saque -=100;
        }
        while (saque>=50)
        {
            cinquenta++;
            saque -=50;
        }
        while (saque>=20)
        {
            vinte++;
            saque -=20;
        }
        while (saque>=10)
        {
            dez++;
            saque -=10;
        }
        while (saque>=5)
        {
            cinco++;
            saque -=5;
        }
        while (saque>=2)
        {
            dois++;
            saque -=2;
        }
        while (saque>=1)
        {
            um++;
            saque -=1;
        }        
    }
    
    printf("%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", cem, cinquenta, vinte, dez, cinco, dois, um);

    return 0;
}