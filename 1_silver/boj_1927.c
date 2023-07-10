#include <stdio.h>

int heap[100001];
enum {left=1,right,none=0,minus,plus};

int parent(int i);
int child(int i,int direction);
int count(int flag);
void minHeapify(int i, int *heap);
void insert(int data, int* heap);

int parent(int i)
{
    return (i-1)>>1;
}

int child(int i,int direction)
{
    return ((i<<1)+direction)>count(none)?-1:(i<<1)+direction;
}

void minHeapify(int i, int *heap)
{
    int min;
    while(child(i,left)!=-1)
    {
        if(child(i,right)==-1) min=child(i,left);
        else min=heap[child(i,left)]<heap[child(i,right)]?child(i,left):child(i,right);

        if(heap[i]<=heap[min]) break;
        int temp=heap[i];
        heap[i]=heap[min];
        heap[min]=temp;
        i=min;
    }   
    
}
/*
void minHeapify(int i, int *heap)
{
    int min;
    if(child(i,left)==-1) return;
    else if(child(i,right)==-1) min=child(i,left);
    else min=heap[child(i,left)]<heap[child(i,right)]?child(i,left):child(i,right);
    if(heap[i]>heap[min])
    {
        int temp=heap[i];
        heap[i]=heap[min];
        heap[min]=temp;
        minHeapify(min,heap);
    }
    
}
*/

void insert(int data, int* heap)
{
    int i=count(plus);
    while(i!=0 &&data<heap[parent(i)])
    {
        heap[i]=heap[parent(i)];
        i=parent(i);
    }
    heap[i]=data;
}

int count(int flag)
{
    static int length=-1;
    if(flag==plus) length++;
    else if(flag==minus) length--;

    return length;
}

int extract(int *heap)
{
    int val=heap[0];
    heap[0]=heap[count(minus)+1];
    minHeapify(0,heap);
    return val;
}


int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        int M;
        scanf("%d",&M);
        if(M==0)
        {
            if(count(none)==-1) printf("0\n");
            else printf("%d\n",extract(heap));
        }
        else insert(M,heap);
    }
}


