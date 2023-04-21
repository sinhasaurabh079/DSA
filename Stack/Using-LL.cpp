#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    
};
 class stack
{
private:
    Node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
    int peek();
    int isFull();
    int isEmpty();
};

void stack::push(int x)
{
    Node *t = new Node;
    // kuki heap use kr rhe hum toh memory dynamically allocate hogi
    // overflow tb hoga jb memory bhar jayegi tb new node null create hoga
    if (t == nullptr)
        cout << "Full";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack::pop()
{
    Node *p;
    int x = -1;
    if (top == NULL)
        cout << "Empty";
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int stack::isFull()
{
    Node *t = new Node;
    // if node created then t has non zero value otherwise it is 0
    int r = t ? 1 : 0;
    return r;
}
int stack::isEmpty()
{
    return top==NULL;
}

int stack::peek()
{
    if(!isEmpty())
       return top->data;
    else
       exit(1);   
}
void stack::display()
{
    Node *temp;
    if(isEmpty())
      cout<<"underflow";
    else{
        temp=top;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL)
             cout<<" -> ";
        }
    }  
}
int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    cout<<"\ntop elemenet : "<<s.peek()<<"\n";

    cout<<s.pop()<<"\n";
    s.display();
    return 0;
}
/*
30 -> 20 -> 10
top elemenet : 30
30
20 -> 10
*/