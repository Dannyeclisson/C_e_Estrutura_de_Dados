#include <stdio.h>

int v[4];

float v1[3];

int main()
{
  v[0] = 45;
  v[1] = 32;
  v[2] = 15;
  v[3] = 22;

  for(int i = 0; i<3; i++)
  {
    printf("\nDigite um valor de numero flutuante: ");
    scanf("%f",&v1[i]);
  }
  
  for(int i = 0; i<3; i++)
  {
    printf("\nO valor de v1[%d] = %.2f", i, v1[i]);
  }

  return 0;
}