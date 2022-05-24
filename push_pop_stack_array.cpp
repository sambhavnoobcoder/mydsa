#include<iostream>
#include<cstdlib>
using namespace std;

class stack
{
    public:
    int size;
    int top;
    int *arr;
};

int isempty(stack *ptr)
{
    if(ptr->top ==-1)
    {
        cout<<"stack underflow"<<endl;
        return 1;
    }

    else 
    {
        return 0;
    }
}


int isfull(stack *ptr)
{
    if(ptr->top ==ptr->size-1)
    {
        cout<<"stack overflow"<<endl;
        return 1;
    }

    else 
    {
        return 0;
    }
}

void push(stack * ptr , int val)
{
    if(isfull(ptr))
    {
        cout<<"operation not possible as stack is full"<<endl;

    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

void pop(stack *ptr )
{
    if(isempty(ptr))
    {
        cout<<"operation not possible as stack is empty"<<endl;
    }

    else
    {
        int val;
        val=ptr->arr[ptr->top];
        ptr->top--;
    }
}

int main()
{
    stack * s = (stack * ) malloc (sizeof(stack));
    s->size= 10;
    s->top= -1;
    s->arr=(int * ) malloc( s->size * sizeof(int ));
    isempty(s);
    isfull(s);

    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);
    push(s,2);

    isempty(s);
    isfull(s);

    pop(s);

    isempty(s);
    isfull(s);



}