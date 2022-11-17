/*
**************************************************
* IFJ Projekt
* Soubor: btree.h
* Hlavičkový soubor pro btree.c
**************************************************
*/


// Uzel
typedef struct btree_node {
  char ident;           // identifikátor
  int order;            // pořadí
  char value;           // řetězec znaků/hodnota
  struct btree_node *left;      // ukazatel na levý prvek
  struct btree_node *right;     // ukazatel na pravý prvek
} btree_node_t;

// Funkce

void btree_init(btree_node_t **tree);
void btree_dispose(btree_node_t **tree)

void btree_add(btree_node_t **tree, int order, char ident, char value);
void btree_delete(btree_node_t **tree, int order);

bool btree_search(btree_node_t *tree, int order, char ident, char value);

void btree_RBRM(btree_node_t *target, btree_node_t **tree);