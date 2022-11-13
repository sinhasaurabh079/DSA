#include<iostream>
using namespace std;
void  funA(int);
void funB(int );
void funA(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funB(n-1);
    }
}
void funB(int n)
{
    if(n>1)
    {
        cout<<n<<" ";
        funA(n/2);
    }
}

int main()
{
    funA(20); // a calls b and funb will a again and it repeates
}