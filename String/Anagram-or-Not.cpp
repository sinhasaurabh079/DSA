#include <bits/stdc++.h>
using namespace std;

/*
  ** Anagram mtlb do distinct string jinke characters same
     ex - Decimal and Medical
     An anagram of a string is another string that contains the same characters,
    only the order of characters can be different.
     For example, “abcd” and “dabc” are an anagram of each other.

     Approach --> ek hash table na li pehle string ko scan krke, H[A[i]]=1 kiya 
                  jb dusre string scan krenge tb uss particular H[A[i]]= -1 dalenge
                  
*/
int main()
{
    char A[] = "decimal";
    //char B[] = "medical";
    char B[20];
    cin>>B;
    int i, H[26] = {0};
    for (i = 0; A[i] != '\0'; i++)
        H[A[i] - 97] += 1;
    for (i = 0; B[i] != '\0'; i++)
    {
        H[A[i] - 97] -= 1;
        if (H[A[i] - 97] < 0)
        {
            cout << "Not Anagram\n";
            break;
        }
    }
    if(B[i]=='\0')
      cout<<"It's Anagram\n";

    return 0;  
}