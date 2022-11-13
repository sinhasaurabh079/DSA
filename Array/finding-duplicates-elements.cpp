#include<iostream>
using namespace std;
/* note : array is sorted
 for multiple duplicate elements, we need to print it only once
 thus we stored the duplicte element in lastdup
*/
int main()
{
    int a[]={3,4,6,6,7,10,10,10,12};
    int lastduplicate=0;
    int n= sizeof(a)/sizeof(0);
    for(int i=0;i<n;i++)
    {
        if (a[i]==a[i+1] && a[i]!= lastduplicate)
        {
            cout<<a[i]<<" ";
            lastduplicate=a[i];
        }
    }
    return 0;
}