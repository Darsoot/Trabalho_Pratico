#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

#define MAX_INGREDIENTES 20
#define MAX_NOME 50

// Struct Pizza
typedef struct {
    int id;
    char nome[MAX_NOME];
    char tamanho; // ('P', 'M', 'G')
    float precoBase;
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int qtd_ingredientes; // Quantidade atual de ingredientes
} Pizza;

// Declaração das Funções CRUD Pizza
void adicionarPizza();
void listarPizzas();
void editarPizza();
void removerPizza();
Pizza* buscarPizzaPorId(int id);

#endif // PIZZA_H

