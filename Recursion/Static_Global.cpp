#include<iostream>
using namespace std;
int x=0;  //global variable also give same output as given
          //static variabble
int fun( int n){
    //static int x=0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}
int main()
{
    int r;
    r=fun(5);
    cout<<r<<endl;
    return 0;
}