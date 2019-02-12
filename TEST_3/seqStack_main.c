#include <stdio.h>
#include <stdlib.h>

#include "seqstack.h"

int main(void)
{
    int option;
    do{
        system("cls");
        menu();
        printf("\nPlease input your option[1-4]:");
        scanf("%d", &option);
        switch (option){
            case 0:
                break;
            case 1: {
                seqStack S;
                int n;
                initStack(&S);
                printf("输入十进制数：\n");
                scanf("%d",&n);
                change(&S,n);
            }getchar();getchar();
                break;

            case 2: {
                seqStack S;
                char a[MAXLEN];
                printf("enter your string:\n");
                scanf("%s",a);
                if (change2(&S,a))
                    printf("match!\n");
                else
                    printf("no match!\n");
            }getchar();getchar();
                break;

            default:
                printf("wrong option!\n");
                getchar();getchar();
                break;
        }
    }while(option);
    return 0;
}
