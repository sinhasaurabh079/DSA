#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *head;

void create(int A[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head; // head points to itself initially
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        // maintaining the last with newly added linked list
        last->next = t;
        last = t;
    }
}

void Display(Node *h)
{
    do
    {
        cout << h->data<<" ";
        h = h->next;
    } while (h != head);
    cout << "\n";
}

void RDisplay(Node *h)
{
    static int flag=0;
    if(h!=head || flag==0)
    {
        flag=1;
        cout<<h->data<<" ";
        RDisplay(h->next);
    }
    flag=0;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6, 7};
    create(A, 6);

    cout << "Circular Linked List : ";
    Display(head);
    RDisplay(head);
    return 0;
}
