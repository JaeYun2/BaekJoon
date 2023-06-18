#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void binary_search(int val, int length, int* lst);

int res;

int main()
{
    int N,cnt=0;
    scanf("%d",&N);
    int *arr=(int*)malloc(sizeof(int)*N);
    int *lst=(int*)malloc(sizeof(int)*N);

    scanf("%d",arr);
    lst[0]=arr[0];
    for(int i=1;i<N;i++)
    {
        scanf("%d",arr+i);
        if(arr[i]>lst[cnt])
        {
            lst[++cnt]=arr[i];
        }
        else
        {
            binary_search(arr[i],cnt,lst);
        }
    }
    free(arr);
    free(lst);

    printf("%d",cnt+1);
    return 0;
}

void binary_search(int val, int length, int* lst)
{
    int l=0,r=length,m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(val<=lst[m]) r=m-1;
        else l=m+1;
    }
    lst[l]=val;
}