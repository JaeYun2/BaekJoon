#include <stdio.h>
#include <stdlib.h>

void merge_sort(int start, int end, int(*arr)[2],int(*cal)[2]);

int main(int argc, char **argv)
{
    int N;
    scanf("%d",&N);
    //only for C99, 2D array dynamic allocation
    int (*arr)[2]=(int(*)[2])malloc(sizeof(int)*N*2);
    int (*cal)[2]=(int(*)[2])malloc(sizeof(int)*N*2);
    int *result=(int*)malloc(sizeof(int)*N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",arr[i]);
        arr[i][1]=i;
    }

    merge_sort(0,N,arr,cal);

    int i=1, cnt=0;
    result[arr[0][1]]=cnt;
    while(i<N)
    {
        if(arr[i][0]!=arr[i-1][0]) cnt++;
        result[arr[i][1]]=cnt;
        i++;
    }

    for(int i=0;i<N-1;i++) printf("%d ",result[i]);
    printf("%d",result[N-1]);

    return 0;
}

void merge_sort(int start, int end, int(*arr)[2],int(*cal)[2])
{
    if(end-start>1)
    {
        int t=(end-start)/2,p=start+t;
        merge_sort(start,p,arr,cal);
        merge_sort(p,end,arr,cal);


        int i=start, cnt=start, j=p;
        while(i<p&&j<end)
        {
            if(arr[i][0]<arr[j][0])
            {
                cal[cnt][0]=arr[i][0];
                cal[cnt][1]=arr[i][1];
                i++;
            }
            else
            {
                cal[cnt][0]=arr[j][0];
                cal[cnt][1]=arr[j][1];
                j++;
            }
            cnt++;
        }
        
        if(i<p) 
        {
            for(int k=i;k<p;k++)
            {
                cal[cnt][0]=arr[k][0];
                cal[cnt][1]=arr[k][1];
                cnt++;
            }
        }
        else{
            for(int k=j;k<end;k++)
            {
                cal[cnt][0]=arr[k][0];
                cal[cnt][1]=arr[k][1];
                cnt++;
            }
        }

        for(int k=start;k<end;k++)
        {
            arr[k][0]=cal[k][0];
            arr[k][1]=cal[k][1];
        }
    }
}
