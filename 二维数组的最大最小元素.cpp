#include<stdio.h>
#define MAX 20
 int main(void){
 	int a[MAX][MAX];
 	int min,max,x;
 	int row,col,Row,Col;
 	printf("please input the order of the matrix:\n");
 	scanf("%d%d",&Row,&Col);
 	printf("please input the elements of the matrix,from a[0][0]-a[%d][%d]:\n",Row-1,Col-1);
 	for(row=0;row<Row;row++)
 		for(col=0;col<Col;col++)
 		scanf("%d",&a[row][col]);
 	
	 	for(row=0;row<Row;row++)
 		for(col=0;col<Col;col++)
 		printf("%d ",a[row][col]);	
 		
 	for(max=a[0][0],row=0;row<Row;row++)
 	{
 		for(x=a[row][0],col=1;col<Col;col++)
		 {
 			if(x<a[row][col])
 			x=a[row][col];
		 
		 }
		 if(max<x)
		 max=x;
	 }
	 printf("\nthe maximum number is %d\n",max);
	 for(min=a[0][0],row=0;row<Row;row++)
 	{
 		for(x=a[row][0],col=1;col<Col;col++)
		 {
 			if(x>a[row][col])
 			x=a[row][col];
		 
		 }
		 if(min>x)
		 min=x;
	 }
	 printf("\nthe minimum number is %d\n",min);
 } 
 
