#include <iostream>
using namespace std;

int main()
{
    int a[] = {8, 3, 6, 4, 5, 6, 8, 2, 7}; // unsorted array
    int n = sizeof(a) / sizeof(a[0]);
    int max=8;
    int hash[max+1]={0};
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    for (int i =0 ; i <= max; i++)
    {
        if (hash[i] > 1)
            cout << i << " appears " << hash[i] << " times.\n";
    }
    return 0;
}