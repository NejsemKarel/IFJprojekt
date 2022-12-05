/*
**************************************************
* IFJ Projekt
* Soubor: parser.c
* Základ syntaktické analýzy
**************************************************
*/

#include "parser.h"

void prologCheck(tokenPtr token){
    if(token == NULL){
            emptyList = true;
            return;
        }
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
    if(!strcmp(tokens[tokenCnt]->value, "null")){
        return true;
    }
    if(tokens[tokenCnt]->type == T_identifier){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_operator){
            tokenCnt++;
            if(EXPR()){
                return true;
            }
            return false;
        }
        return true;
    }
    if(tokens[tokenCnt]->type == T_constant){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_operator){
            tokenCnt++;
            if(EXPR()){
                return true;
            }
            return false;
        }
        return true;
    }
    if(FUN()){
        if(tokens[tokenCnt]->type == T_operator){
            tokenCnt++;
            if(EXPR()){
                return true;
            }
            return false;
        }
        return true;
    }
    if(tokens[tokenCnt]->type == T_Lbracket){
        tokenCnt++;
        if(EXPR()){
            if(tokens[tokenCnt]->type == T_Rbracket){
                return true;
            }
        }
        return false;
    }
    return false;
}

bool BODY(){
    if(!strcmp(tokens[tokenCnt]->value, "return")){
        tokenCnt++;
        if(tokens[tokenCnt]->type, T_keyword){
            tokenCnt++;
            if(tokens[tokenCnt]->type == T_semicolon){
                tokenCnt++;
                return true;
            }
            return false;
        }
        if(tokens[tokenCnt]->type == T_semicolon){
            tokenCnt++;
            return true;
        }
        return false;
    }
    if(FUN()){
        if(tokens[tokenCnt]->type == T_semicolon){
            tokenCnt++;
            if(BODY()){
                return true;
            }
            return true;
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \";\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        errCnt++;
        return false
    }     
    if(VARIABLE()){
        if(BODY()){
            return true;
        }
        return true;
    } 
    if(STRUCT()){
        if(BODY()){
            return true;
        }
        return true;
    }
    

}
bool ARG(){
    if(!strcmp(tokens[tokenCnt]->value, "null")){
        return true;
    }
    if(tokens[tokenCnt]->type == T_identifier){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_comma){
            tokenCnt++;
            if(ARG()){
                return true;
            }
            return false;
        }
        return true;
    }
    if(tokens[tokenCnt]->type == T_constant){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_comma){
            tokenCnt++;
            if(ARG()){
                return true;
            }
            return false;
        }
        return true;
    }
    if(FUN()){
        if(tokens[tokenCnt]->type == T_operator){
            tokenCnt++;
            if(ARG()){
                return true;
            }
            return false;
        }
        return true;
    }

}

bool FUN(){
    if(tokens[tokenCnt]->type == T_function){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_Lbracket){
            tokenCnt++;
            if(ARG()){
                if(tokens[tokenCnt]->type == T_Rbracket){
                    tokenCnt++;
                    return true;
                }
                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \")\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                errCnt++;
                err = true;
                return false;
            }
            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected an argument\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
            errCnt++;
            err = true;
            return false;
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"(\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        errCnt++;
        err = true;
        return false;
    }
    return false;
}

bool S(){
    if(DEF()){return true;}

    if(STRUCT()){return true;}

    if(FUN()){
        if(tokens[tokenCnt]->type == T_semicolon){
            tokenCnt++;
            return true;
        }else{
            printf("\nSyntax Error: missing ; on line %d\n",tokens[tokenCnt]->lineNumber-1);
            
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
                }
                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \";\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                errCnt++;
                err = true;
                return false;
            }
            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected an expression\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
            errCnt++;
            err = true;
            return false;
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"=\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        errCnt++;
        err = true;
        return false;
    }
    return false;
}

bool FUNCTION(){
    if(!strcmp(tokens[tokenCnt]->value,"function")){
        tokenCnt++;
        if(tokens[tokenCnt]->type == T_function){
            tokenCnt++;
            if(tokens[tokenCnt]->type == T_Lbracket){
                tokenCnt++;
                if(ARG()){
                    if(tokens[tokenCnt]->type == T_Rbracket){
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
                                        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"}\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                                        errCnt++;
                                        err = true;
                                        return false;
                                    }
                                }
                                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"{\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                                errCnt++;
                                err = true;
                                return false;
                            }
                            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"data type\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                            errCnt++;
                            err = true;
                            return false;
                        }
                        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \":\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                        errCnt++;
                        err = true;
                        return false;
                    }
                    printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \")\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                    errCnt++;
                    err = true;
                    return false;
                }
                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"arguent\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                errCnt++;
                err = true;
                return false;
            }
            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"(\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
            errCnt++;
            err = true;
            return false;
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"name of the function\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        errCnt++;
        err = true;
        return false;
    }
    return false;
}

bool STRUCT(){
    if(!strcmp(tokens[tokenCnt]->value, "if")){
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
                            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"}\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                            errCnt++;
                            err = true;
                            return false;
                        }
                    }
                    printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"{\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                    errCnt++;
                    err = true;
                    return false;
                }
                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \")\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                errCnt++;
                err = true;
                return false;
            }
            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"expression\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
            errCnt++;
            err = true;
            return false;
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"(\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        errCnt++;
        err = true;
        return false;
    }
    if(!strcmp(tokens[tokenCnt]->value, "while")){
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
                            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"}\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                            errCnt++;
                            err = true;
                            return false;
                        }
                    }
                    printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"{\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                    errCnt++;
                    err = true;
                    return false;
                }
                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \")\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                errCnt++;
                err = true;
                return false;
            }
            printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"expression\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
            errCnt++;
            err = true;
            return false;
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"(\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        errCnt++;
        err = true;
        return false;
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
                printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"}\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
                errCnt++;
                err = true;
                return false;
            }
        }
        printf("\nSyntax Error: unexpected \"%s\" on line %d. Expected \"{\"\n",tokens[tokenCnt]->value,tokens[tokenCnt]->lineNumber);
        errCnt++;
        err = true;
        return false;
    }
    return false;
}
    
int main(void){
    err = false;
    errCnt = 0;
    currToken = getToken();
    prologCheck(currToken);
    if(emptyList){return 0;}
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
        /*if(!S()){
            printf("there are errors in the syntax\n");
            err = true;
        }*/

        S();
        
    }
    if(!err){
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n     there are no errors in the program     \n+++++++++++++++++++++++++++++++++++++++++++++\n\n");
    }else{
        printf("\n---------------------------------------------\n *** there are %d errors in the program *** \n---------------------------------------------\n\n",errCnt);
    }
    
    return 0;
}