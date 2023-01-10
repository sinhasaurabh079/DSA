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
        cout << h->data << " ";
        h = h->next;
    } while (h != head);
    cout << "\n";
}

void RDisplay(Node *h)
{
    static int flag = 0;
    if (h != head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}

void Insert(Node *p, int index, int x)
{
    Node *t;

    if (index < 0 && index > Length(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL) // if ll is empty
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next; // making last node to point first created node
            p -> next = t;
            t->next = head; // t points to first node
            head = t;       // as t becomes first node
        }
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int main()
{
    int A[] = {2, 3, 4, 5, 6, 7};
    create(A, 6);

    cout << "Circular Linked List : ";
    Display(head);
    //RDisplay(head);  // 2 3 4 5 6 7

    //Insert(head,0,1);  // 1 2 3 4 5 6 7 
    Insert(head,4,4);
    Display(head);
    return 0;
}
