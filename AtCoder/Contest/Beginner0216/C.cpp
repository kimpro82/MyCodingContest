// AtCoder Beginner Contest 216
// 2021-08-29(Sun) 21:00 - 22:40, 100 minutes

// C - Many Balls

/* Sample Input & Output
5
AABA

14
BBABBAAAB
*/


#include <iostream>

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    // Find minimum a of n < 2^a
    int divisor = 2, x = n, a = 0;
    while (x > 0)
    {
        x /= 2;
        a++;
    }
    // test
    cout << a << endl;

    return 0;
}