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






// BODY BTREE


/*
* Inicializace stromu
*/
void btree_body_init(btree_body_t **tree)
{
    *tree = NULL;
}


/*
* Vymazání celého stromu
*/
void btree_body_dispose(btree_body_t **tree)
{
    if((*tree) != NULL){
    btree_body_dispose(&(*tree)->right);
    btree_body_dispose(&(*tree)->left);
    free((*tree));
    (*tree) = NULL;
  }
}


/*
* Přidání prvku do stromu
*/
void btree_body_add(btree_body_t **tree, char *name, char *value)
{
    if((*tree) == NULL)
    {
        btree_body_t *element = malloc(sizeof(struct btree_body));
        if(element == NULL)
            return;
        element->name = name;
        element->value = value;
        element->left = NULL;
        element->right = NULL;
        (*tree) = element;
    }
    else if((*tree)->name == name)
    {
        (*tree)->value = value;
    }
    else if((*tree)->name > name)
    {
        btree_body_add(&((*tree)->left), name, value);
    }
    else
    {
        btree_body_add(&((*tree)->right), name, value);
    }
}

/*
* Vyhledá prvek v stromě
*/
bool btree_body_search(btree_body_t *tree, char *name, char **value)
{
    if (tree == NULL)
    {
        return false;
    }
    else
    {
        if (tree->name == name)
        {
            *value = tree->value;
            return true;
        }
        else if(tree->name > name)
        {
            return btree_body_search(tree->left , name, value);
        }
        else
        {
            return btree_body_search(tree->right, name, value);
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
void btree_variable_add(btree_variable_t **tree, char *name, char *value)
{
    if((*tree) == NULL)
    {
        btree_variable_t *element = malloc(sizeof(struct btree_variable));
        if(element == NULL)
            return;
        element->name = name;
        element->value = value;
        element->left = NULL;
        element->right = NULL;
        (*tree) = element;
    }
    else if((*tree)->name == name)
    {
        (*tree)->value = value;
    }
    else if((*tree)->name > name)
    {
        btree_variable_add(&((*tree)->left), name, value);
    }
    else
    {
        btree_variable_add(&((*tree)->right), name, value);
    }
}

/*
* Vyhledá prvek v stromě
*/
bool btree_variable_search(btree_variable_t *tree, char *name, char **value)
{
    if (tree == NULL)
    {
        return false;
    }
    else
    {
        if (tree->name == name)
        {
            *value = tree->value;
            return true;
        }
        else if(tree->name > name)
        {
            return btree_variable_search(tree->left , name, value);
        }
        else
        {
            return btree_variable_search(tree->right, name, value);
        }
    }
}

btree_variable_t *strom;
int main()
{
    char *kuk = "ano";
    char *neco = kuk;

    char *result;
    btree_variable_init(&strom);
    btree_variable_add(&strom, "ahoj12", "1");
    btree_variable_add(&strom, "ahoj11", neco);
    btree_variable_add(&strom, "ahojda", "4");
    btree_variable_add(&strom, "ahojky", "3");
    btree_variable_add(&strom, "ahoj13", "5");


    btree_variable_search(strom, "ahoj11", &result);
    printf("%s\n",result);
 



    return 0;


}