#include <stdio.h>
#include <stdlib.h>

#include "seqList.h"

/*
int main(void)
{
    seqList L1={{1,2,3,4,5,6,7,8,9}, 9};
    seqList L2={{}, 0};
    seqList L3={{}, 0};
    seqList L4={{2,4,5,7,8,9,30}, 7};
    int option;
    do{
        system("cls");
        menu();
        printf("Please input your option[0-8]:");
        scanf("%d", &option);
        switch (option){
            case 0:
                printf("\n\n-------------Welcome again!------------\n");
                getchar();getchar();
                break;
            case 1: {
                printf("Please input the number which you want to get:");
                int i;
                elementType e;
                scanf("%d", &i);
                if (GetElement(L1, i, &e) == OK) {
                    printf("No.%d element is %d!\n", i, e);
                } else {
                    printf("The number %d is out of range!\n", i);
                }
                getchar();
                getchar();
                break;
            }
            case 2: {
                printf("Please input the element and its position which you want to insert:");
                int i;
                elementType e;
                scanf("%d %d", &e, &i);
                if (InsertElement(&L1, i, e) == OK) {
                    printf("The element %d has been inserted to list!\n", e);
                }
                else {
                    printf("The number %d is out of range!\n", i);
                }
                getchar();
                getchar();
                break;
            }
            case 3:{
                printf("Please input the position which you want to delete:");
                int i;
                scanf("%d", &i);
                if (DeleteElement(&L1, i) == OK){
                    printf("The element which is position is %d has been deleted!\n", i);
                }
                else {
                    printf("The number %d is out of range!\n", i);
                }
            }
                getchar();getchar();
                break;
            case 4:{
                elementType x;
                scanf("%d", &x);
                if (ListInsert(&L1, x) == OK){
                    printf("The element %d has been insert to list!\n", x);
                }
                else {
                    printf("Insert error!\n");
                }
            }
                getchar();getchar();
                break;
            case 5:{
                if (ListSplit(L1, &L2, &L3) == OK){
                    printf("Split right!\n");
                    displayList(L1);
                    printf("The odd list is as follows:");
                    displayList(L2);
                    printf("The even list is as follows:");
                    displayList(L3);
                }
            }
                getchar();getchar();
                break;
            case 6:{
                if (FindCommonElement(L1, L4, &L3) == OK){
                    printf("Find common element right!\n");
                    displayList(L3);
                }
            }
                getchar();getchar();
                break;
            case 7:{
                int count;
                if (DeleteRepeatingElement(&L1, &count) == OK){
                    printf("Delete repeating element right!\n");
                    displayList(L1);
                    printf("Moving number: %d", count);
                }
            }
                getchar();getchar();
                break;
            case 8:
                displayList(L1);
                getchar();getchar();
                break;
            default:
                printf("Please input the right option[0-8]!\n");
                getchar();getchar();
                break;
        }
    }while(option);
    return 0;
}
 */
