#include <iostream>
using namespace std;

int main()
{
    char A[] = "Python";
    char t;
    int i, j;
    // char B[7];
    // naive approach
    // pehle A[] k last tk pahuch gye phir A[] ka last B[] k first m dal diya

    // for(i=0;A[i]!='\0';i++);
    //   i=i-1;
    // for(j=0;i>=0;i--,j++)
    //   {
    //     B[j]=A[i];
    //   }
    //   B[j]='\0';
    //   cout<<B;
    /*
       ** swapping fist and last, nd and 2nd last and so on
           IN A SINGLE ARRAY
    */
    for (j = 0; A[j] != '\0'; j++)
        ;
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout << A<<endl;
}