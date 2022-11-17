/*
**************************************************
* IFJ Projekt
* Soubor: btree.c
* Funkce pro binární vyhledávací strom
**************************************************
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

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
* Nahradí prvek nejpravějším potomkem
*/
void btree_RBRM(btree_node_t *target, btree_node_t **tree)
{
    if ((*tree) != NULL)
    {
        if((*tree)->right == NULL)
        {
            target->order = (*tree)->order;
            target->ident = (*tree)->ident;
            target->value = (*tree)->value;
        }
        else
        {
            btree_RBRM(target, &(*tree)->right);
        }
    }
    
}


/*
* Odebrání prvku ze stromu
*/
void btree_delete(btree_node_t **tree, int order);
{
    //TODO
}


/*
* Vyhledá prvek v stromě
*/
bool btree_search(btree_node_t *tree, int order, char ident, char value);
{
    //TODO
}