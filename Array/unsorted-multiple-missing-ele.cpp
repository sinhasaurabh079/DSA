#include <iostream>
using namespace std;

int main()
{
    int a[] = {2, 5, 7, 12, 3, 8, 6};
    int low = 2;   // can be calculated by min
    int high = 12; // by max
    int n = 7;
    int hash[high]={0};
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    cout << "missing element are : ";
    for (int i = low; i <= high; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}