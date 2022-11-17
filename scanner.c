#include <stdio.h>
#include <stdbool.h>
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

typedef struct 
{
    char tokenType;
    int value;
    
}token;

AutomatState Next_State (AutomatState now, char c)
{
    switch (now)
    {
        case start: if (c == ' ' || c == '\n') return start;
                    if (c == '$') return variable;
                    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) return keyword;
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
        case keyword:       if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || (c <= '9' && c >= '0') || c == '_') return keyword;
                            return start;
            break;
        case variable:      if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || (c <= '9' && c >= '0') || c == '_') return variable;
                            return start;
            break;
        case integer:       if (c <= '9' && c >= '0') return integer;
                            if (c == '.') return floating;
                            return start;
            break;
        case floating:      if (c <= '9' && c >= '0') return floating;
                            return start;
            break;
        case semicolon:     return start;
            break; 
        case assign:        if (c == '=') return doubleEqu;
                            return start;
            break;
        case exclMark:      if (c == '=') return exclEqu;
                            return start;
            break;
        case exclEqu:       if (c == '=') return notEqual;       
            break;
        case doubleEqu:     if (c == '=') return equal;
                            return start;
            break;
        case equal:         return start;
            break;
        case notEqual:      return start;
            break;
        case stringRead:    if (c != '"') return stringRead;
                            return string;
            break;
        case string:        return start;
            break;
        case comma:         return start;
            break;
        case Lbracket:      return start;
            break;
        case Rbracket:      return start;
            break;
        case Lcurly:        return start;
            break;
        case Rcurly:        return start;
            break;
        case Lsquare:       return start;
            break;
        case Rsquare:       return start;
            break;
        case add:           return start;
            break;
        case sub:           return start;
            break;
        case mul:           return start;
            break;
        case div:           if (c == '*') return comStart;
                            if (c == '/') return comment;
                            return start;
            break;
        case less:          if (c == '?') return prolog;
                            if (c == '=') return lessEqual;
                            return start;
            break;
        case lessEqual:     return start;
            break;
        case greater:       if (c == '=') return greaterEqual;
                            return start;
            break;
        case greaterEqual:  return start;
            break;
        case prolog:        if (c == '\n') return prologEnd;
            break;
        case prologEnd:     return start;
            break;
        case comment:       if (c == '\n') return start;
            break;
        case comStart:      if (c == '*') return comPom;
                            return comStart;
            break;
        case comPom:        if (c == '/') return comEnd;
                            return comStart;
            break;
        case comEnd:        return start;
            break;
        default:            return now;
            break;
    }
    return now;
}

int main ()
{
    AutomatState CurrentState = start;
    while (true)
    {   
        char c = getchar();
        if (c == EOF) break;
        if ((CurrentState == comment && Next_State(CurrentState, c) != start) || CurrentState == comStart || CurrentState == comPom || CurrentState == stringRead)
        {
            if ((CurrentState != Next_State(CurrentState, c)) && (Next_State(CurrentState, c) == start)) printf("\n");
            printf("%c", c);
            CurrentState = Next_State(CurrentState, c);
        }
        else if (c != ' ')
        {
            if ((CurrentState != Next_State(CurrentState, c)) && (Next_State(CurrentState, c) == start)) printf("\n");
            if (c != '\n') printf("%c", c);
            CurrentState = Next_State(CurrentState, c);
            if (CurrentState == start) CurrentState = Next_State(CurrentState, c);
        }
    }
    return 0;
}
