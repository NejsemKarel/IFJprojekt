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

#define DEBUG (tokenPrint(tokens[tokenCnt]));


tokenPtr tokens[100];
tokenPtr currToken;
tokenPtr prevToken;

int i;
bool err;
int tokenCnt;
bool emptyList;
int errCnt;

void prologCheck(tokenPtr token);
bool S();
bool DEF();
bool VARIABLE();
bool EXPR();
bool FUNCTION();
bool BODY();
bool STRUCT();
bool FUN();
bool AGR();



int main();