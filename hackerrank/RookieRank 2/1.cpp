//Migratory Birds
#include<bits/stdc++.h>


int main(int argc, char const *argv[]) {
    int typeCount[5]={0};
    int n;
    int temp;

    scanf("%d",&n);
    for(int i=0;i<n; i++)
    {
        scanf("%d",&temp);
        typeCount[temp-1]++;
    }

    int greatest=0;
    for(int i=1;i<5;i++)
    {
        if(typeCount[i]>typeCount[greatest])
            greatest=i;
    }

    printf("%d", greatest+1);
  return 0;
}
