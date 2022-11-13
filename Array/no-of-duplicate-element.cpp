#include <iostream>
using namespace std;
/*
 for multiple duplicate elements, we need to count 
*/
int main()
{
    int a[] = {3, 4, 6, 6, 7, 10, 10, 10, 12,12};

    int n = sizeof(a) / sizeof(0);
    for (int i = 0; i < n - 1; i++) // n-1 bcoz hum 10 tk hi compare krenge
    {
        if (a[i] == a[i + 1])
        {
            int j = i + 1;
            while (a[j] == a[i])
                {j++;} // to traverse next elements
            cout <<a[i] << " is appearing " << j - i << " times.\n ";
            i = j - 1; // setting i to point next element, as loop incrementeed its value to n
        }
    }
    return 0;
}