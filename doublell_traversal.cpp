#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
    public:
    int data;
    node* previous;
    node* next;
};

void print_from_start(node * ptr)
{
    while( ptr->next!=NULL)
    {
        cout<<ptr->data << endl;
        ptr=ptr->next;
    }

    cout<<ptr->data<<endl;
}

void print_from_end(node *ptr)
{
    while(ptr->previous !=NULL )
    {
        cout<<ptr->data<<endl;
        ptr=ptr->previous;
    }

    cout<<ptr->data<<endl;

} 



int main()
{
    node*head=NULL;
    node* first=NULL;
    node* second=NULL;

    head=(node*)malloc (sizeof(node));
    first=(node*)malloc (sizeof(node));
    second=(node*)malloc (sizeof(node));

    head->previous=NULL;
    head->data=0;
    head->next=first;

    first->previous=head;
    first->data=1;
    first->next=second;

    second->previous=first;
    second->data=2;
    second->next=NULL;

    print_from_start(head);

    cout <<" "<<endl;

    print_from_end(second);


}