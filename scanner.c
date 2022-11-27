/*
**************************************************
* IFJ Projekt
* Soubor: scanner.c
* Část lexikální analýzy
**************************************************
*/

#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#include "btree.c"      // include binární vyhledávací strom

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
                    if (c == '/') return divide;
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
        case divide:           if (c == '*') return comStart;
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

tokenType getType(AutomatState state)
{
    switch (state)
    {
    case keyword:       return T_keyword;
        break;
    case variable:      return T_identifier;
        break;
    case integer:       return T_integer;
        break;
    case floating:      return T_float;
        break;
    case semicolon:     return T_separator;
        break;
    case assign:        return T_operator;
        break;
    case exclMark:      return T_operator;
        break;
    case doubleEqu:     return T_operator;
        break;
    case equal:         return T_operator;
        break;
    case notEqual:      return T_operator;
        break;
    case string:        return T_string;
        break;
    case comma:         return T_separator;
        break;
    case Lbracket:      return T_bracket;
        break;
    case Rbracket:      return T_bracket;
        break;
    case Lcurly:        return T_bracket;
        break;
    case Rcurly:        return T_bracket;
        break;
    case Lsquare:       return T_bracket;
        break;
    case Rsquare:       return T_bracket;
        break;
    case add:           return T_operator;
        break;
    case sub:           return T_operator;
        break;
    case mul:           return T_operator;
        break;
    case divide:        return T_operator;
        break;
    case less:          return T_operator;
        break;
    case lessEqual:     return T_operator;
        break;
    case greater:       return T_operator;
        break;
    case greaterEqual:  return T_operator;
        break;
    case prologEnd:     return T_prolog;
        break;
    default:            return T_ERROR;
        break;          // no case for EOF (might not be needed)
    }
}

tokenPtr createToken(tokenType type, char *val, int line)
{
    tokenPtr newToken = (tokenPtr) malloc(sizeof(struct token));
    newToken->type = type;
    newToken->value = val;
    newToken->lineNumber = line;
    return newToken;
}

char *strAppend(char *str, char c)
{
	char *tmp = NULL;
	int pos = 0;

	if (str == NULL)			// first character
	{
		tmp = (char*) realloc(str, sizeof(char) * 2);
   	    pos = 0;
   	}
   	else						// append an existing string
   	{
		tmp = (char*) realloc(str, sizeof(char) * (strlen(str) + 2));
		pos = strlen(str);
	}
   	if (tmp == NULL)
   	{
   		free(str);
   		return NULL;
   	}
	str = tmp;
	tmp = NULL;
	str[pos] = c;
	str[pos+1] = '\0';
	return str;
}

void getToken()
{
    static char c;
   // char *val = NULL;
    static int ended;
    static int lineNumber;              // returned in token as lineNumber+1
    AutomatState CurrentState = start;
    if (ended)
    {
        if ((CurrentState == comment && Next_State(CurrentState, c) != start) || CurrentState == comStart || CurrentState == comPom || CurrentState == stringRead)
        {
            if ((CurrentState != Next_State(CurrentState, c)) && (Next_State(CurrentState, c) == start)) 
            {
                printf("%d\n", lineNumber+1);           // return token
            }
            //printf("%c", c);            // to be deleted
            CurrentState = Next_State(CurrentState, c);
        }
        else if (c != ' ')
        {
            if ((CurrentState != Next_State(CurrentState, c)) && (Next_State(CurrentState, c) == start)) 
            {
                printf("%d\n", lineNumber+1);           // return token
            }
            if (c != '\n') printf("%c", c);     // to be deleted
            else lineNumber++;
            CurrentState = Next_State(CurrentState, c);
            if (CurrentState == start) CurrentState = Next_State(CurrentState, c);
        }
        ended = 0;
    }
    while (true)
    {
        c = getchar();
        if (c == EOF) break;            // to be changed
        if ((CurrentState == comment && Next_State(CurrentState, c) != start) || CurrentState == comStart || CurrentState == comPom || CurrentState == stringRead)
        {
            if ((CurrentState != Next_State(CurrentState, c)) && (Next_State(CurrentState, c) == start)) 
            {
                printf("%d\n", lineNumber+1);           // return token
                ended = 1;
                break;
            }
            if (c == '\n')lineNumber++;
            //printf("%c", c);            // to be deleted
            CurrentState = Next_State(CurrentState, c);
        }
        else if (c != ' ')
        {
            if ((CurrentState != Next_State(CurrentState, c)) && (Next_State(CurrentState, c) == start)) 
            {
                printf("%d\n", lineNumber+1);           // return token
                ended = 1;
                break;
            }
            if (c != '\n') printf("%c", c);     // to be deleted
            else lineNumber++;
            CurrentState = Next_State(CurrentState, c);
            if (CurrentState == start) CurrentState = Next_State(CurrentState, c);
        }
    }
}

int main ()     // testing
{
    for (int i = 0; i < 50; i++) getToken();


/*
    // createToken TESTCASE
    char str[] = "Ahoj";
    tokenPtr token = createToken(T_bracket, str, 15);
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
    case T_keyword:
        printf("type:\tT_keyword\n");
        printf("value:\t%s\n", token->value);
        printf("line:\t%d\n\n", token->lineNumber);
        break;
    case T_bracket:
        printf("type:\tT_bracket\n");
        printf("value:\t%s\n", token->value);
        printf("line:\t%d\n\n", token->lineNumber);
        break;
    case T_string:
        printf("type:\tT_string\n");
        printf("value:\t%s\n", token->value);
        printf("line:\t%d\n\n", token->lineNumber);
        break;
    case T_separator:
        printf("type:\tT_separator\n");
        printf("value:\t%s\n", token->value);
        printf("line:\t%d\n\n", token->lineNumber);
        break;
    case T_prolog:
        printf("type:\tT_prolog\n");
        printf("value:\t%s\n", token->value);
        printf("line:\t%d\n\n", token->lineNumber);
        break;
    case T_EOF:
        printf("type:\tT_EOF\n");
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
    */
    return 0;
}
