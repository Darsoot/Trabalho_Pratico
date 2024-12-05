#include <stdio.h>
#include "pizza.h"

Pizza pizzas[MAX_INGREDIENTES];  // Um array para armazenar as pizzas
int qtd_pizzas = 0;  // Quantidade de pizzas cadastradas

void adicionarPizza() {
    Pizza novaPizza;
    printf("Digite o nome da pizza: ");
    scanf("%s", novaPizza.nome);
    printf("Digite o tamanho da pizza (P/M/G): ");
    scanf(" %c", &novaPizza.tamanho);
    printf("Digite o preco base da pizza: ");
    scanf("%f", &novaPizza.precoBase);

    novaPizza.id = qtd_pizzas + 1;  // Gerar um ID simples para a pizza
    pizzas[qtd_pizzas] = novaPizza;
    qtd_pizzas++;

    printf("Pizza adicionada\n");
}

void listarPizzas() {
    for (int i = 0; i < qtd_pizzas; i++) {
        printf("ID: %d | Nome: %s | Tamanho: %c | Preco: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].precoBase);
    }
}

void editarPizza() {
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);
    if (id > 0 && id <= qtd_pizzas) {
        printf("Digite o novo nome da pizza: ");
        scanf("%s", pizzas[id - 1].nome);
        printf("Digite o novo tamanho da pizza (P/M/G): ");
        scanf(" %c", &pizzas[id - 1].tamanho);
        printf("Digite o novo preco da pizza: ");
        scanf("%f", &pizzas[id - 1].precoBase);
        printf("Pizza editada com sucesso!\n");
    } else {
        printf("Pizza nao encontrada.\n");
    }
}

void removerPizza() {
    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);
    if (id > 0 && id <= qtd_pizzas) {
        for (int i = id - 1; i < qtd_pizzas - 1; i++) {
            pizzas[i] = pizzas[i + 1];
        }
        qtd_pizzas--;
        printf("Pizza removida\n");
    } else {
        printf("Pizza nao encontrada.\n");
    }
}

Pizza* buscarPizzaPorId(int id) {
    if (id > 0 && id <= qtd_pizzas) {
        return &pizzas[id - 1];
    }
    return NULL;
}


