// AtCoder Beginner Contest 216
// 2021-08-29(Sun) 21:00 - 22:40, 100 minutes

// A - Signed Difficulty

/* Sample Input & Output
15.8
15+

1.0
1-

12.5
12
*/


#include <iostream>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    string a;
    cin >> a;

    string x, y;
    bool fraction = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
        {
            fraction = true;
            continue;
        }

        if (fraction == false) x.push_back(a[i]);
        else y.push_back(a[i]);
    }

    // test : ok
    // cout << a << ' ' << x << ' ' << y << endl;

    cout << x;
    if (stoi(y) <= 2) cout << '-';
    else if (stoi(y) >= 7) cout << '+';
    cout << endl;

    return 0;
}