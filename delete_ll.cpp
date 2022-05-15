#include <iostream>
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

node *deletell(node *ptr, int index)
{
    node *p = ptr;

    if (index == 0)
    {
        ptr = ptr->next;
        free(p);
    }
    for (int i = 0; p != NULL && i < index - 1; i++)
    {
        p = p->next;
    }
    node *next = p->next->next;
    p->next = next;
    return ptr;
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

    cout << " " << endl;

    head = deletell(head, 0);

    printll(head);
}
