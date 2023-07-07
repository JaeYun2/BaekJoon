#include <stdio.h>
#include <stdlib.h>


void merge_sort(int start, int end, int* arr, int* cal);

int main()
{
    int N,sum=0;
    scanf("%d",&N);
    int *arr=(int*)malloc(sizeof(int)*N);
    int *cal=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }

    merge_sort(0,N,arr,cal);

    for(int i=0;i<N;i++)
    {
        if(sum<arr[i]-1) break;

        sum+=arr[i];
    }
    free(arr);
    free(cal);
    printf("%d",sum+1);
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