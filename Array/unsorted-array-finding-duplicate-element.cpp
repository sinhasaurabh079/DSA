#include <iostream>
using namespace std;

int main()
{
   int a[]={8,3,6,4,5,6,8,2,7};  // unsorted array
   int n= sizeof(a)/sizeof(a[0]);
   for(int i=0;i<n-1;i++)
   {
      int count =1;
      if(a[i]!=-1)
      {
         for(int j=i+1;j<n;j++)
         {
            if(a[i]==a[j])
            {
               count++;
               a[j]=-1;
            }
         }
         if(count>1)
         cout<<a[i]<< " appears "<<count<<" times.\n";
      }
   }
return 0;
}