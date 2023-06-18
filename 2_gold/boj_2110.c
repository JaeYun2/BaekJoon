#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge_sort(int start, int end, int* arr,int* cal);
int router(int m, int M, int N, int *arr);


int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int *arr=(int*)malloc(sizeof(int)*N);
    int *cal=(int*)malloc(sizeof(int)*N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }

    merge_sort(0,N, arr, cal);
    free(cal);

    int l=1,r=arr[N-1]-arr[0],m;
    while(l<=r)
    {
        m=(l+r)/2;
        if (router(m,M,N,arr))
        {
            r=m-1;
        }
        else l=m+1;
    }
    printf("%d",l-1);

    free(arr);
    
    return 0;
}

void merge_sort(int start, int end, int* arr, int* cal)
{
    if(end-start>1)
    {
        int t=(end-start)/2,p=start+t;
        merge_sort(start,p,arr,cal);
        merge_sort(p,end,arr,cal);


        int i=start, cnt=start, j=p;
        while(i<p&&j<end)
        {
            if(arr[i]<arr[j])
            {
                cal[cnt]=arr[i];
                i++;
            }
            else
            {
                cal[cnt]=arr[j];
                j++;
            }
            cnt++;
        }
        
        if(i<p) 
        {
            for(int k=i;k<p;k++)
            {
                cal[cnt]=arr[k];
                cnt++;
            }
        }
        else{
            for(int k=j;k<end;k++)
            {
                cal[cnt]=arr[k];
                cnt++;
            }
        }

        for(int k=start;k<end;k++) arr[k]=cal[k];
    }
}

int router(int m, int M, int N, int *arr)
{
    int cnt=1,t=0;
    for(int i=1;i<N;i++)
    {
        if(arr[i]-arr[t]>=m)
        {
            t=i;
            cnt++;
        }
    }
    if(cnt<M) return 1;
    else return 0;
}
