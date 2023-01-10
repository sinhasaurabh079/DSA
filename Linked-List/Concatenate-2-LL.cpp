#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Concat( Node *p, Node *q)
{
    third=p;

    while(p->next !=NULL)
      p=p->next;
   
    p->next=q;

}


int main()
{

    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};
    create(A, 5);
    create2(B, 5);
    
    Concat(first, second);

    Display(third);

    return 0;
}