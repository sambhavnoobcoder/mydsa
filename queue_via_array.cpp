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

int enque(queue * q , int val)
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

int deque(queue * q)
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

int main()
{
    queue q;
    q.size=100;
    q.f=q.r=-1;
    q.arr =(int *)malloc (q.size* sizeof(int ));
    cout<<"the elements in the queue are"<<endl;
    
    enque(&q,1);
    enque(&q,2),
    enque(&q,3);

    cout<<"the element removed from the queue is "<<endl;
    deque(&q);
}