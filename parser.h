/*
**************************************************
* IFJ Projekt
* Soubor: parser.h
* Hlavičkový soubor pro parser.c
**************************************************
*/

#include "scanner.h"
//#include "symtable.h"
//#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


tokenPtr tokens[100];
tokenPtr currToken;
tokenPtr prevToken;

int i;
bool err;



bool isItAKeyword (tokenPtr token);
void prologCheck(tokenPtr token);
int main();