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






// FUNCTION BTREE


/*
* Inicializace stromu
*/
void btree_function_init(btree_function_t **tree)
{
    *tree = NULL;
}


/*
* Vymazání celého stromu
*/
void btree_function_dispose(btree_function_t **tree)
{
    if((*tree) != NULL){
    btree_function_dispose(&(*tree)->right);
    btree_function_dispose(&(*tree)->left);
    free((*tree));
    (*tree) = NULL;
  }
}


/*
* Přidání prvku do stromu
*/
void btree_function_add(btree_function_t **tree, int order, char ident, char value)
{
    if((*tree) == NULL)
    {
        btree_function_t *element = malloc(sizeof(struct btree_function));
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
        btree_function_add(&((*tree)->left), order, ident, value);
    }
    else
    {
        btree_function_add(&((*tree)->right), order, ident, value);
    }
}

/*
* Vyhledá prvek v stromě
*/
bool btree_function_search(btree_function_t *tree, int order, char ident, char value)
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
            return btree_function_search(tree->left , order, ident, value);
        }
        else
        {
            return btree_function_search(tree->right, order, ident, value);
        }
    }
}











// VARIABLE BTREE


/*
* Inicializace stromu
*/
void btree_variable_init(btree_variable_t **tree)
{
    *tree = NULL;
}


/*
* Vymazání celého stromu
*/
void btree_variable_dispose(btree_variable_t **tree)
{
    if((*tree) != NULL){
    btree_variable_dispose(&(*tree)->right);
    btree_variable_dispose(&(*tree)->left);
    free((*tree));
    (*tree) = NULL;
  }
}


/*
* Přidání prvku do stromu
*/
void btree_variable_add(btree_variable_t **tree, int order, char ident, char value)
{
    if((*tree) == NULL)
    {
        btree_variable_t *element = malloc(sizeof(struct btree_variable));
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
        btree_variable_add(&((*tree)->left), order, ident, value);
    }
    else
    {
        btree_variable_add(&((*tree)->right), order, ident, value);
    }
}

/*
* Vyhledá prvek v stromě
*/
bool btree_variable_search(btree_variable_t *tree, int order, char ident, char value)
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
            return btree_variable_search(tree->left , order, ident, value);
        }
        else
        {
            return btree_variable_search(tree->right, order, ident, value);
        }
    }
}











// PROGRAM BTREE

/*
* Inicializace stromu
*/
void btree_program_init(btree_program_t **tree)
{
    *tree = NULL;
}


/*
* Vymazání celého stromu
*/
void btree_program_dispose(btree_program_t **tree)
{
    if((*tree) != NULL){
    btree_program_dispose(&(*tree)->right);
    btree_program_dispose(&(*tree)->left);
    free((*tree));
    (*tree) = NULL;
  }
}


/*
* Přidání prvku do stromu
*/
void btree_program_add(btree_program_t **tree, int order, char ident, char value)
{
    if((*tree) == NULL)
    {
        btree_program_t *element = malloc(sizeof(struct btree_program));
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
        btree_program_add(&((*tree)->left), order, ident, value);
    }
    else
    {
        btree_program_add(&((*tree)->right), order, ident, value);
    }
}

/*
* Vyhledá prvek v stromě
*/
bool btree_program_search(btree_program_t *tree, int order, char ident, char value)
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
            return btree_program_search(tree->left , order, ident, value);
        }
        else
        {
            return btree_program_search(tree->right, order, ident, value);
        }
    }
}