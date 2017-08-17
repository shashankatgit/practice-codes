#include<stdio.h>

// Fermat's work that 2^(p-1) MOD p = 1 for all prime except 2

int main()
{
 int uBound = 101;
 long long term=1;


 while((--uBound)>2)
 {
    term = 1<<(uBound-1);
    if(term%uBound == 1)
        printf("%u ->",uBound);
 }
}
