#include <iostream>
#include <cstdlib>
using namespace std;

class stack
{
public:
    int size;
    int top;
    int *arr;
};

int isempty(stack arr)
{
    if (arr.top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int isfull(stack arr)
{
    if (arr.top == arr.size - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    stack s;     // i initialised an aintire stucture to the stack but it is also possible to do the same with the help of a pointer
    s.size = 80; // initialise the stack
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    if (isempty(s))
    {
        cout << "empty" << endl;
    }

    else
    {
        cout << "full" << endl;
    }

    // manually pushing elements into an array

    s.arr[0] = 7;
    s.top++;

    /*note the code gives an output empty as when the stack is checked
    it is empty , after the function is run , the insertion takes
    place*/
}