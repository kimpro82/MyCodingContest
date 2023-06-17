// AtCoder Beginner Contest 215
// 2021-08-21(Sat) 21:00 - 22:40, 100 minutes

// B - log2(N)

/* Sample Input & Output
6
2

1
0

1000000000000000000
59
*/


#include <iostream>

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;

    int k = 0;
    while (true)
    {
        if (N <= 1) break;
        N /= 2;
        k++;
    }

    cout << k << endl;

    return 0;
}