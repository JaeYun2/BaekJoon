#include <stdio.h>
#include <stdlib.h>

void quick_sort(int length, int start, int *arr);
void merge_sort(int start, int end, int* arr,int* cal);

int main(int argc, char **argv)
{
    int N;
    scanf("%d",&N);

    int *arr=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }

    //quick_sort(0,N-1,arr); for quick sort
    

    ///* for Merge sort   
    int *cal=(int*)malloc(sizeof(int)*N);
    merge_sort(0,N, arr, cal);
    free(cal);
    //*/

    for(int i=0;i<N;i++) printf("%d\n",arr[i]);
    free(arr);
    return 0;
}

void quick_sort(int start, int end,int *arr)
{
    if (end-start>0)
    {
        int i=start, j=end, pivot=arr[(start+end)/2], temp;
        while(i<=j)
        {
            while(arr[i]<pivot) i++;
            while(arr[j]>pivot) j--;

            if (i<=j)
            {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++; j--;
            }
        }

        quick_sort(start,j,arr);
        quick_sort(i,end,arr);
    }
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
