#include <iostream>
using namespace std;

string modify(string s)
{
    int i = 0;
    int j = s.length();

    while (i < j)
    {
        while (i < j && s[i] != 'n' && s[i] != 'o' && s[i] != 'i' && s[i] != 'd' && s[i] != 'a')
        {
            i++; // tracerse krte rehe
        }
        while (i < j && s[j] != 'n' && s[j] != 'o' && s[j] != 'i' && s[j] != 'd' && s[j] != 'a')
        {
            j--;
        }
        if (i < j)
        {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
        }
        i++;
        j--;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        cout<<modify(str)<<endl;
    }
    return 0;
}