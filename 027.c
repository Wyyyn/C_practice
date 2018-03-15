#include"stdio.h"
#define MAX 30
int rep(char *s,char *s1,char *s2)
{
	char *p;
	for(;*s;s++)
	{
		for(p=s1;*p && *p!=*s;p++);//判断s中的当前字符是否在s1中出现
		if(*p)
			*s=*(p-s1+s2);//用s2中的字符替换掉s中的字符
	}
}

int main()
{
	char s[MAX],s1[MAX],s2[MAX];
	puts("\nplease input the string of s:");
	scanf("%s",s);
	puts("\nplease input the string of s1:");
	        scanf("%s",s1);
	puts("\nplease input the string of s2:");
	        scanf("%s",s2);
		rep(s,s1,s2);
		puts("\nthe displaced s is:");
		printf("\n %s",s);

}

