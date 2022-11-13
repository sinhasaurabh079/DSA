#include<bits/stdc++.h>
using namespace std;

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";
    // if (A.length() != B.length())
    //     exit (0);
    int i, j;
    // for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    // {
    //     if (A[i] != B[j])
    //         break;
    // }
    // if (A[i] == B[j])
    //     cout << "Equal\n";
    // else if (A[i] < B[j])
    //     cout << "A is Smaller String\n";
    // else
    //     cout << "B is Smaller String\n";

    /*
      Using strcmp function
    */
   if(strcmp(A,B)==0)
     cout<<"Equal\n";
    if(strcmp(A,B)>0) 
    cout<<"A is greater\n";
   else 
    cout<<"B is greater\n";
    return 0;
}