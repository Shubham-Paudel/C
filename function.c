#include<stdio.h>
int mul(int a,int b)
{
    return a*b;
}
int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int l,b;
    int c,d;
    printf("First no. :",&l);
    scanf("%d",&l);
    printf("\nSecond no. :",&b);
    scanf("%d",&b);
    c=mul(l,b);
    printf("The mul is :%d",c);
    d=sum(l,b);
    printf("\nThe sum is :%d",d);
    return 0;
}
