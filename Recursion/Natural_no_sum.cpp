#include<iostream>
using namespace std;

int sum(int n)
{
    if(n==0)
       return 0;
    else
        return sum(n-1)+n;  
}
int IterSum(int n)
{
    int s=0;
    int i;
    for(i=1;i<=n;i++)
        s+=i;
    return s;    
}
int main()
{
    int r;
    r=sum(5);
    cout<<"sum : "<<r;
    r=IterSum(5);
    cout<<"\nIterative sum : "<<r;
    return 0;
}