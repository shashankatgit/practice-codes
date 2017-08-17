#include<stdio.h>

void heapify(int a[], int i, int size)
{
 int largest=0;
 int lchild, rchild;
 int temp;
 lchild = i*2;
 rchild = i*2+1 ;
 if(lchild<=size && a[lchild]>a[i]) largest = lchild;
 else largest=i;

 if(rchild<=size && a[rchild]>a[largest]) largest = rchild;

 if(largest!=i)
 {
    temp = a[largest];
    a[largest] = a[i];
    a[i] = temp;
    heapify(a,largest,size);
 }

}

void build_max_heap(int a[], int size)
{
    int i;
    for(i=size/2;i>=1;i--)
    {
        heapify(a,i,size);
    }

}

int main()
{
 int a[10000];
 int i;
 int n;
 int level=2;

 printf("enter n");
 scanf("%d",&n);

 for(i=1;i<=n;i++) scanf("%d",&a[i]);

 build_max_heap(a,n);

 for(i=1;i<=n;i++)
    {
        printf("%d  ",a[i]);
        if(i+1==level)
        {
            printf("\n");
            level<<=1;
        }
    }
 return 0;
}
