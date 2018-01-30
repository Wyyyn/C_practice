#include <stdio.h>
#define N 20

int main() {
    int array[N];
    int x,i,n;
    printf("\nThe first %d array numbers are:\n",N);
    array[0]=2;
    n=1;
    x=3;   //从3开始
    while(n < N)  //外层循环，n控制个数，总共20个质数
    {
        i=0;
        //内层循环，找到质数x时跳出循环
        while(array[i]*array[i]<=x)// 要判断x是质数，则判断x能否被x之前的质数整除即可
        {                           //这里为了减少算法复杂度，直接判断x之前的质数array[i]的平方是否小于x，
            if(x%array[i] == 0)     //如果小于，那么x如果能整除，则不是质数，i++
            {
                x+=2;
                i=1;
            }
            else
                i++;
        }
        array[n++]=x;//将x放入数组
        x+=2;
    }
    for(i=0;i<n;i++)
        printf("%4d",array[i]);
}