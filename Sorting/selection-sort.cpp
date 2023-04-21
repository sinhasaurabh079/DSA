#include <iostream>

using namespace std;

template <class T>
void Print(T &vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int a[], int n)
{
    int i;       // for passing
    int j;       // for comparison
    int min_idx; // to store min ele index

    for (i = 0; i < n - 1; i++)
    {
        // lets the current idx has min ele
        // supposing this we find whether min to this exist or not
        // if exist min_idx=j otherwise nothing
        min_idx = i;
        for(j=i+1;j<n;j++){
            if(a[j] < a[min_idx])
                min_idx=j;
        }  
        if(min_idx!=i)
            swap(&a[min_idx],&a[i]);
    }
}
int main()
{

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, "\t\tA");

    selectionSort(A, n);
    Print(A, n, " Sorted A");

    return 0;
}