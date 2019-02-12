#include "linkedList.h"

/*
//  1. 尾插法创建单链表，打印创建结果
int main(){
    int i;
    elementType x[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &x[j]);
    }
    linkedList * L1 = InitLinkedList_tail(i, x);
    ShowLinkedList(L1);
    return 0;
}
*/

/*
//  2. 头插法创建单链表，打印创建结果
int main(){
    int i;
    elementType x[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &x[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, x);
    ShowLinkedList(L1);
    return 0;
}
*/

/*
// 3. 销毁单链表
int main(){
    int i;
    elementType x[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &x[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, x);
    ShowLinkedList(L1);
    linkedList *L = DestroyLinkedList(L1);
    if (L == NULL) printf("\nDestroy right!\n");
    return 0;
}
*/

/*
// 4. 求链表长度
int main(){
    int i;
    elementType x[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &x[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, x);
    int length = LinkedListLength(*L1);
    printf("The length of linked list is %d\n", length);
    return 0;
}
*/

/*
// 5. 求单链表中第i个元素（函数），若不存在，报错
int main(){
    int i, k;
    elementType x[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    if (i > 0)
        printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &x[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, x);
    elementType y;
    while(getchar() != EOF){
        printf("Please enter the number which you want to get its element:");
        scanf("%d", &k);
        if (GetLinkedListElement(*L1, k, &y))
            printf("No.%d element is %d.\n", k, y);
        else
            printf("Input error!\n");
    }
    return 0;
}
*/

/*
// 6. 在第i个结点前插入值为x的结点
int main() {
    int i;
    elementType y[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &y[j]);
    }
    linkedList *L1 = InitLinkedList_head(i, y);
    elementType x;
    int k;
    while (getchar() != EOF){
        printf("Please enter the location and the element you want to insert:");
        scanf("%d %d", &i, &x);
        if (InsertLinkedListElement(L1, i, x)){
            printf("Insert right!\nThe elements in linked list now are as follow: ");
            ShowLinkedList(L1);
            printf("\n");
        }
        else {
            printf("Insert error!\n");
        }
    }
    return 0;
}
 */

/*
// 7. 链表中查找元素值为x的结点，成功返回结点指针，失败报错
int main(){
    int i;
    elementType y[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &y[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, y), * L2;
    elementType x;
    while (getchar() != EOF){
        printf("Please enter the element which you want to get its point:");
        scanf("%d", &x);
        if ((L2 = GetLocation(L1, x))){
            printf("Seek element %d right!\n", L2->data);
        }
        else {
            printf("Error, no such element!\n");
        }
    }
    return 0;
}
 */

/*
// 8. 删除单链表中第i个元素结点
int main(){
    int i;
    elementType y[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &y[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, y);
    int k;
    while (getchar() != EOF){
        printf("Please enter the number which you want to delete:");
        scanf("%d", &k);
        if (DeleteLinkedListElement(L1, k)){
            printf("Delete NO.%d element right!\n", k);
            ShowLinkedList(L1);
        }
        else {
            printf("Delete error!\n");
        }
    }
    return 0;
}
 */

/*
// 9. 在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性
int main(){
    int i;
    elementType y[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &y[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, y);
    elementType x;
    while (getchar() != EOF){
        printf("Please enter the number which you want to insert:");
        scanf("%d", &x);
        if (LinkedListInsert(L1, x)){
            printf("Insert right!\n");
            ShowLinkedList(L1);
        }
        else {
            printf("Insert error!\n");
        }
    }
    return 0;
}
 */

/*
// 10. 将单链表Ｌ中的奇数项和偶数项结点分解开
int main(){
    int i;
    elementType y[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    printf("Please enter the elements:");
    for (int j = 0; j < i; ++j) {
        scanf("%d", &y[j]);
    }
    linkedList * L1 = InitLinkedList_head(i, y);
    linkedList * L2 = InitLinkedList_head(0, y);
    linkedList * L3 = InitLinkedList_head(0, y);
    if (LinkedListSplit(*L1, L2, L3)){
        printf("The original linked list: ");
        ShowLinkedList(L1);
        printf("\nThe odd linked list: ");
        ShowLinkedList(L2);
        printf("\nThe even linked list: ");
        ShowLinkedList(L3);
    }
    else {
        printf("Split error!\n");
    }
    printf("\nInput any key to end...\n");
    getchar();getchar();
    return 0;
}
 */

/*
// 11. 求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中
int main(){
    int i, j;
    elementType y[30];
    printf("Please enter the number of L1's element:");
    scanf("%d", &i);
    if (i > 0)
        printf("Please enter L1's elements:");
    j = 0;
    while (j < i) {
        scanf("%d", &y[j]);
        j++;
    }
    linkedList * L1 = InitLinkedList_head(i, y);
    printf("Please enter the number of L2's element:");
    scanf("%d", &i);
    if (i >0)
        printf("Please enter L2's elements:");
    j = 0;
    while (j < i) {
        scanf("%d", &y[j]);
        j++;
    }
    linkedList * L2 = InitLinkedList_head(i, y);
    linkedList * L3 = InitLinkedList_head(0, y);
    if (LinkedListCommonElement(*L1, *L2, L3)){
        printf("L1: ");
        ShowLinkedList(L1);
        printf("\nL2: ");
        ShowLinkedList(L2);
        printf("\nL3: ");
        ShowLinkedList(L3);
    }
    else {
        printf("Find error!\n");
    }
    printf("\nInput any key to end...\n");
    getchar();getchar();
    return 0;
}
 */

/*
// 12. 删除递增有序单链表中的重复元素，要求时间性能最好
int main(){
    int i, j;
    elementType y[30];
    printf("Please enter the number of the element:");
    scanf("%d", &i);
    if (i > 0)
        printf("Please enter the elements:");
    j = 0;
    while (j < i) {
        scanf("%d", &y[j]);
        j++;
    }
    linkedList * L1 = InitLinkedList_head(i, y);
    if (DeleteLinkedListRepeatingElement(L1)){
        printf("Delete right!\n");
        ShowLinkedList(L1);
    }
    else {
        printf("Delete error!\n");
    }
    printf("\nInput any key to end...\n");
    getchar();getchar();
    return 0;
}
*/

/*
// 13. 合并递增有序单链表L1、L2
int main(){
    int i, j;
    elementType y[30];
    printf("Please enter the number of L1's element:");
    scanf("%d", &i);
    if (i > 0)
        printf("Please enter L1's elements:");
    j = 0;
    while (j < i) {
        scanf("%d", &y[j]);
        j++;
    }
    linkedList * L1 = InitLinkedList_head(i, y);
    printf("Please enter the number of L2's element:");
    scanf("%d", &i);
    if (i >0)
        printf("Please enter L2's elements:");
    j = 0;
    while (j < i) {
        scanf("%d", &y[j]);
        j++;
    }
    linkedList * L2 = InitLinkedList_head(i, y);
    if (LinkedListCombine(L1, L2)){
        printf("L1: ");
        ShowLinkedList(L1);
    }
    else {
        printf("Combine error!\n");
    }
    printf("\nInput any key to end...\n");
    getchar();getchar();
    return 0;
}
 */
