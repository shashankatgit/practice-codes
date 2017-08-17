#include<cstdio>

int main()
{
    long long int xt, yt, xd, yd;
    int n;

    long long int xtot=0, ytot=0;
    long long int xhome, yhome;

    scanf("%lld %lld", &xt, &yt);

    scanf("%d", &n);

    register int i;

    for(i=0; i<n; i++)
    {
        scanf("%lld %lld", &xd, &yd);

        xtot+=xd;
        ytot+=yd;
    }

    xhome = xt - xtot;
    yhome = yt - ytot;

    printf("%lld %lld", xhome, yhome);


}
