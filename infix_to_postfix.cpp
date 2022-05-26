#include<iostream>
#include<cstdlib>
#include <string.h>
using namespace std;

class stack 
{
    public:
    int top;
    int size;
    char * arr;
};

int istop( stack * s)
{
    return s->arr[s->top];
}

int isbottom(stack * s)
{
    return s->arr[0];
}

int isfull(stack * s)
{
    if( s->top ==s->size-1)
    {
        return 1;
    }

    else 
    {
        return 0;
    }
} 

int isempty(stack * s)
{
    if (s->top== -1)
    {
        return -1;
    }

    else
    {
        return 0;
    }
}

void push(stack *s , char val)
{
    if(isfull(s))
    {
        cout <<"stack overflow"<<endl;
    }
    else 
    {
        s->top++;
        s->arr[s->top]=val;
    }

}

int pop(stack *s)
{
    char tmp;
    if(isempty(s))
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        tmp=s->arr[s->top];
        s->top--;
    }
    return tmp;

}

int preference(char c)
{
    if (c=='*' || c=='/')
    {
        return 2;
    }
    else if (c=='+' || c=='-')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int isOperator(char c)
{
    if(c=='*' ||c=='/' || c=='+' ||c=='-' )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

char * infixToPostfix(char * infix)
{
    stack * s=(stack*) malloc (sizeof (stack));
    s->size=100;
    s->top=-1;
    s->arr=(char*) malloc (s->size *sizeof(stack));
    char *postfix =(char *) malloc(strlen(infix)+1 *sizeof (char)); 
    int i=0;    //initialise for infix
    int j=0;    //initialise for postfix

    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else 
        {
            if(preference(infix[i])>preference(istop(s)))
            {
                push(s,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(s);
                j++;
            }
        }
    }
    while(!isempty(s))
    {
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char * infix = "x-y/z-k*d";
    cout<<"postfix is %s "<<infixToPostfix(infix)<<endl;
    return 0;
}