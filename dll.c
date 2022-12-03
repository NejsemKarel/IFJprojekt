#include "dll.h"
#include "parser.h"

void Error(){
    printf("Error occured in double linked list");
    err = TRUE;
}

void Init(Dll *list){
    list->activeElement = NULL;
    list->firstElement = NULL;
    list->lastElement = NULL;
}

void Dispose(Dll *list){
    DllElementPtr elToDel;
    while(list->firstElement != NULL){
        elToDel = list->firstElement;
        if(list->firstElement != list->lastElement){
            list->firstElement = list->firstElement->nextElement;
        }else{
            list->firstElement = NULL;
            list->lastElement = NULL;
        }
        free(elToDel);
    }
}

void InsertFirst(Dll *list, tokenPtr data){
    DllElementPtr newEl = (DllElementPtr) malloc(sizeof(struct DllElement));
    if(newEl != NULL){
        newEl->data = data;
        if(list->firstElement != NULL){
            newEl->nextElement = list->firstElement;
            list->firstElement->prevElement = newEl;
            list->firstElement = newEl;
        }else{
            list->firstElement = newEl;
            list->lastElement = newEl;
        }
        newEl->prevElement = NULL;
    }else{
        Error();
    }
}

void InsertLast(Dll *list, tokenPtr data){
    DllElementPtr newEl = (DllElementPtr) malloc(sizeof(struct DllElement));
    if(newEl != NULL){
        newEl->data = data;
        if(list->lastElement != NULL){
            newEl->prevElement = list->lastElement;
            list->lastElement->nextElement = newEl;
            list->lastElement = newEl;
        }else{
            list->lastElement = newEl;
            list->firstElement = newEl;
            newEl->prevElement = NULL;
        }
        newEl->nextElement = NULL;
    }
}

void First(Dll *list){
    list->activeElement = list->firstElement;
}

void Last(Dll *list){
    list->activeElement = list->lastElement;
}

void GetFirst(Dll *list, tokenPtr *ptr){
    if(list->firstElement != NULL){
        *ptr = list->firstElement->data;
    }else{
        Error();
    }
}

void GetLast(Dll *list, tokenPtr *ptr){
    if(list->lastElement != NULL){
        *ptr = list->lastElement->data;
    }else{
        Error();
    }
}

void DeleteFirst(Dll *list){
    if(list->firstElement != NULL){
        DllElementPtr elToDel = list->firstElement;
        if(list->firstElement == list->activeElement){
            list->activeElement = NULL;
        }
        if(list->firstElement != list->lastElement){
            list->firstElement = list->firstElement->nextElement;
        }else{
            list->firstElement = NULL;
            list->lastElement = NULL;
        }
        free(elToDel);
    }
}

void DeleteLast( Dll *list ) {
	if(list->lastElement != NULL){		
		DllElementPtr elToDel = list->lastElement;		
		if(list->lastElement == list->activeElement){
			list->activeElement = NULL;
		}
		if(list->lastElement != list->firstElement){
			list->lastElement = list->lastElement->prevElement;
			list->lastElement->nextElement = NULL;
		}else{
			list->lastElement = NULL;
			list->firstElement = NULL;
		}
		free(elToDel);
	}
	
}

void DLL_DeleteAfter( Dll *list ) {
	if(IsActive(list) == TRUE){		
		if(list->activeElement != list->lastElement){
			DllElementPtr elToDel = list->activeElement->nextElement; 
			if(elToDel == list->lastElement){
				list->lastElement = list->activeElement;	
				list->activeElement->nextElement = NULL;
			}else{
				list->activeElement->nextElement = elToDel->nextElement;
				

				elToDel->nextElement->prevElement = list->activeElement;
			}
			free(elToDel);
		}
	}
}

void DLL_DeleteBefore( Dll *list ) {
	if(IsActive(list) == TRUE){		
		if(list->activeElement != list->firstElement){
			DllElementPtr elToDel = list->activeElement->prevElement;		
			if(elToDel == list->firstElement){
				list->firstElement = list->activeElement;		
				list->activeElement->prevElement = NULL;
			}else{
				list->activeElement->prevElement = elToDel->prevElement;
				

				elToDel->prevElement->nextElement = list->activeElement;
			}
			free(elToDel);
		}
	}
}

void DLL_InsertAfter( Dll *list, tokenPtr data ) {
	if(IsActive(list) == TRUE){		
		DllElementPtr newEl = (DllElementPtr) malloc(sizeof(struct DllElement));
		if(newEl != NULL){		
			newEl->data = data;
			newEl->nextElement = list->activeElement->nextElement;
			newEl->prevElement = list->activeElement;
			list->activeElement->nextElement = newEl;
			if(list->activeElement == list->lastElement){
				list->lastElement = newEl;		
				
			}else{
				newEl->nextElement->prevElement = newEl;
			}
		}else{
			Error();
		}
	}
}

void DLL_InsertBefore( Dll *list, tokenPtr data ) {
	if(IsActive(list) == TRUE){		
		DllElementPtr newEl = (DllElementPtr) malloc(sizeof(struct DllElement));
		if(newEl != NULL){		
			newEl->data = data;
			newEl->prevElement = list->activeElement->prevElement;
			newEl->nextElement = list->activeElement;
			list->activeElement->prevElement = newEl;
			if(list->activeElement == list->firstElement){
				list->firstElement = newEl;		
			}else{
				newEl->prevElement->nextElement = newEl;
			}
		}else{
			Error();
		}
	}
	
	
}

void GetValue(Dll *list, tokenPtr *ptr){
    if(IsActive(list) == TRUE){
        *ptr = list->activeElement->data;
    }else{
        Error();
    }
}

void SetValue(Dll *list, tokenPtr data){
    if(IsActive(list) == TRUE){
        list->activeElement->data = data;
    }
}

void Next(Dll *list){
    if(IsActive(list) == TRUE){
        list->activeElement = list->activeElement->nextElement;
    }
}

void Previous(Dll *list){
    if(list->activeElement != NULL){
        list->activeElement = list->activeElement->prevElement;
    }
}

int IsActive(Dll *list){
    return list->activeElement != NULL; 
}