#include<iostream>
#include<cstdio>
#include<climits>
#include<cstdlib>
#include<cstring>

using namespace std;

unsigned *dp;

unsigned minCoins(unsigned sum,unsigned coins[],unsigned nCoins)
{
   // printf("Sum = %u",sum);

    if(sum==0) return 0;


    if(dp[sum]==UINT_MAX)
    {
        unsigned minVal=UINT_MAX;
        unsigned result=UINT_MAX;

        for(unsigned i=0;i<nCoins;i++)
        {

            if(((int)sum-(int)coins[i])>=0)
            {
                result = minCoins(sum-coins[i],coins,nCoins);
                if(result!=UINT_MAX)
                    result+=1;

                if(result>=0 && result<minVal)
                {
                    minVal = result;
                }
            }
        }
        dp[sum]=minVal;
        return minVal;
    }

    else
        return dp[sum];
}

int main()
{
    unsigned sum;
    unsigned nCoins;
    printf("Enter nCoins");
    scanf("%u",&nCoins);

    unsigned coins[nCoins];
    for(unsigned i=0; i< nCoins;i++) scanf("%u",&coins[i]);

    printf("Enter sum");
    scanf("%u",&sum);

    dp = (unsigned*)malloc(sizeof(unsigned)*(sum+1));
   // printf("\nThe result is : ");
    memset(dp,0xFF,sizeof(unsigned)*(sum+1));
    //printf("\nThe result is : ");

    //printf("\nThe result is : ");
    unsigned result = minCoins(sum,coins,nCoins);

    printf("\nThe result is : ");
    if(result==UINT_MAX) printf("Not possible\n");
    else
    printf("%u\n",result);
    for(unsigned i=0;i<=sum;i++) printf("%u = %u,\t",i,dp[i]);


    return 0;
}
