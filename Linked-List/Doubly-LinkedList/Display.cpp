#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

void create(int A[],int n)
{
    Node *t,*last;

    first=new Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
    }
}

void Display(Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int Length(Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);

    cout<<"\nLength of Doubly LL : "<<Length(first);

    cout<<"\nDoubly LL : ";
    Display(first);

    return 0;
}
