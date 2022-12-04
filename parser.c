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
void tokenPrint(tokenPtr token){
    
        
        if (token == NULL) return;
        switch (token->type)
        {
        case T_identifier:
            printf("type:\tT_identifier\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_constant:
            printf("type:\tT_constant\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_integer:
            printf("type:\tT_integer\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_float:
            printf("type:\tT_float\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_operator:
            printf("type:\tT_operator\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_assignment:
            printf("type:\tT_assignment\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_keyword:
            printf("type:\tT_keyword\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_Lbracket:
            printf("type:\tT_Lbracket\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_Rbracket:
            printf("type:\tT_Rbracket\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_Lsquare:
            printf("type:\tT_Lsquare\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_Rsquare:
            printf("type:\tT_Rsquare\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_Lcurly:
            printf("type:\tT_Lcurly\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_Rcurly:
            printf("type:\tT_Rcurly\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_string:
            printf("type:\tT_string\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_semicolon:
            printf("type:\tT_semicolon\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_colon:
            printf("type:\tT_colon\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_comma:
            printf("type:\tT_comma\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_dot:
            printf("type:\tT_dot\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_prolog:
            printf("type:\tT_prolog\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        case T_ERROR:
            printf("type:\tT_ERROR\n");
            printf("value:\t%s\n", token->value);
            printf("line:\t%d\n\n", token->lineNumber);
            break;
        default:
            break;
        }
    
}

    
int main(void){
    err = false;
    currToken = getToken();
    prologCheck(currToken);
    currToken = getToken();
    while (currToken != NULL){
        i = 0;
        while (currToken != NULL){
            
            //tokenPrint(currToken);
            tokens[i] = currToken;
            i++;
            currToken = getToken();
            if(currToken->type != T_semicolon && currToken->type != T_Rcurly){
                tokens[i] = currToken;
                break;
            }
            
        }
        while (i >= 0){
            tokenPrint(tokens[i]);
            i--;
        }
        printf("-----------------------------\n");
        
    }
    
    return 0;
}