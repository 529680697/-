#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100  //定义顺序表最大长度
#define ERROR -1
#define OK 1

typedef  int status;  //定义函数返回值类型
typedef  int elementType;  //定义数据元素类型

typedef struct Sqlist{  //定义顺序表结构体
    elementType data[MAX_LEN];
    int length;
}seqList;

//功能函数的声明
status GetElement(seqList L, int i, elementType * e);  //得到第i位元素，用e保存
status InsertElement(seqList * L, int i, elementType e);  //在第i位插入元素e
status DeleteElement(seqList * L, int i);  //删除第i位元素
status ListInsert(seqList * L, elementType x);  //递增有序地插入x
status ListSplit(seqList L, seqList * odd_L, seqList * even_L);  //奇偶分解
status FindCommonElement(seqList L1, seqList L2, seqList * L3);  //把L1与L2中公共元素放到new_L中
status DeleteRepeatingElement(seqList * L, int * count);  //删除递增有序顺序表中的重复元素
void menu(void);
void displayList(seqList L);  //显示出表格内容

//功能函数的定义
status GetElement(seqList L, int i, elementType * e){
    if (i<1 || i>L.length) return ERROR;  //i的值超过顺序表的范围
    *e = L.data[i-1];
    return OK;
}

status InsertElement(seqList * L, int i, elementType e){
    if (i<1 || i>L->length+1) return ERROR;  //i的值超过顺序表的范围
    int j;
    for (j = L->length; j >= i; j--) {  //表格第i位起均向后移动一位，以便插入新元素
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;  //把新元素插入顺序表
    L->length++;  //表格长度+1
    return OK;
}

status DeleteElement(seqList * L, int i){
    if (i<1 || i>L->length) return ERROR;
    int j;
    for (j = i; j < L->length; j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return OK;
}

status ListInsert(seqList * L, elementType x){
    int i = 0;
    while (L->data[i] <= x && i < L->length){
        i++;
    }
    InsertElement(L, i+1, x);
    return OK;
}

status ListSplit(seqList L, seqList * odd_L, seqList * even_L){
    int i = 0, j = 0, k = 0;
    odd_L->length = 0;
    even_L->length =0;
    while (i < L.length){
        if (L.data[i] % 2){
            odd_L->data[j] = L.data[i];
            odd_L->length++;
            j++;
        }
        else {
            even_L->data[k] = L.data[i];
            even_L->length++;
            k++;
        }
        i++;
    }
    return OK;
}

status FindCommonElement(seqList L1, seqList L2, seqList * L3){
    int i = 0, j = 0, k = 0;
    L3->length = 0;
    while (i < L1.length){
        while (j < L2.length && L1.data[i] >= L2.data[j]){
            if (L1.data[i] == L2.data[j]){
                L3->data[k] = L1.data[i];
                L3->length++;
                k++;
            }
            j++;
        }
        i++;
    }
    return OK;
}

status DeleteRepeatingElement(seqList * L, int * count){
    int i = 0, j = 1, k = 1;
    *count = 0;  //移动次数
    if (L->length == 0) return ERROR;
    while (j < L->length){
        while (L->data[i] == L->data[j]){
            j++;
        }
        if (j != k && j < L->length){
            L->data[k] = L->data[j];
            (*count)++;
        }
        if (j == L->length && i != j-1)
            k--;
        i = j;
        j = i+1;
        k++;
    }
    L->length = k;
    return OK;
}

void menu(void){
    printf("\n");
    printf("1.GetElement          5.ListSplit\n");
    printf("2.InsertElement       6.FindCommonElement\n");
    printf("3.DeleteElement       7.DeleteRepeatingElement\n");
    printf("4.ListInsert          8.DisplayList\n");
    printf("0.Exit\n");
}

void displayList(seqList L){
    int i;
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}
