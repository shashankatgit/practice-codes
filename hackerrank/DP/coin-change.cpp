#include<cstdio>

int memTable[250];

int main()
{
    int amount, nCoins;
    int coins[50];



    scanf("%d %d",&amount, &nCoins);

    register int i, j;

    for(i=0;i<nCoins;i++)
    {
        scanf("%d",&coins[i]);
        memTable[coins[i]]=1;
    }

    for(i=1;i<=amount;i++)
    {
        for(j=0;j<nCoins;j++)
        {
            if(i - coins[j] > 0)
            {
                memTable[i] += memTable[i-coins[j]];
            }
        }
        printf("%d %d\n",i, memTable[i]);

    }

    printf("%d", memTable[amount]);
}
