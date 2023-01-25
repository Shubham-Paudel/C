#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,k,j;
	float r,a[50][50],x[50];
	printf("Enter n :");
	scanf("%d",&n);
	printf("\nEnter the matrix :");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			printf("\tA[%d][%d] :",i,j);
			scanf("%f",&a[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=n-1;i++)
	{
		if(a[i][i]==0)
		{
			printf("\nMathematical error!!");
		}
		for(j=i+1;j<=n;j++)
		{
			r=a[j][i]/a[i][i];
		for(k=1;k<=n+1;k++)
		{
			a[j][k]=a[j][k]-r*a[i][k];
		}
	}
	}
	x[n]=a[n][n+1]/a[n][n];
	for(i=n-1;i>=1;i--)
	{
		x[i]=a[i][n+1];
		for(j=i+1;j<=n;j++)
		{
		x[i]=x[i]-a[i][j]*x[j];
	}
		x[i]=x[i]/a[i][i];
	}
	printf("\n The solutions are :");
	for(i=1;i<=n;i++)
	{
		printf("\t%f",x[i]);
	}
	return 0;
}
