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

// Função para inicializar a rede social
void inicializarRede() {
    printf("========================================\n");
    printf("Esse trabalho de ED foi feito por Dannyeclisson - 211061592 e Dylgerfesson - 221029356\n");
    printf("REPRESENTACAO DE GRAFO NAO-DIRECIONADO\n");
    printf("- Vertices: Jogadores (Usuario)\n");
    printf("- Arestas: Amizades (conexoes bidirecionais)\n");
    printf("- Implementacao: Lista de Adjacencia\n");

    printf("========================================\n");
    printf("    INICIALIZANDO REDE SOCIAL SHOW DE BOLA\n");
    printf("========================================\n");
    printf("Sistema iniciado com sucesso!\n");
    printf("Capacidade maxima: %d 'craques'\n", MAX_USUARIOS);
    printf("========================================\n\n");
    
    // Garantir que todas as estruturas estejam zeradas
    totalUsuarios = 0;
    for (int i = 0; i < MAX_USUARIOS; i++) {
        rede[i].amigos = NULL;
        strcpy(rede[i].nome, "");
    }
}

// Função para liberar toda a memória alocada
void liberarMemoria() {
    printf("\n=== LIBERANDO MEMORIA ===\n");
    int nosLiberados = 0;
    
    for (int i = 0; i < totalUsuarios; i++) {
        No* atual = rede[i].amigos;
        
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
            nosLiberados++;
        }
        
        rede[i].amigos = NULL;
    }
    
    printf("Memoria liberada com sucesso!\n");
    printf("Total de nos de amizade liberados: %d\n", nosLiberados);
}

// Função para encerrar o sistema
void encerrarRede() {
    printf("\n========================================\n");
    printf("         ENCERRANDO SISTEMA\n");
    printf("========================================\n");
    
    // Liberar toda a memória alocada
    liberarMemoria();
    
    // Estatísticas finais
    printf("Rede Social show de bola encerrada\n");
    printf("Total de 'Craques' cadastrados: %d\n", totalUsuarios);
    printf("Obrigado por usar a Rede Social Show de Bola!\n");
    printf("========================================\n");
}

// Função para adicionar um usuário à rede
int adicionarUsuario(char* nome) {
    // Verifica se o limite maximo de 'craques' (definifido no inicio do código) foi atingido
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Erro: Limite maximo de 'craques' atingido!\n");
        return -1;
    }

    // Verifica se o 'craque' existe se existir retorna um erro
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(rede[i].nome, nome) == 0) {
            printf("Erro: 'Craque' '%s' ja existe!\n", nome);
            return -1;
        }
    }

    // Adicionar o novo 'craque'
    strcpy(rede[totalUsuarios].nome, nome);
    rede[totalUsuarios].amigos = NULL;  // Inicialmente o 'craque' não tem amigos

    printf("Craque '%s' adicionado com ID %d\n", nome, totalUsuarios);

    return totalUsuarios++;  // Retorna o ID e incrementa o contador
}

// Função para buscar um 'craque' pelo nome (retorna o ID)
int buscarUsuario(char* nome) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(rede[i].nome, nome) == 0) {
            return i;  // Retorna o ID do 'craque'
        }
    }
    return -1;  // 'Craque' não encontrado
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
    printf("         REDE SOCIAL Show de Bola\n");
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

// Função para encontrar amigos em comum entre dois usuários
void amigosEmComum(char* nome1, char* nome2) {
    int id1 = buscarUsuario(nome1);
    int id2 = buscarUsuario(nome2);

    // Verificar se os 'craques' existem
    if (id1 == -1) {
        printf("Erro: 'Craque' '%s' nao encontrado!\n", nome1);
        return;
    }
    if (id2 == -1) {
        printf("Erro: 'Craque' '%s' nao encontrado!\n", nome2);
        return;
    }
    
    // Verificar se não é o mesmo 'craque'
    if (id1 == id2) {
        printf("Erro: Nao e possivel verificar amigos em comum do mesmo 'craque'!\n");
        return;
    }
    
    printf("\nAmigos em comum entre os craques '%s' e '%s':\n", nome1, nome2);
    
    int encontrouAmigos = 0;
    No* amigo1 = rede[id1].amigos;

    // Para cada amigo do primeiro 'craque'
    while (amigo1 != NULL) {
        No* amigo2 = rede[id2].amigos;

        // Verificar se este amigo também está na lista do segundo 'craque'
        while (amigo2 != NULL) {
            if (amigo1->id == amigo2->id) {
                printf("  - %s (ID: %d)\n", rede[amigo1->id].nome, amigo1->id);
                encontrouAmigos = 1;
                break;
            }
            amigo2 = amigo2->prox;
        }
        amigo1 = amigo1->prox;
    }
    
    if (!encontrouAmigos) {
        printf("  Nenhum amigo em comum.\n");
    }
}

