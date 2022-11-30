#include <iostream>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            mp[temp]++;
        }

        int count = 0;
        for (auto it : mp)
        {
            if (it.second == 3) // as 3 is the lucky number
                count++;
        }

        if (count == 1)
            cout << "Lucky Day" << endl;
        else
            cout << "Not Lucky" << endl;
    }
    return 0;
}
