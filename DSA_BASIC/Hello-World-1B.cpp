#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int lastDigit = n % 10;       // jo bhi no hoga uska lastDigit ka hi difference hoga, n ko multiple bnane k liye
        int another = 10 - lastDigit; // for lastDigit > 5

        int m = min(lastDigit, another);

        for (int i = 0; i < m; i++)
        {
            cout << "Hello World !\n";
        }
    }
    return 0;
}