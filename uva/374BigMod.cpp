#include<cstdio>
#include<cmath>

int bigMod(long b, long p, long m);

int main()
{

    int b, p, m;
    scanf("%ld\n%ld\n%ld",&b, &p, &m);
    int ans = bigMod(b,p,m);

    printf("%d", ans);
    return 0;

}


int bigMod(long b, long p, long m)
{

    if(p==0)
        return 1;

    if(p%2==0)
        {
            int t=(bigMod(b, p/2, m))%m ;
            return (t*t)%m;
        }
    else
        return ((b%m) * bigMod(b,p-1,m))%m;
}
