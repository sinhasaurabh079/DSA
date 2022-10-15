#include<bits/stdc++.h>  // single header file that includes all header file
using namespace std;

void toh(int n ,int a,int b, int c)  // n=no of disc and a,b,c are the name of the towers
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        cout<<"From "<<a<<" to "<<c<<endl;
        toh(n-1,b,a,c);
    }

}
int main()
{
    toh(3,1,2,3);
    return 0;
}