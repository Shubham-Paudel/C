#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;
#define Maxsize 100 
void push(char c)
{
    if(top==Maxsize-1)
    printf("Stack overflow");
    else
    top++;
    stack[top]=c;
}
char pop()
{
    if(top==-1)
    printf("Stack underflow");
    else
    top--;
    return stack[top];
}
int priority(char x)
{
    if(x=='(')
    return 0;
    if(x=='+'||x=='-')
    return 1;
    if (x=='*'||x=='/')
        return 2;
}
int main()
{
    char exp[20];
    char *e,x;
    printf("Enter the expression :");
    scanf("%s",exp);
    e=exp;
    while (*e!='\0')
    {
        if(isalnum(*e))
        printf("%c",*e);
        else if(*e=='(')
        push(*e);
        else if(*e==')')
        {
            while((x=pop())!='(')
                printf("%c",x);
        }
        else
        {
            while (priority(stack[top])>=priority(*e))
            {
                printf("%c",pop());
                push(*e);
            }
        }
         e++;
    }
        while(top!=-1)
        {
            printf("%c",pop());
        }
}