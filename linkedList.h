#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int status;
typedef int elementType;

typedef struct chain_node{
    elementType data;
    struct chain_node * next;
}linkedList;

linkedList * InitLinkedList_tail(int i, const elementType * x);
linkedList * InitLinkedList_head(int i, const elementType * x);
linkedList *  DestroyLinkedList(linkedList * L);
int LinkedListLength(linkedList L);
status GetLinkedListElement(linkedList L, int i, elementType * x);
status InsertLinkedListElement(linkedList * L, int i, elementType x);
linkedList * GetLocation(linkedList * L, elementType x);
status DeleteLinkedListElement(linkedList * L, int i);
status LinkedListInsert(linkedList * L, elementType x);  //递增有序地插入x
status LinkedListSplit(linkedList L, linkedList * odd_L, linkedList * even_L);
status LinkedListCommonElement(linkedList L1, linkedList L2, linkedList * L3);
status DeleteLinkedListRepeatingElement(linkedList * L);
status LinkedListCombine(linkedList * L1, linkedList * L2);
status ShowLinkedList(linkedList * L);

linkedList * InitLinkedList_tail(int i, const elementType * x){
    linkedList * L = (linkedList *)malloc(sizeof(linkedList));
    linkedList * p = L;
    p->data = 0;
    p->next = NULL;
    int j;
    for (j = 0; j < i; ++j) {
        p->next = (linkedList *)malloc(sizeof(linkedList));
        p = p->next;
        p->data = *(x+j);
        p->next = NULL;
    }
    return L;
}

linkedList * InitLinkedList_head(int i, const elementType * x){
    int j;
    linkedList * L = NULL;
    for (j = i-1; j >= 0; j--) {
        linkedList * p = (linkedList *)malloc(sizeof(linkedList));
        p->data = *(x+j);
        p->next = L;
        L = p;
    }
    linkedList * p = (linkedList *)malloc(sizeof(linkedList));
    p->data = i;
    p->next = L;
    L = p;
    return L;
}

linkedList *  DestroyLinkedList(linkedList * L){
    if (L->next == NULL){
        free(L);
    }
    else {
        DestroyLinkedList(L->next);
        free(L);
    }
    L = NULL;
    return L;
}

int LinkedListLength(linkedList L){
    return L.data;
}

status GetLinkedListElement(linkedList L, int i, elementType * x){
    if (i < 1 || i > L.data) return ERROR;
    linkedList * p = &L;
    int j = 0;
    while (j < i){
        p = p->next;
        j++;
    }
    *x = p->data;
    return OK;
}

status InsertLinkedListElement(linkedList * L, int i, elementType x){
    if (i < 1 || i > L->data)
        return ERROR;
    linkedList * p = L;
    int j = 0;
    while (j < i-1){
        p = p->next;
        j++;
    }
    linkedList * t = (linkedList*)malloc(sizeof(linkedList));
    t->data = x;
    t->next = p->next;
    p->next = t;
    L->data++;
    return OK;
}

linkedList * GetLocation(linkedList * L, elementType x){
    linkedList * p ;
    for (p = L->next; p != NULL; p = p->next) {
        if (p->data == x)
            return p;
    }
    return NULL;
}

status DeleteLinkedListElement(linkedList * L, int i){
    if (i < 1 || i > L->data) return ERROR;
    linkedList * p = L;
    int j;
    for (j = 0; j < i-1; ++j) {
        p = p->next;
    }
    linkedList * p_deleted = p->next;
    p->next = p->next->next;
    free(p_deleted);
    L->data--;
    return OK;
}

status LinkedListInsert(linkedList * L, elementType x){
    linkedList * p;
    if (L->next == NULL) return ERROR;
    for (p = L; p->next != NULL; p = p->next) {
        if (p->next->data >= x)
            break;
    }
    linkedList * t = (linkedList *)malloc(sizeof(linkedList));
    t->data = x;
    t->next = p->next;
    p->next = t;
    L->data++;
    return OK;
}

status LinkedListSplit(linkedList L, linkedList * odd_L, linkedList * even_L) {
    linkedList *L_p = &L, *o_p = odd_L, *e_p = even_L;
    while (L_p->next != NULL) {
        L_p = L_p->next;
        if (L_p->data % 2) {
            o_p->next = (linkedList *) malloc(sizeof(linkedList));
            o_p = o_p->next;
            o_p->next = NULL;
            o_p->data = L_p->data;
            odd_L->data++;
        } else {
            e_p->next = (linkedList *) malloc(sizeof(linkedList));
            e_p = e_p->next;
            e_p->next = NULL;
            e_p->data = L_p->data;
            even_L->data++;
        }
    }
    return OK;
}

status LinkedListCommonElement(linkedList L1, linkedList L2, linkedList * L3){
    L3->next = NULL;
    L3->data = 0;
    linkedList *p1 = L1.next, *p2 = L2.next, *p3 = L3;
    while (p1 != NULL){
        while (p2 != NULL && p1->data >= p2->data){
            if (p1->data == p2->data){
                p3->next = (linkedList *)malloc(sizeof(linkedList));
                p3 = p3->next;
                p3->data = p1->data;
                p3->next = NULL;
                L3->data++;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return OK;
}

status DeleteLinkedListRepeatingElement(linkedList * L){
    if (L == NULL) return ERROR;
    if (L->data <= 1) return OK;
    linkedList * pri_p = L->next, * cur_p = pri_p->next;
    while (cur_p!= NULL){
        while (pri_p->data == cur_p->data){
            pri_p->next = cur_p->next;
            free(cur_p);
            L->data--;
            cur_p = pri_p->next;
            if (cur_p == NULL) return OK;
        }
        pri_p = pri_p->next;
        cur_p = pri_p->next;
    }
    return OK;
}

status LinkedListCombine(linkedList * L1, linkedList * L2){
    linkedList * p1 = L1, * p2 = L2, * p3;
    while (p2->next != NULL ){
        while ((p1->next != NULL) && (p1->next->data <= p2->next->data)){
            p1 = p1->next;
        }
        if (p1->next == NULL){
            if (p1->data != p2->next->data){
                p1->next = p2->next;
                L1->data = L1->data + L2->data;
                free(p2);
                return OK;
            }
            else {
                p1->next = p2->next->next;
                L1->data = L1->data + L2->data - 1;
                free(p2);
                return OK;
            }

        }
        if (p1->data != p2->next->data){
            p3 = p2->next;
            p2->next = p2->next->next;
            p3->next = p1->next;
            p1->next = p3;
            L1->data++;
            L2->data--;
        }
        else {
            p3 = p2->next;
            p2->next = p2->next->next;
            free(p3);
            L2->data--;
        }
    }
    free(L2);
    return OK;
}

status ShowLinkedList(linkedList * L){
    linkedList * p = L->next;
    while (p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}