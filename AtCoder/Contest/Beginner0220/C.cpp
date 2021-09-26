// AtCoder Beginner Contest 220
// 2021-09-26(Sun) 21:00 - 22:40, 100 minutes

// C - Long Sequence

/* Sample Input & Output
3
3 5 2
26

8

4
12 34 56 78
1000

23
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Input data
    int N, a= 0;
    cin >> N;
    vector<int> A;
    ll aSum = 0;
    for (int n = 0; n < N; n++)
    {
        cin >> a;
        aSum += a;
        A.push_back(a);
    }
    ll X;
    cin >> X;

    // Operate
    ll ans = (X / aSum) * N;
    ll res = X % aSum;
    for (int n = 0; n < N; n++)
    {
        if (res < 0) break;
        else
        {
            res -= A[n];
            ans++;
        }
    }

    // Output
    cout << ans << endl;

    return 0;
}