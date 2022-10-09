#include<iostream>
using namespace std;

int factorail(int n)
{
    if(n==0)
      return 1;
    else 
       return factorail(n-1)*n;  
}
int main()
{
    
    cout<<"fact : "<<factorail(-1);
}