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

#define endl '\n'

using namespace std;

int main()
{
    float a;
    cin >> a;

    int x = (int) a;
    int y = (a - x) * 10;

    // test
    // cout << a << ' ' << x << ' ' << y << endl;

    cout << x;
    if (y < 2.5) cout << '-';
    else if (y > 6.5) cout << '+';
    cout << endl;

    return 0;
}