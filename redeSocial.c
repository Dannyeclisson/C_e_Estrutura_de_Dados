#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100

typedef struct No {
    int id;               // ID do amigo
    struct No* prox;      // Próximo amigo
} No;

typedef struct {
    char nome[50];
    No* amigos;
} Usuario;

Usuario rede[MAX_USUARIOS];
int totalUsuarios = 0;

// Função para adicionar um usuário à rede
int adicionarUsuario(char* nome) {
    // Verifica se o limite maximo de usuarios (definifido no inicio do código) foi atingido
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Erro: Limite máximo de usuários atingido!\n");
        return -1;
    }
    
    // Verificar se o usuário existe se existir retorna um erro
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(rede[i].nome, nome) == 0) {
            printf("Erro: Usuário '%s' já existe!\n", nome);
            return -1;
        }
    }
    
    // Adicionar o novo usuário
    strcpy(rede[totalUsuarios].nome, nome);
    rede[totalUsuarios].amigos = NULL;  // Inicialmente o usuario não tem amigos
    
    printf("Usuário '%s' adicionado com ID %d\n", nome, totalUsuarios);
    
    return totalUsuarios++;  // Retorna o ID e incrementa o contador
}


void exibirUsuarios() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }
    
    printf("\n=== USUÁRIOS CADASTRADOS ===\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d - Nome: %s\n", i, rede[i].nome);
    }
}

int main() {
    printf("=== REDE SOCIAL SIMPLES ===\n\n");
    
    // Testando a adição de usuários
    adicionarUsuario("Alice");
    adicionarUsuario("Bob");
    adicionarUsuario("Carlos");
    adicionarUsuario("Alice");  // (já existe) é pra dar erro
    
    exibirUsuarios();
    
    return 0;
}
