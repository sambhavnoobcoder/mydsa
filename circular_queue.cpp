#include <iostream>
#include <cstdlib>
using namespace std;

class queue
{
public:
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int enque(queue *q, int val)
{
    if (isfull(q))
    {
        cout << "enqueueing is not possible as queue is full" << endl;
        return 1;
    }

    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        cout << q->arr[q->r] << endl;
        return 0;
    }
}

int deque(queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        cout << "cant dequeue as queue is empty " << endl;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        cout << a << endl;
    }
    return a;
}

int main()
{
    queue q;
    q.size = 4;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(queue));
    enque(&q, 0);
    enque(&q, 1);
    enque(&q, 2);
    enque(&q, 2);

    deque(&q);
}