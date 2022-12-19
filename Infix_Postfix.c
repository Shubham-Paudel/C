#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define Maxsize 100
int top=-1;
char stack[100];
void push(char x)
{
    if(top==Maxsize-1)
    printf("\nStack Overflow");
    else
    top++;
    stack[top]=x;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int priority(char x)
{
    if(x=='('||x==')')
    return 0;
    else if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 2;
}
int main()
{
    char exp[100];
    char x;
    int i=0;
    printf("Enter a infix Expression :");
    scanf("%s",exp);
    strrev(exp);
    while (exp[i]!='\0')
    {
        if(isalnum(exp[i]))
        {
            printf("%c",exp[i]);
        }
        else if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while(x=pop()!='(')
            {
                exp[i]=x;
            }
        }
        else{
        while(priority(stack[top])>priority(exp[i]))
        {
            printf("%c",pop());
        }
        push(exp[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        exp[i++]=pop();
        exp[i]='\0';
        strrev(exp);
        printf("%s",exp);
    }
return 0;
    }