// AtCoder Beginner Contest 214
// 2021-08-14(Sat) 21:00 - 22:40, 100 minutes

// A - New Generation ABC

/* Sample Input & Output
214
8

1
4

126
6
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int N, ans;
    cin >> N;

    if (N <= 125) ans = 4;
    else if (N <= 211) ans = 6;
    else ans = 8;

    cout << ans << endl;

    return 0;
}