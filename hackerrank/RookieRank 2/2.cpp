//Minimum Absolute Difference

#include<bits/stdc++.h>

int main() {

    int n;
    scanf("%d",&n);

    std::vector<int> a;
    int t;
    for(int i=0; i<n;i++)
    {
        scanf("%d",&t);
        a.push_back(t);
    }

    std::sort(a.begin(), a.end());

    int minDiff=INT_MAX;

    for(int i=1; i<n; i++)
    {
        if(abs(a[i]-a[i-1]) < minDiff)
            minDiff= abs(a[i]-a[i-1]);
    }

    printf("%d", minDiff);
}
