/*
**************************************************
* IFJ Projekt
* Soubor: parser.c
* Základ syntaktické analýzy
**************************************************
*/

#include "parser.h"

bool isItAKeyword (tokenPtr token)
{
    if (token->type != T_keyword) return false;       // redundant
    if (!strcmp(token->value, "else")) return true;
    if (!strcmp(token->value, "float")) return true;
    if (!strcmp(token->value, "function")) return true;
    if (!strcmp(token->value, "if")) return true;
    if (!strcmp(token->value, "int")) return true;
    if (!strcmp(token->value, "null")) return true;
    if (!strcmp(token->value, "return")) return true;
    if (!strcmp(token->value, "string")) return true;
    if (!strcmp(token->value, "void")) return true;
    if (!strcmp(token->value, "while")) return true;
    return false;
}

void Error(){
    printf("Error ocured in parser.c");
    err = TRUE;
}

int main(void){
    
    tokenPtr firstToken = getToken();

    //if(firstToken->type == prolog){}
    return 0;
}