#include<iostream>
#include<cstdlib>
using namespace std;


class queue
{
    public:
    int size;
    int f;
    int r;
    int * arr;
};

int isfull(queue * q)
{
    if(q->r ==q->size-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int isempty(queue * q)
{
    if(q->r== q->f)
    {
        return 1;
    }

    else 
    {
        return 0;
    }
}

int enqueR(queue * q , int val)
{
    if(isfull(q))
    {
        cout<<"enqueueing is not possible as queue is full"<<endl;
        return -1;
    }

    else 
    {
        q->r=q->r+1;
        q->arr[q->r]=val;
        cout<<q->arr[q->r]<<endl;
        return q->arr[q->r];
        //cout<<"running"<<endl;
    }
}

int enqueL(queue * q , int val )
{
    if(isfull(q))
    {
        cout<<"enqueueing is not possible as queue is full"<<endl;
        return -1;
    }
    else 
    {
        q->f=q->f-1;
        q->arr[q->f]=val;
        cout<<q->arr[q->f]<<endl;
        //q->f=q->f-1;
        return q->arr[q->f];
    }
}

int dequeL(queue * q)
{
    int a=-1;
    if(isempty(q))
    {
        cout << "cant dequeue as queue is empty "<<endl;
    }
    else 
    {
        q->f++;
        a=q->arr[q->f];
    }
    cout<<a<<endl;
    return a;
}

int dequeR(queue *q)
{
    int a=-1;
    if(isempty(q))
    {
        cout << "cant dequeue as queue is empty "<<endl;
    }
    else 
    {
        q->r--;
        a=q->arr[q->r];
    }
    cout <<a<<endl;
    return a;
}



int main()
{
    queue q;
    q.size=3;
    q.f=q.r=-1;
    q.arr =(int *)malloc (q.size* sizeof(int ));
    cout<<"the elements in the queue are"<<endl;
    
    enqueR(&q,1);
    enqueR(&q,2);
    enqueR(&q,3);


    cout<<"the element removed from the queue is "<<endl;
    dequeL(&q);
    dequeL(&q);
    dequeL(&q);
}