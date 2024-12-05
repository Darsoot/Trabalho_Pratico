#include <stdio.h>
#include "ingrediente.h"

Ingrediente ingredientes[MAX_NOME_INGREDIENTE];  // Um array para armazenar os ingredientes
int qtd_ingredientes = 0;  // Quantidade de ingredientes cadastrados

void adicionarIngrediente() {
    Ingrediente novoIngrediente;
    printf("Digite o nome do ingrediente: ");
    scanf("%s", novoIngrediente.nome);
    printf("Digite o preco do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    novoIngrediente.id = qtd_ingredientes + 1;  // Gerar um ID simples para o ingrediente
    ingredientes[qtd_ingredientes] = novoIngrediente;
    qtd_ingredientes++;

    printf("Ingrediente adicionado\n");
}

void listarIngredientes() {
    for (int i = 0; i < qtd_ingredientes; i++) {
        printf("ID: %d | Nome: %s | Preco: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

void editarIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);
    if (id > 0 && id <= qtd_ingredientes) {
        printf("Digite o novo nome do ingrediente: ");
        scanf("%s", ingredientes[id - 1].nome);
        printf("Digite o novo preco do ingrediente: ");
        scanf("%f", &ingredientes[id - 1].preco);
        printf("Ingrediente editado\n");
    } else {
        printf("Ingrediente nao encontrado.\n");
    }
}

void removerIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);
    if (id > 0 && id <= qtd_ingredientes) {
        for (int i = id - 1; i < qtd_ingredientes - 1; i++) {
            ingredientes[i] = ingredientes[i + 1];
        }
        qtd_ingredientes--;
        printf("Ingrediente removido\n");
    } else {
        printf("Ingrediente nao encontrado.\n");
    }
}

Ingrediente* buscarIngredientePorId(int id) {
    if (id > 0 && id <= qtd_ingredientes) {
        return &ingredientes[id - 1];
    }
    return NULL;
}

