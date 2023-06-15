#include <stdio.h>
#include <stdlib.h>

void quick_sort(int length, int start, int *arr);

int main(int argc, char **argv)
{
    int N;
    scanf("%d",&N);

    int *arr=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }

    quick_sort(0,N-1,arr);
    for(int i=0;i<N;i++) printf("%d\n",arr[i]);
    free(arr);
    return 0;
}

void quick_sort(int start, int end,int *arr)
{
    if (end-start>0)
    {
        int i=start, j=end, pivot=arr[(start+end)/2], temp;
        while(i<j)
        {
            while(arr[i]<pivot) i++;
            while(arr[j]>pivot) j--;

            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

        quick_sort(start,i-1,arr);
        quick_sort(j+1,end,arr);
    }
}
