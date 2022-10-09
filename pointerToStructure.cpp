
#include <iostream>
#include <cstdlib>
using namespace std;

struct Rect
{
    int length;
    int breadth;
};
int main()
{
    Rect *ptr;
    // mem allocated in heap
   // mem allocated in heap// in C lang : ptr = (struct Rect *)malloc(sizeof(struct Rect)); 
    ptr=new Rect;
    ptr->length = 10;
    ptr->breadth = 20;
    cout << "lenght=" << ptr->length << " "
         << "breadth=" << ptr->breadth;
    return 0;
}