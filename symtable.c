/*
**************************************************
* IFJ Projekt
* Soubor: symtable.c
* Funkce pro binární vyhledávací strom
**************************************************
*/

#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* Inicializace stromu
*/
void btree_init(btree_node_t **tree)
{
    *tree = NULL;
}


/*
* Vymazání celého stromu
*/
void btree_dispose(btree_node_t **tree)
{
    if((*tree) != NULL){
    btree_dispose(&(*tree)->right);
    btree_dispose(&(*tree)->left);
    free((*tree));
    (*tree) = NULL;
  }
}


/*
* Přidání prvku do stromu
*/
void btree_add(btree_node_t **tree, int order, char ident, char value)
{
    if((*tree) == NULL)
    {
        btree_node_t *element = malloc(sizeof(struct btree_node));
        if(element == NULL)
            return;
        element->order = order;
        element->ident = ident;
        element->value = value;
        element->left = NULL;
        element->right = NULL;
        (*tree) = element;
    }
    else if((*tree)->order == order)
    {
        (*tree)->ident = ident;
        (*tree)->value = value;
    }
    else if((*tree)->order > order)
    {
        btree_add(&((*tree)->left), order, ident, value);
    }
    else
    {
        btree_add(&((*tree)->right), order, ident, value);
    }
}

/*
* Vyhledá prvek v stromě
*/
bool btree_search(btree_node_t *tree, int order, char ident, char value)
{
    if (tree == NULL)
    {
        return false;
    }
    else
    {
        if (tree->order == order)
        {
            ident = tree->ident;
            value = tree->value;
            return true;
        }
        else if(tree->order > order)
        {
            return btree_search(tree->left , order, ident, value);
        }
        else
        {
            return btree_search(tree->right, order, ident, value);
        }
    }
}
