#include <stdio.h>
#include <string.h>

/*
typedef struct Data {
    int Dia;
    char Mês[12];
    int Ano;
}endData;

*/

/*
typedef struct Data {
    int Dia;
    char Mês[12];
    int Ano;
}endData;

int main(){

    printf("Informe sua data de nascimento:");
    scanf("%d %c %d", &Data.dia, &Data.mês, &Data.Ano);
}
*/

typedef struct Cadastro {
    char nome[50];
    int idade;
    char endereco[60];
}endCadastro;


int main(){
    endCadastro cadastro1;
    endCadastro *ptr = &cadastro1;

        ptr->idade = 21;
        strcpy(ptr->nome, "Luisinho");
        strcpy(ptr->endereco, "Estancia3");

        printf("Nome: %s, Idade: %d, Endereco: %s\n", cadastro1.nome, cadastro1.idade, cadastro1.endereco);

    endCadastro cadastro2;
    endCadastro *ptr2 = &cadastro2;

    printf("Digite a idade: ");
    scanf("%d", &ptr2->idade);
    getchar();
    
    printf("\nDigite o nome: ");
    fgets(ptr2->nome, sizeof(ptr2->nome), stdin);

    printf("\nDigite o endereco: ");
    fgets(ptr2->endereco, sizeof(ptr2->endereco), stdin);


    printf("Nome: %s, Idade: %d, Endereco: %s\n", cadastro2.nome, cadastro2.idade, cadastro2.endereco);

    return 0;
}


/*
int main(){
    int N;
    int vetor[1];
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    
    return 0;
}
*/