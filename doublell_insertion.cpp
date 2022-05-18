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

node* insert_first(node * head, int data)
{
    node *p = head;
    p = (node*) malloc(sizeof(node) );
    
        p->data=data;
        p->previous=NULL;
        p->next=head;
        head->previous=p;
        return p;
}
void insert_specified(node * head,int item,int loc)  
{  
    


     
   struct node *ptr = (struct node *)malloc(sizeof(struct node));  
   struct node *temp;   
   int i;   
     
       temp=head;  
       for(i=0;i<loc-1;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\ncan't insert\n");  
               return;  
           }  
       }  
       ptr->data = item;  
       ptr->next = temp->next;  
       ptr -> previous = temp;  
       temp->next = ptr;  
       temp->next->previous=ptr; 
   
 
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

    cout <<" "<<endl;

    head = insert_first(head,20);

    print_from_start(head);

    cout<<" "<<endl;

    insert_specified(head,10,1);

    print_from_start(head);
}