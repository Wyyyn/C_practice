#define ERR 5
#define OK 6
#include <stdio.h>

int status;
double result,sig,scale;

int sign(int c)//处理符号
{
	if(c=='-')
		sig=-sig;
}

int integer( int c)//转换整数部分
{
	result=result*10.0+c-'0';
}

int decimal(int c)//转换小数部分，一位小数
{
	result+=(c-'0')*scale;
	scale/=10;
}

/*
 * 7个状态分别代表了从头开始转换中遇到的各个情况
 * 0-初始状态，还未开始转换
 * 1-已遇到符号字符
 * 2-转换整数部分
 * 3-在未遇到整数字符之前遇到小数点
 * 4-在遇到整数字符后遇到小数点
 * 5-错误
 * 6-转换结束
 * */
int statbl[][4]={{1,2,3,ERR},
	         {ERR,2,3,ERR},
		 {OK,2,4,OK},
		 {ERR,4,ERR,ERR},
		 {OK,4,OK,OK}};

int (*funtbl[][4])()={{sign,integer,NULL,NULL},
	              {NULL,integer,NULL,NULL},
		      {NULL,integer,NULL,NULL},
		      {NULL,decimal,NULL,NULL},									                  {NULL,decimal,NULL,NULL}};
int readreal(double *dp)//将输入字符串转换为浮点数
{
	int c,ckind;
	sig=1.0;
	result=0.0;
	scale=0.1;

	while((c=getchar())==' ' || c=='\t' || c=='\n');//跳过空白符
	status=0;//置初始状态
	for(;;)
	{
		//分类字符
		if(c=='+' || c=='-') ckind=0;
		else if(c>='0' && c<='9') ckind=1;
		else if(c=='.') ckind=2;
		else ckind=3;

		if(funtbl[status][ckind]) //如果当前为转换函数
			(*funtbl[status][ckind])(c);//执行相应的函数
			status=statbl[status][ckind];//此处status对应statbl表变化值
		if(status==ERR || status==OK) break;
		c=getchar();
	}
	ungetc(c,stdin); //归还数的结束符
	if(status == OK)
	{
		*dp=result *sig;//读入数按指针参数赋给相应变量
		return 1;
	}
	return -1;  //出错返回

}

int main()
{
	double x;
	printf("\nplease input real numbers:");
	while(readreal(&x)==1)
		printf("the real number is:%f\n",x);
	return 0;
}

