#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, p, x, y;
        cin >> m >> p >> x >> y;

        int total = 165;
    // if he reaches before 8pm, then he doesn't need hotel as hostel gate is open
        if ((total - (x + y)) >= 0)
        {
            cout << "Masti" << endl;
            cout << total - (x + y) << " " << m << endl;
            continue;
        }
     // if he reaches before 9pm, time is 165+60 ==225 and remaining money after payinf hotel rent is m-p
        total += 60;
        if ((total - (x + y)) >= 0 && m >= p)
        {
            cout << "Masti" << endl;
            cout << total - (x + y) << " " << m - p << endl;
            continue;
        }

        cout << "Sad Life" << endl;
    }
    return 0;
}
