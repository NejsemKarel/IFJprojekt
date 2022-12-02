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
    int data;
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
void InsertFirst(Dll*,int);
void Insertlast(Dll*,int);
void First(Dll*);
void Last(Dll*);
void GetFirst(Dll*, int*);
void GetLast(Dll*, int*);
void DeleteFirst(Dll*);
void DeleteLast(Dll*);
void DeleteAfter(Dll*);
void DeleteBefore(Dll*);
void InsertAfter(Dll*, int);
void InsertBefore(Dll*, int);
void GetValue(Dll*, int*);
void SetValue(Dll*, int);
void Next(Dll*);
void Previous(Dll*);
int IsActive(Dll*);