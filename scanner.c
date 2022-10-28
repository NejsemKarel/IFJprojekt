#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef enum
{
    start,
    variable,
    functionID,
    semicolon,
    assign,
    stringRead,
    stringEnd,
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
                if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A') return functionID;
                if (c == ';') return semicolon;
                if (c == '"') return stringRead;
                if (c == '(') return Lbracket;
                if (c == ')') return Rbracket;
        break;
    case functionID:    if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A' || c <= '9' && c >= '0') return functionID;
        break;
    case variable:      if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A' || c <= '9' && c >= '0' || c == '_') return variable;
        break;
    case semicolon:     return start;
        break; 
    case assign:
        break;
    case stringRead:   if (c == '"') return stringEnd;
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
        CurrentState = Next_State(CurrentState, c);
    }
    return 0;
}
