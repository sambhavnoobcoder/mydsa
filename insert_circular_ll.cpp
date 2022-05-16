#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void printll(node *last)
{
    node *p;

    // If list is empty, return.
    if (last == NULL)
    {
        cout << "Circular linked List is empty." << endl;
        return;
    }
    p = last->next; // Point to the first Node in the list.

    // Traverse the list starting from first node until first node is visited again

    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != last->next);
    if (p == last->next)
        cout << p->data;
    cout << "\n\n";
}

node *addToEmpty(node *last, int data)
{
    // if last is not null, then the list is not empty, do return
    if (last != NULL)
        return last;

    // Creating a node dynamically.
    node *temp = (node *)malloc(sizeof(node));

    // Assigning the data.
    temp->data = data;
    last = temp;

    // Creating the link.
    last->next = last;

    return last;
}

node *insertnodefirst(node *last, int data)
{
    // last ==NULL means the list is empty , so call the addToEmpty function to create a node fot the given element and return the ll
    if (last == NULL)
        return addToEmpty(last, data);

    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    return last;
}

node *insertnodeend(node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

node *insertafternode(node *last, int new_data, int after_item)
{
   //return null if list is empty
   if (last == NULL)
   return NULL;
  
   node *temp, *p;
   p = last -> next;
   do
   {
      if (p ->data == after_item)
      {
         temp = (node*) malloc(sizeof(node));
         temp -> data = new_data;
         temp -> next = p -> next;
         p -> next = temp;
        
         if (p == last)
         last = temp;
         return last;
       }
   p = p -> next;
 } while(p != last -> next);
  
   cout << "The node with data "<<after_item << " is not present in the list." << endl;
   return last;
  
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
    third->next = head;

    printll(head);

    cout << " " << endl;

    head = insertnodefirst(head, 56);

    cout << " " << endl;

    printll(head);

    // head = insertnodeindex(head, 78, 1);

    cout << " " << endl;

    // printll(head);

    head = insertnodeend(head, 102);

    cout << " " << endl;

    printll(head);

     head = insertafternode(head, 12, 3);

     cout << " " << endl;

     printll(head);

    return 0;
}