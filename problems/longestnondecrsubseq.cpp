#include<cstdio>
#include<cstring>
#include<cstdlib>

unsigned calc_largest_seq(int a[],int size)
{
    unsigned *sol = (unsigned *)malloc(sizeof(unsigned)*(size+1));
    sol[1]=1;
    unsigned last1_pos=1;
    unsigned last2_pos=1;

    for(unsigned i=2;i<=size;i++)
    {
      if(a[i]>a[last1_pos])
      {
            sol[i] = sol[i-1]+1;
            last2_pos = last1_pos;
            last1_pos = i;
      }

      else if(a[i]>a[last2_pos])
      {
          sol[i]=sol[i-2]+1;
          last2_pos=last1_pos;
          last1_pos=i;
      }

      else
      {
          if(sol[i-1]==1)
          {
            last2_pos = last1_pos;
            last1_pos = i;
          }
          sol[i]=sol[i-1];

      }
    }

    //for(unsigned i=1;i<=size;i++) printf("%u = %u \t",i,sol[i]);
    return sol[size];
}




int main()
{
 unsigned n;
 int *arr;

 //printf("Enter n");
 scanf("%u",&n);

 arr = (int*)malloc(sizeof(int)*(n+1));
 for(unsigned i=1;i<=n;i++)
    scanf("%d",&arr[i]);
 unsigned result = calc_largest_seq(arr,n);
 printf("%u",result);


 return 0;
}
