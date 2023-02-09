#include <stdio.h>
#include <conio.h>
int main()
{
	int max[50][50],alloc[50][50],need[50][50],n,r,i,j;
	printf("Enter the no.of processes:");
	scanf("%d",&n);
	printf("Enter the no.of resources:");
	scanf("%d",&r);
	printf("Enter the max matrix:\n");
	  for(i=0;i<n;i++)
	  {
	  	for(j=0;j<r;j++)
	  	{
	  		scanf("%d",&max[i][j]);
		  }
	  }
	printf("Enetr the allocation matrix:\n");
	  for(i=0;i<n;i++)
	  {
	  	for(j=0;j<r;j++)
	  	{
	  		scanf("%d",&alloc[i][j]);
		  }
	  }
	printf("the need matrix is :\n");
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<r;j++)
	 	{
	 		need[i][j]=max[i][j] - alloc[i][j];
	 		printf("%d\t",need[i][j]);
		 }
		 printf("\n");
	 }
	 return 0;
}
