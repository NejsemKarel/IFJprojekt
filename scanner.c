#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define EOL '\n'

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
    comEnd,
    less,
    lessEqual,
    greater,
    greaterEqual,
    prolog
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
                    if (c <= '9' && c >= '0') return integer;
                    if (c == ';') return semicolon;
                    if (c == '=') return assign;
                    if (c == '!') return exclMark;
                    if (c == '"') return stringRead;
                    if (c == ',') return comma;
                    if (c == '(') return Lbracket;
                    if (c == ')') return Rbracket;
                    if (c == '{') return Lcurly;
                    if (c == '}') return Rcurly;
                    if (c == '[') return Lsquare;
                    if (c == ']') return Rsquare;
                    if (c == '+') return add;
                    if (c == '-') return sub;
                    if (c == '*') return mul;
                    if (c == '/') return div;
                    if (c == '<') return less;
                    if (c == '>') return greater;
            break;
        case keyword:       if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A' || c <= '9' && c >= '0') return keyword;
                            return Next_State(start, c);
            break;
        case variable:      if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A' || c <= '9' && c >= '0' || c == '_') return variable;
                            return Next_State(start, c);
            break;
        case integer:       if (c <= '9' && c >= '0') return integer;
                            if (c == '.') return floating;
                            return Next_State(start, c);
            break;
        case floating:      if (c <= '9' && c >= '0') return floating;
                            return Next_State(start, c);
            break;
        case semicolon:     return Next_State(start, c);
            break; 
        case assign:        if (c == '=') return doubleEqu;
                            return Next_State(start, c);
            break;
        case exclMark:      if (c == '=') return exclEqu;
                            return Next_State(start, c);
            break;
        case exclEqu:       if (c == '=') return notEqual;       
            break;
        case doubleEqu:     if (c == '=') return equal;
                            return Next_State(start, c);
            break;
        case equal:         return Next_State(start, c);
            break;
        case notEqual:      return Next_State(start, c);
            break;
        case stringRead:    if (c == '"') return Next_State(start, c);
            break;
        case comma:         return Next_State(start, c);
            break;
        case Lbracket:      return Next_State(start, c);
            break;
        case Rbracket:      return Next_State(start, c);
            break;
        case Lcurly:        return Next_State(start, c);
            break;
        case Rcurly:        return Next_State(start, c);
            break;
        case Lsquare:       return Next_State(start, c);
            break;
        case Rsquare:       return Next_State(start, c);
            break;
        case add:           return Next_State(start, c);
            break;
        case sub:           return Next_State(start, c);
            break;
        case mul:           return Next_State(start, c);
            break;
        case div:           if (c == '*') return comStart;
                            if (c == '/') return comment;
                            return Next_State(start, c);
            break;
        case less:          if (c == '?') return prolog;
                            if (c == '=') return lessEqual;
                            return Next_State(start, c);
            break;
        case lessEqual:     return Next_State(start, c);
            break;
        case greater:       if (c == '=') return greaterEqual;
                            return Next_State(start, c);
            break;
        case greaterEqual:  return Next_State(start, c);
            break;
        case prolog:        return Next_State(start, c);
            break;
        case comment:       if (c == EOL) return start; 
        case comStart:      if (c == '*') return comEnd;
                            return comStart;
            break;
        case comEnd:        if (c == '/') return start;
                            return comStart;
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
