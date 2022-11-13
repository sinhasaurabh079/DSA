#include <iostream>
using namespace std;
int main()
{
    int a[] = {3, 6, 8, 8, 10, 12, 14, 14, 14, 16};
    int max = 16;
    int h[max+1] = {0};
    int n = sizeof(a) / sizeof(0);
    for (int i = 0; i < n; i++)
    {
        h[a[i]]++;
    }
   
    for (int i = 0; i <= max; i++)
    {
        if (h[i] > 1)
            cout << i << " appears " << h[i] << " times.\n";
    }
    return 0;
}