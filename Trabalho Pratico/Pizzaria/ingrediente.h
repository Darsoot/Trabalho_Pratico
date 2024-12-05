#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_NOME_INGREDIENTE 25

// Struct Ingrediente
typedef struct {
    int id;
    char nome[MAX_NOME_INGREDIENTE];
    float preco;
} Ingrediente;

// Declara��o das Fun��es CRUD Ingrediente
void adicionarIngrediente();
void listarIngredientes();
void editarIngrediente();
void removerIngrediente();
Ingrediente* buscarIngredientePorId(int id);

#endif // INGREDIENTE_H

