#include <stdio.h>
#include <string.h>

int stack[1000001];
char sol[1000001];
char arr[1000001];
char explosion[37];
int main()
{
    scanf("%s",arr);
    scanf("%s",explosion);
    int arr_length=strlen(arr);
    int exp_length=strlen(explosion);
    int stack_cnt=0,sol_cnt=0;
    for(int i=0;i<arr_length;i++)
    {
        if(arr[i]==explosion[stack[stack_cnt]])
        {
            if(stack[stack_cnt]==exp_length-1)
            {
                stack[stack_cnt]=0;
                if(stack_cnt!=0) stack_cnt--;
            }
            else stack[stack_cnt]++;
        }
        else if(arr[i]==explosion[0])
        {
            stack[++stack_cnt]=1;
        }

        else
        {
                for(int j=0;j<stack_cnt+1;j++)
                {
                    memcpy(sol+sol_cnt,explosion,stack[j]);
                    sol_cnt+=stack[j];
                    stack[j]=0;
                }
                stack_cnt=0;
                sol[sol_cnt++]=arr[i];
        }
        
    }
    for(int j=0;j<stack_cnt+1;j++)
                {
                    memcpy(sol+sol_cnt,explosion,stack[j]);
                    sol_cnt+=stack[j];
                    stack[j]=0;
                }


    sol[sol_cnt]=0;
    if(sol_cnt==0) printf("FRULA");
    else printf("%s",sol);
}



