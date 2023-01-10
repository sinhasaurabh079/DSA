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

int Delete(Node *p, int index)
{
    Node *q;
    int x;

    if (index < 0 && index > Length(p))
        return -1;

    if (index == 1)
    {
        while (p->next != head)
            p = p->next;

        x = head->data;
        // if it is a singlr node
        if (head == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next; // last node pointing to next node of head
            delete head;
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
            p = p->next;

        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}
int main()
{
    int A[] = {2, 3, 4, 5, 6, 7};
    create(A, 6);

    cout << "Circular Linked List : ";
    Display(head);
    // RDisplay(head);  // 2 3 4 5 6 7

    // Insert(head,0,1);  // 1 2 3 4 5 6 7
    Delete(head, 4);
    Display(head);
    return 0;
}
