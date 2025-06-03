#include <stdio.h>

int main(){
    int dias = 0, mes = 0, ano = 0;

    scanf("%d", &dias);

    if(dias>0){
        while(dias>=365){
            ano ++;
            dias -=365;
        }
        while (dias>=30)
        {
            mes ++;
            dias -=30;
        }
    }

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dias);

    return 0;
}