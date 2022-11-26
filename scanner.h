/*
**************************************************
* IFJ Projekt
* Soubor: scanner.h
* Hlavičkový soubor pro scanner.c
**************************************************
*/

#define EOL '\n'

//Stavy
typedef enum
{
    start,
    variable,
    keyword,
    integer,
    floating,
    semicolon,
    comma,
    assign,
    doubleEqu,
    equal,
    notEqual,
    stringRead,
    string,
    Lbracket,
    Rbracket,
    Lcurly,
    Rcurly,
    Lsquare,
    Rsquare,
    mul,
    div,
    add,
    sub,
    exclMark,
    exclEqu,        // vykricnik rovnase != (mezistav pro !==)
    comment,
    comStart,
    comPom,
    comEnd,
    less,
    lessEqual,
    greater,
    greaterEqual,
    prolog,
    prologEnd
}AutomatState;

typedef enum
{
    identifier,
    constant,
    integerType,
    floatType,
    tokenEOF
}tokenType;

typedef struct 
{
    tokenType type;
    char value;
    int lineNumber;
    
}token;

//Funkce

void getToken();        // gonna return token instead of void

AutomatState Next_State(AutomatState now, char c);

int main();