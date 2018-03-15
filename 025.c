//在已知的两个从小到大的有序数组中寻找都出现的第一个元素的指针
#include"stdio.h"
#define NULL 0

int *search(int *pa,int *pb,int an,int bn)
{
	int *ca,*cb;
	ca=pa;cb=pb;
	while(ca<pa+an && cb<pb+bn)      //两个数组都未比较完
	{
		if(*ca<*cb)
			ca++;//a数组当前元素小于b数组当前元素，a数组++
		else if(*ca>*cb)
			cb++;
		else//两个元素相等返回指针
			return ca;
	}	
	return NULL;
}

void main()
{
	int a[]={1,3,5,7,9,13,16,17,23};
	int b[]={2,4,6,8,9,14,18,20};
	int *p,i;
	puts("The elements of array a are :");
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		printf(" %d",a[i]);
	puts("\nThe elements of array b are :");
	for(i=0;i<sizeof(b)/sizeof(b[0]);i++)
		printf(" %d",b[i]);
	p=search(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
	if(p)
	{
		printf("\nThe first same number in both arrays is %d\n",*p);
	}
	else printf("Not found!");
}
