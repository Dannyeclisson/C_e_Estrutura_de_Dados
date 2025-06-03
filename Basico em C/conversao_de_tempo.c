#include <stdio.h>

int main(){
    int segundos, minutos = 0, horas = 0;

    scanf("%d", &segundos);

    if  (segundos>0)
    {
        while  (segundos>3600)
        {
            horas++;
            segundos-=3600;
        }
        while  (segundos>=60)
        {
            minutos++;
            segundos-=60;
        }
    }
    
    printf("%d:%d:%d\n", horas, minutos, segundos);
    return 0;
}