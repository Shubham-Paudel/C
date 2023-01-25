#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.00001
int main()
{
	int i,j,n;
	float lo,ln,a[50][50],x[10],xnew[10],temp;
	printf("Enter n :");
	scanf("%d",&n);
	printf("\nEnter matrix :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		printf("A[%d][%d]",i,j);
		scanf("%f",&a[i][j]);
	}
	printf("\n");
	}
	printf("Enter inital guess vector :\n");
	for(i=1;i<=n;i++)
	{
		printf("\t x[%d]",i);
		scanf("%f",&x[i]);
	}
	lo=1;
	up:
	for(i=1;i<=n;i++)
	{
		temp=0.0;
		for(j=1;j<=n;j++)
		{
			temp=temp+a[i][j]*x[j];
		}
		xnew[i]=temp;
	}
	for(i=1;i<=n;i++)
	{
		x[i]=xnew[i];
	}
	ln=fabs(x[1]);
	for(i=2;i<=n;i++)
	{
		if(fabs(x[i])>ln)
		{
			ln=fabs(x[i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		x[i]=x[i]/ln;
	}
	printf("The solutions are :\n");
	printf("The eigen value is :%f\n",ln);
	printf("The eigen vector is :\n");
	for(i=1;i<=n;i++)
	{
		printf("\n%f",x[i]);
	}
	printf("\n");
	if(fabs(ln-lo)>e)
	{
		lo=ln;
		goto up;
	}
	return 0;
}
