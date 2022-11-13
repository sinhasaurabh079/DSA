#include <iostream>
using namespace std;


// C Implementaton
struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    cout << "\nElements are:";
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}
void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int delete_element(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index <= arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int linear_search(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++) // -> is used instead of . operatr because *arr is a pointer, (->) used to access via pointer
    {                                     // . operator is used to access data members n methods by objects
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]); // to improve linear search by transportation for repeative key element
            return i;
        }
    }
    return -1;
}
int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0, h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int rec_binary_search(int a[], int l, int h, int key)
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

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}
int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (max < arr.A[i])
            max = arr.A[i];
    }
    return max;
}
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (min > arr.A[i])
            min = arr.A[i];
    }
    return min;
}
int sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}
float avg(struct Array arr)
{
    return (float)sum(arr) / arr.length;
}

void reverse(struct Array *arr)
{
    int *B;
    B = new int[arr->length];
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}
void reversebyswap(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void insertsort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i]; // shifting to create gap for insertion
        i--;
    }
    arr->A[i + 1] = x; // jb shi jaga pr pahoch jao tb
    arr->length++;
}
int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0) // for -ve number
            i++;
        while (arr->A[j] >= 0) // for +ve number
            j--;
        if (i < j) // for rearrange
            swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = new Array;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    // for remaining elements if any
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i++];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}
int main()
{
    struct Array arr = {{2, 3, -1, 4, 5, -4, 6}, 10, 7};
    struct Array arr1 = {{1, 3, 5, 7}, 10, 4};
    struct Array arr2 = {{2, 4, 6, 8}, 10, 4};
    struct Array *arr3;
    // append(&arr, 10);
    // display(arr);
    // insert(&arr, 5, 10);
    // display(arr);
    // cout << "\n Deleted element:" << delete_element(&arr, 4);
    // cout << "\n By linear search: Element found at " << linear_search(&arr, 5) << "th index.";
    // cout << "\n By binary search: Element found at " << BinarySearch(arr, 5) << "th index";
    // cout << "\n By recursive binary search: Element found at " << rec_binary_search(arr.A, 0, arr.length - 1, 5) << "th index";
    // cout << "\n " << get(arr, 3);
    // set(&arr,3,8);
    // display(arr);
    //  max,min,avg,sum can be calculated same
    // reversebyswap(&arr);
    // insertsort(&arr, 20);
    // display(arr);
    rearrange(&arr);
    display(arr);
     //merging two array
     arr3=merge(&arr1,&arr2);
     display(*arr3);

    return 0;
}