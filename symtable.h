/*
**************************************************
* IFJ Projekt
* Soubor: symtable.h
* Hlavičkový soubor pro symtable.c
**************************************************
*/
 #include <stdbool.h>

// Body struct - seznam hlavniho tela funkci a promennych

typedef struct btree_body {
  char name;           // identifikátor
  int order;            // pořadí
  char value;           // řetězec znaků/hodnota
  struct btree_body *left;      // ukazatel na levý prvek
  struct btree_body *right;     // ukazatel na pravý prvek
} btree_body_t;

void btree_body_init(btree_body_t **tree);
void btree_body_dispose(btree_body_t **tree);
void btree_body_add(btree_body_t **tree, int order, char name, char value);
bool btree_body_search(btree_body_t *tree, int order, char name, char value);



// Variable struct

typedef struct btree_variable {
  char *name;           // identifikátor
  char *value;           // řetězec znaků/hodnota
  struct btree_variable *left;      // ukazatel na levý prvek
  struct btree_variable *right;     // ukazatel na pravý prvek
} btree_variable_t;

void btree_variable_init(btree_variable_t **tree);
void btree_variable_dispose(btree_variable_t **tree);
void btree_variable_add(btree_variable_t **tree, char *name, char *value);
bool btree_variable_search(btree_variable_t *tree, char *name, char *value);

int strSort (char *val1, char *val2);