#include<stdio.h>

int power(int x, int n)
{
    int powerseq=x;
    int res = 1;

    while(n>0)
    {
     if(n&1==1)
        res=res*powerseq;
     n=n>>1;
     powerseq*=powerseq;
    }

    return res;
}

int main(void)
{
 int x=12;
 int n=2; //to calculate x^n

 printf("%d",power(x,n));

}


