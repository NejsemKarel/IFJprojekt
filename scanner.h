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
    variable,                   // ++
    keyword,                    // ++
    integer,                    // ++
    floating,                   // ++
    semicolon,                  // ++
    comma,                      // ++
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
    T_bracket,
    T_string,
    T_separator,
    T_prolog,
    T_EOF,
    T_ERROR
}tokenType;

typedef struct token
{
    tokenType type;
    char *value;
    int lineNumber;
}*tokenPtr;

//Funkce

void getToken();        // gonna return token instead of void

AutomatState Next_State(AutomatState now, char c);

tokenType getType(AutomatState state);

tokenPtr createToken (tokenType type, char val[], int line);

int main();