/*
**************************************************
* IFJ Projekt
* Soubor: parser.h
* Hlavičkový soubor pro parser.c
**************************************************
*/

#include "scanner.h"
#include "symtable.h"
#include <string.h>
#include <stdbool.h>

bool isItAKeyword (tokenPtr token);