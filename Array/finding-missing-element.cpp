#include <iostream>
using namespace std;

 // single missing element
// arr = 1 2 3 4 5 6 8 9 10 11 12
// 7 is missing
// sum(n)-present sum = missing elemnt , n is natural no

// if the natural starts from 1 
int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
   
    int missing, n = 12;
    int sum1 = n * (n + 1) / 2;
    int sum2 = sum(arr, 11);
    missing = sum1 - sum2;
    cout << "Missing element in natural no's array is " << missing<<endl;
    // randow satrt of natural no
     int arr1[] = {6,7,8,9,11,12};
     int diff,low=6,high=12;   // n=6
     diff=low-0;
     for(int i=0;i<6;i++)
     {
        if(arr1[i]-i!=diff)
        {
            cout<<"missing element "<<i+diff<<endl;
            break;
        }
     }
    
    
    return 0;
}


