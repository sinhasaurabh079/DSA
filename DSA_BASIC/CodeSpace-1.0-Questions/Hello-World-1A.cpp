#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if(n%2==0)
      for(int i=0;i<n/2;i++) cout<<"Hello World !\n";
    else 
      for(int i=0;i<2*n;i++) cout<<"Hello World !\n";

     return 0;   
}
