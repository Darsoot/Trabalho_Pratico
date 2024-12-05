#include <stdio.h>
#include "pizza.h"
#include "ingrediente.h"

// Função para exibir o menu de ingredientes
void menuIngredientes() {
    int opcao;
    do {
        printf("\n----- Menu Ingredientes -----\n");
        printf("1. Adicionar Ingrediente\n");
        printf("2. Listar Ingredientes\n");
        printf("3. Editar Ingrediente\n");
        printf("4. Remover Ingrediente\n");
        printf("0. Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarIngrediente(); break;
            case 2: listarIngredientes(); break;
            case 3: editarIngrediente(); break;
            case 4: removerIngrediente(); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opcao invalida\n");
        }
    } while (opcao != 0);
}

// Função para exibir o menu de pizzas
void menuPizzas() {
    int opcao;
    do {
        printf("\n----- Menu Pizzas -----\n");
        printf("1. Adicionar Pizza\n");
        printf("2. Listar Pizzas\n");
        printf("3. Editar Pizza\n");
        printf("4. Remover Pizza\n");
        printf("0. Voltar\n");
        printf("\nEscolha uma opcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarPizza(); break;
            case 2: listarPizzas(); break;
            case 3: editarPizza(); break;
            case 4: removerPizza(); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opcao invalida\n");
        }
    } while (opcao != 0);
}

// Função para registrar uma venda
void registrarVenda() {
    int pizzaId, ingredienteExtraId, continuar = 1;
    float precoFinal = 0.0;

    printf("\n----- Registrar Venda -----\n");
    listarPizzas();
    printf("Selecione o ID da pizza desejada: ");
    scanf("%d", &pizzaId);

    Pizza* pizza = buscarPizzaPorId(pizzaId);
    if (pizza == NULL) {
        printf("Pizza nao encontrada\n");
        return;
    }

    precoFinal = pizza->precoBase;
    printf("\nPizza selecionada: %s | Preco base: %.2f\n", pizza->nome, pizza->precoBase);

    do {
        listarIngredientes();
        printf("Adicione o ID do ingrediente extra (0 para finalizar): ");
        scanf("%d", &ingredienteExtraId);

        if (ingredienteExtraId == 0) {
            continuar = 0;
        } else {
            Ingrediente* ingrediente = buscarIngredientePorId(ingredienteExtraId);
            if (ingrediente != NULL) {
                precoFinal += ingrediente->preco;
                printf("Ingrediente %s adicionado, preco atual: %.2f\n", ingrediente->nome, precoFinal);
            } else {
                printf("Ingrediente nao encontrado\n");
            }
        }
    } while (continuar);

    printf("\nVenda finalizada, preco total: %.2f\n", precoFinal);
}

int main() {
    int opcao;
    do {
        printf("\n===== Sistema de Gerenciamento de Pizzaria =====\n");
        printf("1. Menu de Ingredientes\n");
        printf("2. Menu de Pizzas\n");
        printf("3. Registrar Venda\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menuIngredientes(); break;
            case 2: menuPizzas(); break;
            case 3: registrarVenda(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}

