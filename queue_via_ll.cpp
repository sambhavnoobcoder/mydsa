#include <iostream>
#include <cstdlib>
using namespace std;
int counting;
int max_elements=4;

class node 
{
    public:
    int data ;
    node * next ;
};

class stack
{
    public:
    int f;
    int r;
    int * arr;
};

node * f =NULL;
node * r= NULL;

int isfull(node * f,node * r)
{
    if(counting==max_elements)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int isempty(node * f)
{
    if( f==NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


void enqueue(int val)
{
    node * n = (node * ) malloc ( sizeof ( node));
    if(isfull(f,r))
    {
        cout <<"queue is full "<<endl;
    }
    else
    { 
        n->data= val;
        n->next =NULL;

        if (isempty(f))
        {
            f=r=n;
        }
        else
        {
            r->next=n;
            r=n;
        }
        counting++;
        cout <<val<<endl;

    }
}

void dequeue()
{
    if(isempty(f))
    {
        cout <<"cant deque as queue is empty "<<endl;
    }

    else 
    {
        int val;
        node * n = (node *) malloc (sizeof (node));
        //f=f->next;
        n->data=f->data;
        f=f->next;
        val=n->data;
        free (n);

        cout <<val<<endl;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    cout <<"the dequeued element is "<<endl; 
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}