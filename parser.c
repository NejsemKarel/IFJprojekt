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

void checkProlog(tokenPtr token){
    while(token->type != T_prolog){
        err = TRUE;
        InsertLast(errs, token);
        token = getToken();
    }
    
}

int main(void){
    err = FALSE;
    Init(errs);
    Init(tokens);
    
    tokenPtr currToken = getToken();

    checkProlog(currToken);

    if(err == TRUE){
        while(errs->firstElement != NULL){
            printf("\033[0;31m");
            printf("Syntax error on line %d",errs->firstElement->data->lineNumber);
            printf("\033[0m");
        }
    }else{
        printf("\n***********************************\nAnd here you can imagine generated code\n***********************************\n");
    }
    return 0;
}