#include<bits/stdc++.h>
using namespace std;

/*  this is the golden ratio or the linear recurrence solution to find the 
    fibonacci series nth number
    formula = 1/sqrt(5)*((1+ (under root 5 )/2)^n - (1 - (under root 5 )/2)^n)

    so the time complexity is
    t(n) = O(1.6180)^n    
    expln : (1 - (under root 5 )/2)^n) as n increases the aboce part
        will become near to zero and hence we will neglect it for bigger n 
        and 1/sqrt(5) will be neglected  as it a constant    */

int fibo_formula(int n )  
{
   return (pow(((1 + sqrt(5))/2),n) - pow(((1 - sqrt(5))/2),n))/sqrt(5);
}

int main()
{
  int n;
  cin>>n;  // upto which term you want to print fibonacci series
  for(int i=0;i<n;i++)
   cout<<fibo_formula(i)<<endl;
   return 0;
  
}