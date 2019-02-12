#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

typedef int elementType;
typedef struct sStack
{
    char a[MAXLEN];
    elementType data[MAXLEN];
    int top;
}seqStack;

void initStack(seqStack *S)  /**栈的初始化**/
{
    S->top=-1;
}

void popStack(seqStack *S)  /**出栈**/
{
    if(S->top==-1)
        printf("栈空");
    else
    {
        S->top--;
    }
}

void pushStack(seqStack *S,elementType x)  /**int入栈**/
{
    if(S->top==MAXLEN-1)
        printf("栈满");
    else
    {
        S->top++;
        S->data[S->top]=x;
    }
}

void pushStack2(seqStack *S,char x)  /**char入栈**/
{
    if(S->top==MAXLEN-1)
        printf("栈满");
    else
    {
        S->top++;
        S->a[S->top]=x;
    }
}

void change(seqStack *S,int n)  /**十进制转化成十六进制（顺序栈）**/
{
    int mod;
    while(n!=0)
    {
        mod=n%16;
        pushStack(S,mod);
        n=n/16;
    }
    printf("十六进制数为：\n");
    while(S->top!=-1)
    {
        if(S->data[S->top]<10)
            printf("%d",S->data[S->top]);
        else
            printf("%c",S->data[S->top]-10+65);
        S->top--;
    }
}

int change2(seqStack *S,char s[MAXLEN])
{
    int i=0;
    initStack(S);
    for(i=0;s[i];i++) {
        if(s[i]=='{'||s[i]=='['||s[i]=='(') {
            pushStack2(S,s[i]);
        } else if(s[i]=='}') {
            if(S->a[S->top]=='{'){
                popStack(S);
            } else{
                return 0;
            }
        } else if(s[i]==']') {
            if(S->a[S->top]=='['){
                popStack(S);
            } else{
                return 0;
            }
        } else if(s[i]==')') {
            if(S->a[S->top]=='('){
                popStack(S);
            } else{
                return 0;
            }
        }
    }
    if(S->top == -1)
        return 1;
    else
        return 0;
}

void menu()
{
    printf("\n");
    printf("1.顺序栈十进制转化为十六进制         3.链栈十进制转化为十六进制\n");
    printf("2.顺序栈判断括号是否匹配             4.链栈判断括号是否匹配\n");

}