// Função para exibir estatísticas da rede
void exibirEstatisticas() {
    if (totalUsuarios == 0) {
        printf("Nenhum craque para exibir estatisticas.\n");
        return;
    }
    
    printf("\n=== ESTATISTICAS DA REDE ===\n");
    printf("Total de craques: %d\n", totalUsuarios);
    printf("Total de amizades: %d\n", contarAmizades());

    // Encontrar craque com mais amigos
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
        printf("Craque mais popular: %s (%d amigos)\n", 
               rede[usuarioPopular].nome, maxAmigos);
    } else {
        printf("Nenhuma amizade registrada ainda.\n");
    }
}

int main() {
    // Inicializar o sistema
    inicializarRede();
    
    printf("=== CADASTRANDO JOGADORES ===\n");
    
    // Cadastrando jogadores de futebol
    adicionarUsuario("Neymar");
    adicionarUsuario("Cristiano_Ronaldo");
    adicionarUsuario("Vinicius_Junior");
    adicionarUsuario("Halaand");
    adicionarUsuario("Luva_de_Pedreiro");
    adicionarUsuario("Messi");
    adicionarUsuario("Gabigol");
    adicionarUsuario("Rafinha");
    adicionarUsuario("Camavinga");
    adicionarUsuario("Rudiger");
    adicionarUsuario("Marcelo");
    adicionarUsuario("Casemiro");
    adicionarUsuario("Pepe");
    adicionarUsuario("Endrick");
    
    printf("\n=== CRIANDO AMIZADES ENTRE JOGADORES ===\n");
    
    // Criando amizades entre jogadores brasileiros
    criarAmizade("Neymar", "Vinicius_Junior");
    criarAmizade("Neymar", "Casemiro");
    criarAmizade("Vinicius_Junior", "Endrick");
    criarAmizade("Gabigol", "Rafinha");

    // Amizades de influencer
    criarAmizade("Luva_de_Pedreiro", "Neymar");
    criarAmizade("Luva_de_Pedreiro", "Vinicius_Junior");
    criarAmizade("Luva_de_Pedreiro", "Cristiano_Ronaldo");
    criarAmizade("Luva_de_Pedreiro", "Halaand");
    criarAmizade("Luva_de_Pedreiro", "Rafinha");
    criarAmizade("Luva_de_Pedreiro", "Rudiger");
    criarAmizade("Luva_de_Pedreiro", "Gabigol");
    
    // Amizades Real Madrid
    criarAmizade("Cristiano_Ronaldo", "Marcelo");
    criarAmizade("Cristiano_Ronaldo", "Casemiro");
    criarAmizade("Vinicius_Junior", "Camavinga");
    criarAmizade("Camavinga", "Rudiger");
    
    // Rivalidade que vira amizade
    criarAmizade("Messi", "Neymar");
    criarAmizade("Cristiano_Ronaldo", "Pepe");
    
    // Amizades internacionais
    criarAmizade("Halaand", "Rudiger");
    criarAmizade("Halaand", "Casemiro");
    
    // Testando algumas validações
    printf("\n=== TESTANDO VALIDAÇÕES ===\n");
    criarAmizade("Neymar", "Vinicius_Junior");  // Erro: já são amigos
    criarAmizade("Messi", "Messi");             // Erro: mesmo usuário
    criarAmizade("Endrick", "Ronaldinho");      // Erro: Ronaldinho não existe
    
    // Exibindo a rede completa
    exibirRedeSocial();
    
    // Exibindo estatísticas
    exibirEstatisticas();
    
    printf("\n=== AMIGOS INDIVIDUAIS ===\n");
    
    // Testando exibição individual
    exibirAmigos("Neymar");
    exibirAmigos("Cristiano_Ronaldo");
    exibirAmigos("Luva_de_Pedreiro");
    exibirAmigos("Rafinha");  // Pode ter poucos amigos
    
    printf("\n=== AMIGOS EM COMUM ===\n");
    
    // Testando amigos em comum
    amigosEmComum("Neymar", "Cristiano_Ronaldo");     // Casemiro em comum
    amigosEmComum("Vinicius_Junior", "Neymar");       // Endrick/Casemiro em comum
    amigosEmComum("Gabigol", "Luva_de_Pedreiro");     // Podem ter amigos em comum
    amigosEmComum("Messi", "Halaand");                // Talvez nenhum amigo em comum
    
    // Encerrar o sistema adequadamente
    encerrarRede();
    
    return 0;
}
