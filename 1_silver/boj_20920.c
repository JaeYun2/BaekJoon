#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct DATA
{
    int length;
    char word[11];
    int num;
}data;

void merge_sort(int start, int end, data arr[], data cal[],int flag);
int compare(data *a, data *b, int flag);

int main()
{
    int N,M,length;
    int cnt=0;

    scanf("%d %d",&N,&M);

    data* arr=(data*)malloc(sizeof(data)*N);
    data* cal=(data*)malloc(sizeof(data)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",(cal[i]).word);
        if(((cal[i]).length=strlen((cal[i]).word))<M)
        {
            cnt++;
            continue;
        }
        arr[i-cnt]=cal[i];
    }
    N-=cnt;

    
    merge_sort(0,N,arr,cal,1);
    

    int i=0,tot=0; cnt=0;
    while(i+cnt<N-1)
    {
        if(strcmp((cal[i]).word,(cal[i+cnt+1]).word))
        {
            (cal[i]).num=cnt+1;
            arr[tot]=cal[i];
            i+=cnt+1;
            cnt=0;
            tot++;
        }
        else cnt++;
    
    }
    (cal[N-1]).num=cnt+1;
    arr[tot]=cal[N-1];

    merge_sort(0,tot+1,arr,cal,0);
    
    for(int i=0;i<tot+1;i++) printf("%s\n",(arr[i]).word);
    
    return 0;
}

int compare(data *a, data *b, int flag)
{
    int i=0;
    if (flag)
    {
        if(a->length>b->length) return 1;
        else if (a->length<b->length) return 0;

        while (a->word[i])
        {
            if(a->word[i]<b->word[i]) return 1;
            else if (a->word[i]>b->word[i]) return 0;
            i++;
        }
        return 1;
    }

    if(a->num>=b->num) return 1;
    return 0;
    
}



void merge_sort(int start, int end, data arr[], data cal[],int flag)
{
    if(end-start>1)
    {
        int t=(end-start)/2,p=start+t;
        merge_sort(start,p,arr,cal,flag);
        merge_sort(p,end,arr,cal,flag);

        int i=start, cnt=start, j=p;

        while(i<p&&j<end)
        {
            if(compare(&arr[i],&arr[j],flag))
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
