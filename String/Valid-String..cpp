#include<bits/stdc++.h>
using namespace std;

int valid(char* name)
{
    int i;
    for(i=0;name[i]!='\0';i++)
    {
        if(!(name[i]>=65 && name[i]<=90)&& !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
            // agr koi bhi character ---> capital, small case ya number na ho toh wo special character hoga and valid string nhi hoga
          return 0;
    }
    return 1;
}

int main()
{
  // char name[] ="Ani?321";
    string data = "Ani?321";
    char* name = new char [data.length()+1];
    strcpy (name, data.c_str());
     int yes;
     yes=valid(name);
     if(yes==1)
       cout<<"Yes, It is a valid String.\n";
     else 
        cout<<"No!\n";

     return 0;      
}