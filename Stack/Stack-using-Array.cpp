#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(Stack *st)
{
    cout << "Enter size:";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void Display(Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}

void push(Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "Stack Underflow\n";
    else
        x = st->s[st->top--];
    return x;
}

int peek( Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = st.s[st.top - index + 1];

    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull( Stack st)
{
    return st.top == st.size - 1;
}
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.s[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("%d \n", peek(st, 2));

    Display(st);
    return 0;
}