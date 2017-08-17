#include<cstdio>
#include<vector>
#include<algorithm>
//0=> nmatchbox, 1=>nmatchsticks

struct Crate{
    int nbox;
    int nmatches;
};

bool comparator(const Crate& crate1, const Crate& crate2)
    {
        return (crate1.nmatches > crate2.nmatches);
    }

int main()
{
    int n, c;
    std::vector<Crate> crates;

    long long nmatchtot=0;
    int boxCount;

    scanf("%d %d", &n, &c);

    register int i=0;

    for(i=0;i<c;i++)
    {
        crates.push_back(Crate());
        scanf("%d %d", &crates[i].nbox, &crates[i].nmatches);
    }

    std::sort(crates.begin(), crates.end(), comparator);

//    for(i=0;i<n;i++)
//    {
//       printf("%d %d", crates[i].nbox, crates[i].nmatches);
//    }

    boxCount=0;
    nmatchtot=0;

    for(i=0;i<c;i++)
    {
        if(boxCount<n)
        {
            if((crates[i].nbox+boxCount) <= n)
                {
                    boxCount+=crates[i].nbox;
                    nmatchtot+= ((crates[i].nmatches) * (crates[i].nbox));
                }

            else
                {
                    nmatchtot+= ((crates[i].nmatches) * (n- boxCount));
                    boxCount+= n-boxCount;
                }
        }

        else break;
    }

    printf("%lld", nmatchtot);

}
