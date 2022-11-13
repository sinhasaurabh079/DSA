#include<bits/stdc++.h>
using namespace std;

int main()
{
    char A[]="finding";
   /*
      // using Hash Table

    int H[26]={0};  // hash table
    int i;
    for(i=0;A[i]!='\0';i++)
      {
        H[A[i]-97]+=1;
      }
      for(i=0;i<26;i++)
        {
            if(H[i]>1)
             {
                cout<<char(i+97)<<" "<<H[i]<<endl;
             }
        }
    */ 
   /*
     Finding Duplicates Using Bitwise Operations
     1. left shift <<
     2. Bits Oring (Merging)
     3. Bits Anding (Masking)
   */  
    int H=0,x=0;    // 4 byte = 32bit max to store a-z(26 hash table element now in bits position)
                    // 31.....0 , jo character mila uss bit m 1 dal diya
    for(int i=0;A[i]!='\0';i++) 
      {
        x=1;              // assuming opern for a-z only
        x=x<<(A[i]-97);  // diff pta kr rhe h present character a se kitna bda h
         if((x&H)>0)
           cout<<A[i]<<" is duplicate"<<endl;
        else 
           H=x|H;   
      }
   return 0;

}