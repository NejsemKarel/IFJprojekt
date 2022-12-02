/*
**************************************************
* IFJ Projekt
* Soubor: dll.h
* Hlavičkový soubor pro dll.c
**************************************************
*/

#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

int err;

typedef struct DllElement{
    tokenPtr data;
    struct DllElement *prevElement;
    struct DllElement *nextElement;
}*DllElementPtr;

typedef struct{
    DllElementPtr firstElement;
    DllElementPtr activeElement;
    DllElementPtr lastElement;
} Dll;

//funkce

void Init(Dll*);
void Dispose(Dll*);
void InsertFirst(Dll*,tokenPtr);
void InsertLast(Dll*,tokenPtr);
void First(Dll*);
void Last(Dll*);
void GetFirst(Dll*, tokenPtr*);
void GetLast(Dll*, tokenPtr*);
void DeleteFirst(Dll*);
void DeleteLast(Dll*);
void DeleteAfter(Dll*);
void DeleteBefore(Dll*);
void InsertAfter(Dll*, tokenPtr);
void InsertBefore(Dll*, tokenPtr);
void GetValue(Dll*, tokenPtr*);
void SetValue(Dll*, tokenPtr);
void Next(Dll*);
void Previous(Dll*);
int IsActive(Dll*);