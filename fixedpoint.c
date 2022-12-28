#include<stdio.h>
#include<math.h>
float f(float x)
{
	return x*x*x+x*x-1;
}
float g(float x)
{
	return 1/sqrt(x+1);
}
int main()
{
	float x0,x1,e=0.001;
	int i;
	printf("Enter initial guess x0 :");
	scanf("%f",&x0);
	i=1;
	do
	{
		x1=g(x0);
		i=i+1;
		x0=x1;
	}while(fabs(f(x1))>e);
printf("The root is : %f",x1);
return 0;
}
