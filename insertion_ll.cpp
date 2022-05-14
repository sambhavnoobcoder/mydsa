#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void printll(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

node *insertnodefirst(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

node *insertnodeindex(node *head, int data, int index)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head;
    int i = 0;

    while (i != index - 1) // moves pointer of p till the index iteratively.
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node *insertafternode(node *head, node *prevnode, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->next =prevnode->next;
        ptr->data = data;


    prevnode->next = ptr;

    return head;
}

node *insertnodeend(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head;
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printll(head);

    head = insertnodefirst(head, 56);

    cout << " " << endl;

    printll(head);

    head = insertnodeindex(head, 78, 1);

    cout << " " << endl;

    printll(head);

    head = insertnodeend(head, 102);

    cout << " " << endl;

    printll(head);

    head = insertafternode(head, second, 28);

    cout << " " << endl;

    printll(head);

    return 0;
}