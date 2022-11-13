#include <iostream>
using namespace std;

int main()
{
    int a[]={6,7,8,9,11,12,15,16,17,18,19};
    int diff=a[0]-0;
    int n= sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        if(a[i]-i!=diff)      // to check diff
        {
            while(diff<a[i]-i)   // logic to print missing elements
            {
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }

}