#include<iostream>
using namespace std;

int pow(int m,int n)
{
    if(n==0)
      return 1;
     return pow(m,n-1)*m; 
}
int eff_pow(int m,int n)  // a more efficient way to
                       // calculate power
{
    if(n==0)
     return 1;
    if(n%2==0)
       return pow(m*m,n/2);
    else
      return m*pow(m*m,(n-1)/2);    
}
int main()
{
    // r will be overwrited till 10
    //int r =(2,3,4,5,6,7,10);
    cout<<pow(2,9);
    cout<<"\n"<<eff_pow(2,9);
    return 0;
}