#include <iostream>
using namespace std;

// C++ Implementaton
class Array
{
private:
    int A[10];
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void display();
    void append(int x);
    void insert(int index, int x);
    int delete_element(int index);
    int linear_search(int key);
    int BinarySearch(int key);
    int rec_binary_search(int a[], int l, int h, int key);
    int get();
    int set();
    int max();
    int min();
    int sum();
    float avg();
    void reverse();
    void reversebyswap();
    int isSorted();
    void rearrange();
    Array *Merge(Array *arr2);
    Array *Union(Array *arr2);
    Array *Intersection(Array *arr2);
    Array *Difference(Array *arr2);
};

void Array::display()
{
    cout << "\nElements are:";
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
}

void Array::append(int x)
{
    if (length < size)
        A[length++] = x;
}
void Array::insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array::delete_element(int index)
{
    int x = 0;
    if (index >= 0 && index <= length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }
    return 0;
}

void Array:: swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Array:: linear_search(int key)
{
    for (int i = 0; i < length; i++) // -> is used instead of . operatr because *arr is a pointer, (->) used to access via pointer
    {                                // . operator is used to access data members n methods by objects
        if (key == A[i])
        {
            swap(&A[i], &A[i - 1]); // to improve linear search by transportation for repeative key element
            return i;
        }
    }
    return -1;
}
int Array ::BinarySearch(int key)
{
    int l, mid, h;
    l = 0, h = length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Array::rec_binary_search(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return rec_binary_search(a, l, mid - 1, key);
        else
            return rec_binary_search(a, mid + 1, h, key);
    }
    return -1;
}

int Array ::get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void  Array ::set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}
int Array :: max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    return max;
}
int Array ::min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (min > A[i])
            min = A[i];
    }
    return min;
}
int Array ::sum()
{
    int s = 0;
    for (int i = 0; i < length; i++)
        s += A[i];
    return s;
}
float Array ::avg()
{
    return (float)sum() / length;
}

void Array ::reverse()
{
    int *B;
    B = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (int i = 0; i < length; i++)
        A[i] = B[i];
}
void Array ::reversebyswap()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}

void Array ::insertsort( int x)
{
    int i = length - 1;
    if (length ==size)
        return;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i]; // shifting to create gap for insertion
        i--;
    }
    A[i + 1] = x; // jb shi jaga pr pahoch jao tb
    length++;
}
int Array ::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

void Array ::rearrange()
{
    int i, j;
    i = 0;
    j = length - 1;
    while (i < j)
    {
        while (A[i] < 0) // for -ve number
            i++;
        while (A[j] >= 0) // for +ve number
            j--;
        if (i < j) // for rearrange
            swap(&A[i], &A[j]);
    }
}

Array* Merge(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(length+arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    // for remaining elements if any
    for (; i < length; i++)
        arr3->A[k++] = A[i++];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = length + arr2.length;
    arr3->size = 10;
    return arr3;
}


Array *Union(Array  *arr2)
{
    int i, j, k;
    i = j = k = 0;
    *arr3 = new Array;
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j]) // set b element is greater
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2.A[j]) // set a element greater
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = A[i++]; // if elements are same
            j++;
        }
    }
    // for remaining elements if any
    for (; i < length; i++)
        arr3->A[k++] = A[i++];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

Array *Intersection(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    *arr3 = new Array;
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j]) // set b element is greater
            i++;
        else if (A[i] > arr2.A[j]) // set a element greater
            j++;
        else if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++]; // if elements are same
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

Array *Difference(Array  *arr2)
{
    int i, j, k;
    i = j = k = 0;
    *arr3 = new Array;
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j]) // set b element is greater
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2.A[j]) // set a element greater
            j++;
        else
        {
            i++;
            j++;
        }
    }
    // for remaining elements if any
    for (; i < length; i++)
        arr3->A[k++] = A[i++];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    arr = {{2, 3, -1, 4, 5, -4, 6}, 10, 7};
    arr1 = {{1, 3, 5, 7}, 10, 4};
    arr2 = {{2, 4, 6, 8}, 10, 4};
    *arr3;
    // append(&arr, 10);
    // display(arr);
    // insert(&arr, 5, 10);
    // display(arr);
    // cout << "\n Deleted element:" << delete_element(&arr, 4);
    // cout << "\n By linear search: Element found at " << linear_search(&arr, 5) << "th index.";
    // cout << "\n By binary search: Element found at " << BinarySearch(arr, 5) << "th index";
    // cout << "\n By recursive binary search: Element found at " << rec_binary_search(A, 0, length - 1, 5) << "th index";
    // cout << "\n " << get(arr, 3);
    // set(&arr,3,8);
    // display(arr);
    //  max,min,avg,sum can be calculated same
    // reversebyswap(&arr);
    // insertsort(&arr, 20);
    // display(arr);
    rearrange(&arr);
    display(arr);
    // merging two array
    arr3 = merge(&arr1, &arr2);
    display(*arr3);

    return 0;
}