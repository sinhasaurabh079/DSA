#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
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

bool isLoop(Node *first)
{
    Node *p, *q;
    // p is slow pointer and q is fast pointer

    p = q = first;

    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (p && q && p != q);

    if (p == q)
        return true;
    else
        return false;
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    Node *t1, *t2;
    t1 = first->next->next;             // t1=30
    t2 = first->next->next->next->next; // t2 =50
    t2->next = t1;
    // loop is created between 30 and 50

    cout << "LL 1 : \n";
    // Display(first);    // infinite times ll is printed due to loop between 30 and 50

    cout << "Is loop present :" << (isLoop(first) ? " Yes \n" : " No \n");

    return 0;
}