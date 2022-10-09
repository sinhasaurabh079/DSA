#include<iostream>
using namespace std;

void fun(int n){
  if(n>0){
    cout<<n<<" ";
    fun(n-1); // first it will called and returned in every instance
    fun(n-1); //it called by first in returning
  }           // time - O(2^n) and space - O(n)
}
int main()
{
    fun(3);
    return 0;
}