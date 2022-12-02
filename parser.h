/*
**************************************************
* IFJ Projekt
* Soubor: parser.h
* Hlavičkový soubor pro parser.c
**************************************************
*/

#include "scanner.h"
#include "symtable.h"
#include "dll.h"
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

int err;

bool isItAKeyword (tokenPtr token);
int main();