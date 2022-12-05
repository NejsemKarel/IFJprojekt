/*
**************************************************
* IFJ Projekt
* Soubor: scanner.h
* Hlavičkový soubor pro scanner.c
**************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define EOL '\n'

//Stavy
typedef enum
{
    start,
    errorState,
    variable,                   // ++
    keyword,                    // ++
    integer,                    // ++
    floating,                   // ++
    semicolon,                  // ++
    comma,                      // ++
    dot,
    colon,
    assign,                     
    doubleEqu,
    equal,
    notEqual,                   // op
    stringRead,
    string,                     // ++
    Lbracket,
    Rbracket,
    Lcurly,
    Rcurly,
    Lsquare,
    Rsquare,                    // bracket
    mul,                        // op
    divide,                        // op
    add,                        // op
    sub,                        // op
    exclMark,
    exclEqu,        // vykricnik rovnase != (mezistav pro !==)
    comment,
    comStart,
    comPom,
    comEnd,
    less,                       // op
    lessEqual,                  // op
    greater,                    // op
    greaterEqual,               // op
    prolog,
    prologEnd                   // ++
}AutomatState;

typedef enum
{
    T_identifier,
    T_constant,
    T_integer,
    T_float,
    T_operator,
    T_keyword,
    T_function,
    T_Lbracket,
    T_Rbracket,
    T_Lsquare,
    T_Rsquare,
    T_Lcurly,
    T_Rcurly,
    T_string,
    T_assignment,
    T_semicolon,
    T_colon,
    T_comma,
    T_dot,
    T_prolog,
    T_ERROR
}tokenType;

typedef struct token
{
    tokenType type;
    char *value;
    int lineNumber;
}*tokenPtr;

//Funkce

tokenPtr getToken();

AutomatState Next_State(AutomatState now, char c);

tokenType getType(AutomatState state);

tokenPtr createToken (tokenType type, char val[], int line);

void tokenPrint(tokenPtr token);

bool isItAKeyword (tokenPtr token);

int main();