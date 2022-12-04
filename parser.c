/*
**************************************************
* IFJ Projekt
* Soubor: parser.c
* Základ syntaktické analýzy
**************************************************
*/

#include "parser.h"

void prologCheck(tokenPtr token){
    if(token->type != T_prolog){
        printf("\033[0;31m");
        printf("\nSyntax Error on line %d in %s: ",token->lineNumber, token->value);
        printf("\033[0m");
        printf("expecting prolog\n\n");
        err = true;
        return;
    }
    
}
    
int main(void){
    err = false;
    currToken = getToken();
    prologCheck(currToken);
    while (currToken != NULL){
        i = 0;
        while (currToken != NULL){
            if((currToken->type == T_prolog) || (currToken->type == T_semicolon) || (currToken->type == T_Rcurly))
            {   
                tokens[i] = currToken;
                currToken = getToken();
                break;
            }
            tokens[i] = currToken;
            currToken = getToken();
            i++;
        }
        for (int m = 0; m <= i; m++){
            printf("%d\n",m);
            tokenPrint(tokens[m]);
        }
        printf("-----------------------------\n");
        
    }
    
    return 0;
}