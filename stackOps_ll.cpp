#include<iostream> 
#include<cstdlib>
using namespace std;

class stack 
{
    public:
    int top;
    int data;
    int *arr;
};

class node 
{
    public:
    int data;
    node * next;
};

int isempty(node *head) 
{
    if(head==NULL)
    {
        return 1;
    }

    else 
    {
        return 0;
    }
}

int isfull(node *top)
{
    node *p= (node * ) malloc ( sizeof (node ));
    if ( p==NULL)
    {
        return 1;
    }

    else 
    {
        return 0;
    }
}

node *push(node *head , int p)
{
    if (isfull(head))
    {
        cout<<"stack overflow"<<endl;
    }

    else 
    {
        node *n = (node * )malloc (sizeof (node ));
        n->next=head;
        n->data= p;
        head=n ;
    }
    return head;
}

void pop(node **head )
{
    if(isempty(*head))
    {
        cout <<" stack underflow"<<endl;
    }

    else 
    {
        node *n = (node*) malloc (sizeof (node ));
        n=*head;
        *head= (*head)->next;
        int tmp= n->data;
        free(n);
        cout << tmp<<endl;
    }       
}

void peek(node *p,int index)
{
    if(isempty(p))
    {
        cout<<"stack underflow"<<endl;
    }

    else 
    {
        node * h=(node *)malloc( sizeof(node));
        h=p;
        int counter=0;

        
        while(counter!=index)
        {
            h=h->next;
            counter++;
        }

        int tmp;
        tmp = h->data;
        cout<<tmp <<endl;
    } 
}

void isbottom(node * head)
{
    
        node* n = (node *)malloc ( sizeof(node));
        n=head;

        while(n->next!=NULL)
        {
            n=n->next;
        }
        cout<<n->data<<endl;
}

void istop(node * head )
{
    cout<<head->data<<endl;     //could also have used peek(head,0) for the same result.

}


void printll(node * head )
{
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head =head->next;
    }
}
int main ()
{
    //initialise a hardcoded linked list
    node *head=NULL;
    head=push(head,1);
    head = push(head ,2);
    head =push (head ,3);

    printll(head);

    cout <<"the popped element is  ";
    pop(&head); //passing address is necessary as we need the base vlaue to chanfe .conept of call by refrence than call by value.

    cout<<"the new stack is"<<endl;

    printll(head);

    cout<<"the element at the first index is"<<endl;

    peek(head,0);

    cout<<"the bottom element is ";

    isbottom(head);

    cout <<"the top element is ";

    istop(head);

}