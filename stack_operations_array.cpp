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

int peek(stack* ptr , int i)
{
    if(ptr->top-i+1 <0)
    {
        cout<<"invalid input"<<endl;
        return -1;
    }

    else 
    {
        //cout<<ptr->arr[ptr->top-i+1]<<endl;
        return ptr->arr[ptr->top-i+1];
    }
}

int stacktop(stack *p)
{
    if(isempty(p))
    {
        cout<<"operation not possible as stack is empty"<<endl;
        return -1;
    }

    else
    {
        cout<<p->arr[p->top]<<endl;   //add +1 to compensate for top satrting from -1 and not 0
        return 1;
    }
}

int stackbottom(stack *p)
{
    if(isempty(p))
    {
        cout<<"operation not possible as stack is empty"<<endl;
        return -1;
    }

    else
    {
        cout <<p->arr[0]<<endl;
        return 1;
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
    push(s,4);
    push(s,6);
    push(s,8);
    push(s,10);
    push(s,12);
    push(s,14);
    push(s,16);
    push(s,18);
    push(s,20);

    isempty(s);
    isfull(s);

    //pop(s);

    isempty(s);
    isfull(s);


    for (int i=0 ; i< s->size ; i++)
    {
        cout<<peek(s,i)<<endl;
    }

    cout <<"lol last in first out is visible here "<<endl;

    stacktop(s);

    cout<< " "<<endl;

    stackbottom(s);

    


}