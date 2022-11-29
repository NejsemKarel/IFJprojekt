/*
**************************************************
* IFJ Projekt
* Soubor: symtable.h
* Hlavičkový soubor pro symtable.c
**************************************************
*/
 #include <stdbool.h>

// Function struct

typedef struct btree_function {
  char ident;           // identifikátor
  int order;            // pořadí
  char value;           // řetězec znaků/hodnota
  struct btree_function *left;      // ukazatel na levý prvek
  struct btree_function *right;     // ukazatel na pravý prvek
} btree_function_t;

void btree_function_init(btree_function_t **tree);
void btree_function_dispose(btree_function_t **tree);
void btree_function_add(btree_function_t **tree, int order, char ident, char value);
bool btree_function_search(btree_function_t *tree, int order, char ident, char value);



// Variable struct

typedef struct btree_variable {
  char ident;           // identifikátor
  int order;            // pořadí
  char value;           // řetězec znaků/hodnota
  struct btree_variable *left;      // ukazatel na levý prvek
  struct btree_variable *right;     // ukazatel na pravý prvek
} btree_variable_t;

void btree_variable_init(btree_variable_t **tree);
void btree_variable_dispose(btree_variable_t **tree);
void btree_variable_add(btree_variable_t **tree, int order, char ident, char value);
bool btree_variable_search(btree_variable_t *tree, int order, char ident, char value);



// Program

typedef struct btree_program {
  char ident;           // identifikátor
  int order;            // pořadí
  char value;           // řetězec znaků/hodnota
  struct btree_program *left;      // ukazatel na levý prvek
  struct btree_program *right;     // ukazatel na pravý prvek
} btree_program_t;

void btree_program_init(btree_program_t **tree);
void btree_program_dispose(btree_program_t **tree);
void btree_program_add(btree_program_t **tree, int order, char ident, char value);
bool btree_program_search(btree_program_t *tree, int order, char ident, char value);

