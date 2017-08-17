//Knight on a chessboard

#include<bits/stdc++.h>
int n;
int traverse(int x, int y, int a, int b)
{
    printf("x=%d,y=%d,a=%d,b=%d\n",x,y,a,b);
    if(x==(n-1) && y==(n-1))
        return 0;

    else if(x<0 || x>=n || y<0 ||y>=n) return INT_MAX;

    int r[8];

//    r[0]=traverse(x+a,y+b,a,b);
//    r[1]=traverse(x+a,y-b,a,b);
//   r[2]=traverse(x-a,y+b,a,b);
    r[3]=traverse(x-a,y-b,a,b);
  //  r[4]=traverse(x+b,y+a,a,b);
 //   r[5]=traverse(x+b,y-a,a,b);
//    r[6]=traverse(x-b,y+a,a,b);
//    r[7]=traverse(x-b,y-a,a,b);

    int smallest=INT_MAX;
    for (int i = 0; i < 1; ++i)
    {
        smallest = std::min(smallest, r[i]);
    }
    if(smallest==INT_MAX) return INT_MAX;
    else return smallest+1;
}
int main() {

    int store[25][25]={0};

    scanf("%d",&n);

    int ans;

    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(store[j][i]!=0) ans=store[j][i];
            else {
                    ans = traverse(0,0,i,j);
                    store[j][i]=ans;
                }
            printf("%d", ans);
            exit(0);
        }

        printf("\n");
    }

}
