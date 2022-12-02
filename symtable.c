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
void btree_body_add(btree_body_t **tree, int order, char name, char value)
{
    if((*tree) == NULL)
    {
        btree_body_t *element = malloc(sizeof(struct btree_body));
        if(element == NULL)
            return;
        element->order = order;
        element->name = name;
        element->value = value;
        element->left = NULL;
        element->right = NULL;
        (*tree) = element;
    }
    else if((*tree)->order == order)
    {
        (*tree)->name = name;
        (*tree)->value = value;
    }
    else if((*tree)->order > order)
    {
        btree_body_add(&((*tree)->left), order, name, value);
    }
    else
    {
        btree_body_add(&((*tree)->right), order, name, value);
    }
}

/*
* Vyhledá prvek v stromě
*/
bool btree_body_search(btree_body_t *tree, int order, char name, char value)
{
    if (tree == NULL)
    {
        return false;
    }
    else
    {
        if (tree->order == order)
        {
            name = tree->name;
            value = tree->value;
            return true;
        }
        else if(tree->order > order)
        {
            return btree_body_search(tree->left , order, name, value);
        }
        else
        {
            return btree_body_search(tree->right, order, name, value);
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
    else if(strSort((*tree)->name, name) == 0)
    {
        (*tree)->value = value;
    }
    else if(strSort((*tree)->name, name) > 0)
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
bool btree_variable_search(btree_variable_t *tree, char *name, char *value)
{
    if (tree == NULL)
    {
        return false;
    }
    else
    {
        if (strSort((tree)->name, name)==0)
        {
            value = tree->value;
            return true;
        }
        else if(strSort((tree)->name, name) > 0)
        {
            return btree_variable_search(tree->left , name, value);
        }
        else
        {
            return btree_variable_search(tree->right, name, value);
        }
    }
}

/*
* Sort hodnot podle abecedy
* -position val1 < val2    0 val1 == val2    +position val1 > val2
*/
 
int strSort (char *val1, char *val2)		
{
	int i = 0;
	while (true)
	{
		if (val1[i] < val2[i])
		{
			return (-i-1);
		}
		else if (val1[i] > val2[i])
		{
			return i+1;
		}
		i++;
	}
	return 0;
}

int main(void){
    return 0;
}