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

bool EXPR(){
    return true;
}

bool BODY(){
    return true;
}
bool ARG(){
    return true;
}

bool FUN(){
    if(tokens[tokenCnt]->type == T_keyword && !isItAKeyword(tokens[tokenCnt])){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_Lbracket){
            tokenCnt++;
            if(ARG()){
                if(tokens[tokenCnt]->type == T_Rbracket){
                    tokenCnt++;
                    return true;
                }
                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \")\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
            }
            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected argument\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"(\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
    }
    return false;
}

bool S(){
    //if(DEF()){return true;}

    //if(STRUCT()){return true;}

    if(FUN()){
        if(tokens[tokenCnt]->type == T_semicolon){
            tokenCnt++;
            return true;
        }else{
            printf("\nSyntax Error: missing ; on line %d\n",tokens[tokenCnt]->lineNumber);
            
        }
    }
    return false;
}

bool DEF(){
    if(VARIABLE()){return true;}

    if(FUNCTION()){return true;}

    return false;
}

bool VARIABLE(){
    if(tokens[tokenCnt]->type == T_identifier){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_assignment){
            tokenCnt++;
            if(EXPR()){
                if(tokens[tokenCnt]->type == T_semicolon){
                    tokenCnt++;
                    return true;
                }else{
                    printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \";\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                }
            }
        }else{
            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"=\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
            return false;
        }
    }
    return false;
}

bool FUNCTION(){
    if(!strcmp(tokens[tokenCnt]->value,"function")){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_keyword && !isItAKeyword(tokens[tokenCnt])){
            tokenCnt++;
            if(tokens[tokenCnt]->type == T_Rbracket){
                tokenCnt++;
                if(ARG()){
                    if(tokens[tokenCnt]->type == T_Lbracket){
                        tokenCnt++;
                        if(tokens[tokenCnt]->type == T_colon){
                            tokenCnt++;
                            if((!strcmp(tokens[tokenCnt]->value,"int")) || (!strcmp(tokens[tokenCnt]->value,"float")) || (!strcmp(tokens[tokenCnt]->value,"double")) || (!strcmp(tokens[tokenCnt]->value,"char")) || (!strcmp(tokens[tokenCnt]->value,"string"))){
                                tokenCnt++;
                                if(tokens[tokenCnt]->type == T_Lcurly){
                                    tokenCnt++;
                                    if(BODY()){
                                        if(tokens[tokenCnt]->type == T_Rcurly){
                                            tokenCnt++;
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool STRUCT(){
    if((!strcmp(tokens[tokenCnt]->value, "if")) || (!strcmp(tokens[tokenCnt]->value, "while"))){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_Lbracket){
            tokenCnt++;
            if(EXPR()){
                if(tokens[tokenCnt]->type == T_Rbracket){
                    tokenCnt++;
                    if(tokens[tokenCnt]->type == T_Lcurly){
                        tokenCnt++;
                        if(BODY()){
                            if(tokens[tokenCnt]->type == T_Rcurly){
                                tokenCnt++;
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(!strcmp(tokens[tokenCnt]->value, "else")){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_Lcurly){
            tokenCnt++;
            if(BODY()){
                if(tokens[tokenCnt]->type == T_Rcurly){
                    tokenCnt++;
                    return true;
                }
            }
                    
        }
    }
    return false;
}
    
int main(void){
    err = false;
    currToken = getToken();
    prologCheck(currToken);
    currToken = getToken();
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
        /*for (int m = 0; m <= i; m++){
            printf("%d\n",m);
            tokenPrint(tokens[m]);
        }
        printf("-----------------------------\n");*/
        
        tokenCnt = 0;
        /*f (!S()){
            printf("there are errors in the syntax\n");
        }*/

        S();
        
    }
    
    return 0;
}