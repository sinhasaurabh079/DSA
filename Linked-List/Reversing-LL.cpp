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
// method 1: reversing the element of the ll
void Reverse1(Node *p)
{
    int *A, i = 0; // ptr bcoz we dont the size of the linked list, ptr will help to traverse
    Node *q = p;

    A = new int[count(p)]; // creating array of size of ll

    // copy data from ll to array
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p; // to again traverse ll

    i--; // to point lasst node

    // copying data from array(last to first) to ll
    while (q != NULL)
    {
        q->data = A[i]; // --i to point last element
        q = q->next;
        i--;
    }
}

// method 2: reversing the links
// sliding pointer method (3 pointer)
// p for traversing
// q,r for linking by keeping record of visited nodes
void Reverse2(Node *p)
{
    Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next; // traversing

        q->next = r; // linking q to r node
    }
    first = q; // q becomes now first node
}

// recursive version of Reverse2
// during calling we traverse the linked list
// in returning we reverse the links
// example of  head recursion
void Reverse3(Node *q, Node *p)
{
    if (p != NULL)
    {
        Reverse3(p, p->next);
        // equivalent to q=p and p = p->next

        p->next = q; // linking the last node to second last ans so on..
    }
    else
        first = q;
}
int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    cout << "LL : \n";
    Display(first);

    // Reverse1(first);
    // Reverse2(first);
    Reverse3(NULL, first);
    cout << "Reversed LL : \n";
    Display(first);

    return 0;
}