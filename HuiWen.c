//判断正整数n的d进制数是否为回文数
#include"stdio.h"

int circle(int n,int d)
{
	int s=0,m=n;
	while(m)
	{
		s=s*d+m%d;//几个例子，272的10进制，自己算
		m/=d;
	}
	return s==n;
}
int main()
{
	int num[]={232,344,11};
	int scale[]={2,10,16};
	int i,j;
	for(i=0;i<sizeof(num)/sizeof(num[0]);i++)
		for(j=0;j<sizeof(scale)/sizeof(scale[0]);j++)
			if(circle(num[i],scale[j]))
				printf("%5d -> (%d) is a circle number!\n",num[i],scale[j]);
			else
				printf("%5d -> (%d) is not a circle number!\n",num[i],scale[j]);
}
