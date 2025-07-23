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
        printf("Erro: Limite maximo de usuarios atingido!\n");
        return -1;
    }
    
    // Verifica se o usuário existe se existir retorna um erro
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(rede[i].nome, nome) == 0) {
            printf("Erro: Usuario '%s' ja existe!\n", nome);
            return -1;
        }
    }
    
    // Adicionar o novo usuário
    strcpy(rede[totalUsuarios].nome, nome);
    rede[totalUsuarios].amigos = NULL;  // Inicialmente o usuario não tem amigos
    
    printf("Usuario '%s' adicionado com ID %d\n", nome, totalUsuarios);
    
    return totalUsuarios++;  // Retorna o ID e incrementa o contador
}

// Função para buscar um usuário pelo nome (retorna o ID)
int buscarUsuario(char* nome) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(rede[i].nome, nome) == 0) {
            return i;  // Retorna o ID do usuário
        }
    }
    return -1;  // Usuário não encontrado
}

// Função para criar um novo nó (representa uma amizade)
No* criarNo(int id) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        return NULL;
    }
    novoNo->id = id;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para verificar se dois usuários já são amigos
int jaSaoAmigos(int id1, int id2) {
    No* atual = rede[id1].amigos;
    while (atual != NULL) {
        if (atual->id == id2) {
            return 1;  // Já são amigos
        }
        atual = atual->prox;
    }
    return 0;  // Não são amigos
}

// Função para criar amizade bidirecional
int criarAmizade(char* nome1, char* nome2) {
    // Buscar os IDs dos usuários
    int id1 = buscarUsuario(nome1);
    int id2 = buscarUsuario(nome2);
    
    //Verificação se os usuários já existem, se não existir retorna um erro
    if (id1 == -1) {
        printf("Erro: Usuario '%s' nao encontrado!\n", nome1);
        return -1;
    }
    if (id2 == -1) {
        printf("Erro: Usuario '%s' nao encontrado!\n", nome2);
        return -1;
    }
    
    // Verificar se não é o mesmo usuário
    if (id1 == id2) {
        printf("Erro: Um usuario nao pode ser amigo de si mesmo!\n");
        return -1;
    }
    
    // Verificar se já são amigos
    if (jaSaoAmigos(id1, id2)) {
        printf("'%s' e '%s' ja sao amigos!\n", nome1, nome2);
        return -1;
    }
    
    // CONEXÃO BIDIRECIONAL:
    
    // 1. Adicionar id2 na lista de amigos de id1
    No* novoNo1 = criarNo(id2);
    if (novoNo1 == NULL) return -1;
    novoNo1->prox = rede[id1].amigos;  // Inserir no início da lista
    rede[id1].amigos = novoNo1;
    
    // 2. Adicionar id1 na lista de amigos de id2
    No* novoNo2 = criarNo(id1);
    if (novoNo2 == NULL) return -1;
    novoNo2->prox = rede[id2].amigos;  // Inserir no início da lista
    rede[id2].amigos = novoNo2;
    
    printf("Amizade criada entre '%s' e '%s'\n", nome1, nome2);
    return 1;  // Sucesso
}

void exibirUsuarios() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    
    printf("\n=== USUARIOS CADASTRADOS ===\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d - Nome: %s\n", i, rede[i].nome);
    }
}

// Função para exibir os amigos de um usuário
void exibirAmigos(char* nome) {
    int id = buscarUsuario(nome);
    if (id == -1) {
        printf("Usuario '%s' nao encontrado!\n", nome);
        return;
    }
    
    printf("\nAmigos de '%s':\n", nome);
    No* atual = rede[id].amigos;
    
    if (atual == NULL) {
        printf("  Nenhum amigo ainda.\n");
        return;
    }
    
    while (atual != NULL) {
        printf("  - %s (ID: %d)\n", rede[atual->id].nome, atual->id);
        atual = atual->prox;
    }
}

// Função para exibir toda a rede social (grafo completo)
void exibirRedeSocial() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado na rede.\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("         REDE SOCIAL COMPLETA\n");
    printf("========================================\n");
    
    for (int i = 0; i < totalUsuarios; i++) {
        printf("\n%s (ID: %d) -> ", rede[i].nome, i);
        
        No* atual = rede[i].amigos;
        
        if (atual == NULL) {
            printf("(sem amigos)");
        } else {
            int primeiro = 1; // Para controlar a formatação
            while (atual != NULL) {
                if (!primeiro) {
                    printf(", ");
                }
                printf("%s", rede[atual->id].nome);
                atual = atual->prox;
                primeiro = 0;
            }
        }
        printf("\n");
    }
    
    printf("========================================\n");
}

// Função para contar total de amizades na rede
int contarAmizades() {
    int totalAmizades = 0;
    
    for (int i = 0; i < totalUsuarios; i++) {
        No* atual = rede[i].amigos;
        while (atual != NULL) {
            totalAmizades++;
            atual = atual->prox;
        }
    }
    
    // Como cada amizade é contada duas vezes (A->B e B->A), dividimos por 2
    return totalAmizades / 2;
}

// Função para exibir estatísticas da rede
void exibirEstatisticas() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuario para exibir estatisticas.\n");
        return;
    }
    
    printf("\n=== ESTATISTICAS DA REDE ===\n");
    printf("Total de usuarios: %d\n", totalUsuarios);
    printf("Total de amizades: %d\n", contarAmizades());
    
    // Encontrar usuário com mais amigos
    int maxAmigos = 0;
    int usuarioPopular = 0;
    
    for (int i = 0; i < totalUsuarios; i++) {
        int contadorAmigos = 0;
        No* atual = rede[i].amigos;
        
        while (atual != NULL) {
            contadorAmigos++;
            atual = atual->prox;
        }
        
        if (contadorAmigos > maxAmigos) {
            maxAmigos = contadorAmigos;
            usuarioPopular = i;
        }
    }
    
    if (maxAmigos > 0) {
        printf("Usuario mais popular: %s (%d amigos)\n", 
               rede[usuarioPopular].nome, maxAmigos);
    } else {
        printf("Nenhuma amizade registrada ainda.\n");
    }
}

int main() {
    printf("=== REDE SOCIAL SIMPLES ===\n\n");
    
    // Testando a adição de usuários
    adicionarUsuario("Alice");
    adicionarUsuario("Bob");
    adicionarUsuario("Carlos");
    adicionarUsuario("Diana");
    adicionarUsuario("Eva");
    
    printf("\n=== CRIANDO AMIZADES ===\n");
    
    // Criando uma rede mais interessante
    criarAmizade("Alice", "Bob");
    criarAmizade("Alice", "Carlos"); 
    criarAmizade("Bob", "Diana");
    criarAmizade("Carlos", "Diana");  // Agora Diana tem 2 amigos
    criarAmizade("Bob", "Carlos");    // Formando um triângulo Alice-Bob-Carlos
    // Eva fica isolada (sem amigos)
    
    // Testando algumas validações
    printf("\n=== TESTANDO VALIDAÇÕES ===\n");
    criarAmizade("Alice", "Bob");     // Erro: já são amigos
    criarAmizade("Alice", "Alice");   // Erro: mesmo usuário
    criarAmizade("Eva", "Pedro");     // Erro: Pedro não existe
    
    // Exibindo a rede completa
    exibirRedeSocial();
    
    // Exibindo estatísticas
    exibirEstatisticas();
    
    printf("\n=== AMIGOS INDIVIDUAIS ===\n");
    
    // Testando exibição individual
    exibirAmigos("Alice");
    exibirAmigos("Diana");
    exibirAmigos("Eva");  // Sem amigos
    
    return 0;
}
