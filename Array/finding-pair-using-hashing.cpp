#include <iostream>
using namespace std;

int main()
{
    int k = 10, count = 0;
    int a[] = {6, 3, 8, 10, 7, 5, 2, 9, 14};
    int n = sizeof(a) / sizeof(a[0]);
    int max=14;
    int hash[max+1]={0};
    for(int i=0;i<n;i++)
    {
        hash[a[i]]++;
    }
for(int i=0;i<n;i++)
{
    if(hash[k-a[i]]!=0&&k-a[i]>0 )
    {
        cout<<a[i]<<" + "<<k-a[i]<<" = "<<k<<endl;
        hash[a[i]]=0;
        count++;
    }
}

    if (count == 0)
        cout << "No pair present!";
    return 0;
}