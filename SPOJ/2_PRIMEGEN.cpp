#include<bits/stdc++.h>
using namespace std;

vector<long long> primes;
long long highestLimit;

int simpleSeive(long long limit) //returns number of primes
{
    bool mark[limit+1];

    memset(mark, true, sizeof(mark));

    for(long long i=2;i*i<limit; i++)
    {
        if(mark[i]==true)
        {
            for(long long j=2*i; j<limit; j+=i)
            {
                mark[j]=false;
            }
        }
    }

    for(long long i=2;i<limit;++i)
    {
        if(mark[i]==true)
        {
            primes.push_back(i);
        }
    }

    return primes.size();
}

void segSeive(long long limit)
{
    long long simpleSeiveLimit = floor(sqrt(limit)) +1;

    long long nElemPrimes = simpleSeive(simpleSeiveLimit);
    //printf("Completed simple seive till %d, found %d primes\n",simpleSeiveLimit, nElemPrimes);

    long long lowBound = simpleSeiveLimit;
    long long highBound = 2*simpleSeiveLimit;
    long long start;
    long long prime;

    bool mark[simpleSeiveLimit+1];
    while (lowBound<limit)
    {
        memset(mark, true, sizeof(mark));
        for(long long i=0; i<nElemPrimes; ++i)
        {
            prime = primes[i];

            //find first mulltiple of prime[i] in range [lowBound, highBound]
            start = ceil(lowBound/prime)*prime;

            for(long long j=start; j<highBound; j+=prime)
            {
                mark[j-lowBound]=false;
            }
        }

        for(long long i=0;i<simpleSeiveLimit;++i)
        {
            if(mark[i]==true)
                primes.push_back(lowBound+i);
        }


        highBound+=simpleSeiveLimit;
        lowBound+=simpleSeiveLimit;
        if(highBound>limit) highBound=limit;
    }
}


int main()
{
    int t;
    long long tlimits[10][2];
    scanf("%d",&t);

    long long highest=0;
    for(int i=0;i<t; ++i)
    {
        scanf("%lld %lld", &tlimits[i][0], &tlimits[i][1]);

        if(highest<tlimits[i][1])
        {
            highest=tlimits[i][1];
        }
    }

    segSeive(highest+1);
    long long low, high;
    for(int i=0;i<t; ++i)
    {
        low=tlimits[i][0];
        high=tlimits[i][1];

        long long j;
        for(j=0;primes[j]<low;j++);

        for(;primes[j]<=high;j++)
            printf("%lld\n",primes[j]);

        printf("\n");
    }
}
