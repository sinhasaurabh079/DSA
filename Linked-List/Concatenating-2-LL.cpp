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

void create2(int B[], int n)
{
    int i;
    Node *t, *last;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next; // or count(p->next);
    }
    return count;
}

void concat(Node *p, Node *q)
{
    // third=p; allows third pointer to access concatenated linkedlist
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    int B[] = {1, 2, 3, 4, 5};
    create2(B, 5);
    cout << "LL 1 : \n";
    Display(first);
    cout << "LL 2 : \n";
    Display(second);

    concat(first, second);

    cout << "Concatenated LL :\n";
    Display(third);

    return 0;
}