#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef enum
{
    start,
    variable,
    keyword,
    semicolon,
    assign,
    doubleEqu,
    equal,
    notEqual,
    stringRead,
    Lbracket,
    Rbracket
}AutomatState;

typedef struct 
{
    char tokenType;
    int value;
    
}token;

AutomatState Next_State (AutomatState now, char c)
{
    switch (now)
    {
        case start: if (c == '$') return variable;
                    if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A') return keyword;
                    if (c == ';') return semicolon;
                    if (c == '=') return assign;
                    if (c == '"') return stringRead;
                    if (c == '(') return Lbracket;
                    if (c == ')') return Rbracket;
            break;
        case keyword:       if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A' || c <= '9' && c >= '0') return keyword;
            break;
        case variable:      if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A' || c <= '9' && c >= '0' || c == '_') return variable;
            break;
        case semicolon:     return Next_State(start, c);;
            break; 
        case assign:        if (c == '=') return doubleEqu;
                            else return Next_State(start, c);;
            break;
        case doubleEqu:     if (c == '=') return equal;
                            else if (c == '!') return notEqual;
                            else return Next_State(start, c);;
            break;
        case equal:         return Next_State(start, c);
            break;
        case notEqual:     return Next_State(start, c);
            break;
        case stringRead:   if (c == '"') return Next_State(start, c);
            break;
        default:
            break;
    }
}

int main ()
{
    AutomatState CurrentState = start;
    while (TRUE)
    {
        char c = getchar();
        if (c == EOF) break;
        CurrentState = Next_State(CurrentState, c);
    }
    return 0;
}
