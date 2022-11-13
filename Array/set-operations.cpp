#include <iostream>
using namespace std;

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

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = new Array;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) // set b element is greater
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j]) // set a element greater
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++]; // if elements are same
            j++;
        }
    }
    // for remaining elements if any
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i++];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = new Array;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) // set b element is greater
            i++;
        else if (arr1->A[i] > arr2->A[j]) // set a element greater
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++]; // if elements are same
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = new Array;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) // set b element is greater
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j]) // set a element greater
            j++;
        else
        {
            i++;
            j++;
        }
    }
    // for remaining elements if any
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i++];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main()
{

    struct Array arr1 = {{1, 3, 5, 7}, 10, 4};
    struct Array arr2 = {{2, 3, 5, 8}, 10, 4};
    struct Array *arr3;

    arr3 = Union(&arr1, &arr2);
    cout << "\nUnion";
    display(*arr3);
    arr3 = Intersection(&arr1, &arr2);
    cout << "\nIntersecton";
    display(*arr3);
    arr3 = Difference(&arr1, &arr2);
    cout << "\nDiffernce:";
    display(*arr3);

    return 0;
}