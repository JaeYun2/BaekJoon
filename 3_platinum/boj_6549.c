//Using Stack

#include <stdio.h>

long long arr[100000];
long long stack[100000]={0};
int main()
{
    long long N,cnt,max;
    while(1)
    {   
        scanf("%lld",&N);
        if(N==0) break;
        max=0,cnt=0;
        scanf("%lld",arr);
        for(int i=1;i<N;i++)
        {
            scanf("%lld",arr+i);
            if(arr[stack[cnt]]<arr[i])
            {
                stack[++cnt]=i;
                continue;
            }
            while(cnt>-1&&arr[stack[cnt]]>=arr[i])
            {
                max=max>arr[stack[cnt]]*(i-stack[cnt])?max:arr[stack[cnt]]*(i-stack[cnt]);
                cnt--;
            }
            arr[stack[++cnt]]=arr[i];
        }
        while(cnt>-1)
            {
                max=max>arr[stack[cnt]]*(N-stack[cnt])?max:arr[stack[cnt]]*(N-stack[cnt]);
                cnt--;
            }
        printf("%lld\n",max);
    }
    return 0;
}
//Using Divide and Conquer
/*
#include <stdio.h>

long long split(int left, int right, long long *arr);

long long arr[1000000];

int main()
{
    while(1)
    {
        int N;
        scanf("%d",&N);
        if(N==0) break;
        for(int i=0;i<N;i++) scanf("%lld",arr+i);
        printf("%lld\n",split(0,N,arr));
    }

    return 0;
}



long long split(int left, int right, long long *arr)
{
    if(left+1< right)
    {
        int pivot=(left+right)/2;
        int l=pivot-1, r=pivot;
        long long height=arr[l]<arr[r]?arr[l]:arr[r], val, max=height*2;
        for(int i=3;i<right-left+1;i++)
        {
            if(l==left) val=arr[++r];
            else if(r==right-1) val=arr[--l];
            else if(arr[l-1]<arr[r+1]) val=arr[++r];
            else val=arr[--l];

            height=height<val?height:val;
            max=max>height*i?max:height*i;
        }
        long long max2=split(left,pivot,arr);
        long long max3=split(pivot,right,arr);

        max=max>max2?max:max2;
        max=max>max3?max:max3;

        return max;
    }

    return arr[left];
}*/