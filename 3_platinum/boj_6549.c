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