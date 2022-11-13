/* -----------------------------------Tower of Hanoi-----------------------------------
  Initially there are N no of disc present in tower A in from smaller at the top to bigger at the bottom
  (Disc size is in decreasing fom top to bottom or increasing from bottom to top).

In this there are three towers : A - tower at which the whole disc is present at first
                                 B - an auxilary tower i.e. used to move disc from tower A to C
                                 C - last tower at which the disc has to be finally placed 
                                     in the same manner as present in tower A

                       Aim : The aim of this game is to move all the disc from tower A to C with the help of
                              auxilary tower B 

         Rules : * Only one disc can be move at a time from one tower to another.
                 * Larger disc cannot be placed on a smaller disc at any time
                                                    
       NOTE : For N no of disc ---> No. of Operation (in nested recursion) = 2^(N+1) - 1
                               ---> No. of moves (between towers) = 2^N - 1 
                    
         Coded By : Saurabh Sinha   github user id : sinhasaurabh3104
*/

#include<bits/stdc++.h>  // single header file that includes all header file
using namespace std;

   /* Nested Recursion Concept is used to solve this problem*/
void toh(int n ,char a,char b, char c)  // n=no of disc and a,b,c are the name of the towers
{
    if(n>0)                
    {
        toh(n-1,a,c,b);    // toh short form of TowerOfHanoi
        cout<<" Move Disc "<<n<<" From Tower "<<a<<" to "<<c<<endl;
        toh(n-1,b,a,c);
    }

}
int main()
{    
    int no_of_disc;
    cin>>no_of_disc;
    toh(no_of_disc,'A','B','C'); // A,B,C are the towers names
    return 0;
}
