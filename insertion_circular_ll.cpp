#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class node
{
public:
    int data;
    node*next;
};

void printll(node* n)
{
    node *tmp=n;
    do
    {
        cout<<tmp->data<<endl;
        tmp=tmp->next;
    }
    while(tmp!=n);

    free(tmp);
    
}

int main()
{
    node* head=NULL;
    node *second=NULL;
    node* third=NULL;

    head=(node*)malloc (sizeof(node));
    second=(node*)malloc (sizeof(node));
    third=(node*)malloc (sizeof(node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=head;

    printll(head);


}